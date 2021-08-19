// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MrBox/TopDownTanks/Pawns/PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;
UCLASS()
class MRBOX_API APawnTurret : public APawnsBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatAI", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CombatAI", meta = (AllowPrivateAccess = "true"))
		float FireRange = 500.f;

	APawnTank* PlayerPawn;
	FTimerHandle FireRateTimerHandle;
	void CheckFireCondition();

	float ReturnDistanceToPlayer();



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};

