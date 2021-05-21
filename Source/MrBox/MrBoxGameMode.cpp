// Copyright Epic Games, Inc. All Rights Reserved.

#include "MrBoxGameMode.h"
#include "MrBoxCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMrBoxGameMode::AMrBoxGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
