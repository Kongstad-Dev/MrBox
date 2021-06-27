

// Fill out your copyright notice in the Description page of Project Settings.



#include "MrBox/MrBoxCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MrBox/CoffeeLevel/Enemy_Shooter.h"


// Sets default values
AEnemy_Shooter::AEnemy_Shooter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy_Shooter::BeginPlay()
{
	Super::BeginPlay();
	//GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &AMrBoxCharacter::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<AMrBoxCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

}




// Called every frame
void AEnemy_Shooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}
	//RotateTurret(PlayerPawn->GetActorLocation());
}



void AEnemy_Shooter::CheckFireCondition()
{

	// if Player == null || Is Dead Then bail!
	{
		//if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
		

	}
	// If Player IS in range then fire!
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		//fire
		//Fire();
	}
	
}

float AEnemy_Shooter::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return 0.f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());

}

// Called to bind functionality to input
void AEnemy_Shooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

