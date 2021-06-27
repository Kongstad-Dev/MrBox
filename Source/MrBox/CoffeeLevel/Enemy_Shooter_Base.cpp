// Fill out your copyright notice in the Description page of Project Settings.


#include "MrBox/CoffeeLevel/Enemy_Shooter_Base.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "MrBox/CoffeeLevel/HealthComponent.h"
#include "MrBox/CoffeeLevel/projectile.h"


// Sets default values
AEnemy_Shooter_Base::AEnemy_Shooter_Base()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy_Shooter_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy_Shooter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy_Shooter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

