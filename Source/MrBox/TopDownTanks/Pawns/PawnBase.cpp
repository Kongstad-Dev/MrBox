// Fill out your copyright notice in the Description page of Project Settings.


#include "MrBox/TopDownTanks/Pawns/PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "MrBox/TopDownTanks/ProjectileBase.h"
#include "MrBox/TopDownTanks/Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
APawnsBase::APawnsBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));

	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void APawnsBase::RotateTurret(FVector LookAtTarget)
{
	//Update turretMesh Rotation to face the LookAtTarget Passed in from child

	FVector LookAtTargetClean = FVector(FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z));
	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRoatation = FVector(LookAtTargetClean - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRoatation);

}
void APawnsBase::Fire()
{
	// Get ProjectileSpawnPoint Location && Rotation -> Spawn Projectile class at Location towards Rotation.

	if (ProjectileClass)
	{
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();

		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(this);
	}
}

void APawnsBase::HandleDestruction()
{
	//Univeral functionallity
	//Death effect particle, sound and camera shake

	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation());

	//The child overrides
	//PawnTurret - Inform Gamemode that turret is dead -> Then Destroy turret actor (self)
	UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	//PawnTank inform player is dead -> Then hide() all components && stop movement input from player.
	GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(DeathShake);
}


