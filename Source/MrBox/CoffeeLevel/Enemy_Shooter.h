// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy_Shooter.generated.h"


class AMrBoxCharacter;

UCLASS()
class MRBOX_API AEnemy_Shooter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy_Shooter();




private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatAI", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatAI", meta = (AllowPrivateAccess = "true"))
		float FireRange = 500.f;


	AMrBoxCharacter* PlayerPawn;
	FTimerHandle FireRateTimerHandle;

	void CheckFireCondition();

	float ReturnDistanceToPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
