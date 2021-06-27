// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CoffeeLevelGameModeBase.generated.h"


UCLASS()
class MRBOX_API ACoffeeLevelGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public: 
	void ActorDied(AActor* DeadActor);
};
