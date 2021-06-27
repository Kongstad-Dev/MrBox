// Fill out your copyright notice in the Description page of Project Settings.


#include "MrBox/CoffeeLevel/CoffeeLevelGameModeBase.h"

void ACoffeeLevelGameModeBase::ActorDied(AActor* DeadActor)
{
	if (DeadActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Dead"))
	}
	
}