// copyright Kristoffer Petersen 2020
#include "OpenDoor.h"
#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"
#include "Math/Rotator.h"
#include "Math/TransformNonVectorized.h"
#include "GameFramework/Actor.h"


#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	/*InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;*/

	// Door goes Y when X is applied
	if (Random > 50)
	{
		InitialPosY = GetOwner()->GetActorLocation().Y;
		CurrentPosY = InitialPosY;
		TargetPositionY += InitialPosY;

	}
	if (Random < 50)
	{
		InitialPosX = GetOwner()->GetActorLocation().X;
		CurrentPosX = InitialPosX;
		TargetPositionX += InitialPosX;
	}

	IsPressurePlateSetOnActor();

	if (!AudioComponent) { return; }
	AudioComponent->Play();
}

void UOpenDoor::IsPressurePlateSetOnActor()
{
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT(" %s has the door component on it, but not the pressureplate set!"), *GetOwner()->GetName());
	}

}

void UOpenDoor::FindAudioComponent()
{
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();
	if (!AudioComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s missing Auido component"), *GetOwner()->GetName());
	}
}
// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TotalMassOfActors() > MassToOpenDoors)
	{
		OpenDoor(DeltaTime);
		DoorLastOpen = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if (GetWorld()->GetTimeSeconds() - DoorLastOpen >= DoorCloseDelay)
		{
			CloseDoor(DeltaTime);
		}
	}
	UE_LOG(LogTemp, Error, TEXT("Pos X: %s "), *GetOwner()->GetActorLocation().ToString());


}

void UOpenDoor::OpenDoor(float DeltaTime)
{



	if (Random > 50)
	{
		CurrentPosY = FMath::FInterpTo(CurrentPosY, TargetPositionY, DeltaTime, OpenDoorSpeed);
		FVector DoorPositionY = GetOwner()->GetActorLocation();
		DoorPositionY.Y = CurrentPosY;
		GetOwner()->SetActorLocation(DoorPositionY);
	}

	if (Random < 50)
	{
		CurrentPosX = FMath::FInterpTo(CurrentPosX, TargetPositionX, DeltaTime, OpenDoorSpeed);
		FVector DoorPositionX = GetOwner()->GetActorLocation();
		DoorPositionX.X = CurrentPosX;
		GetOwner()->SetActorLocation(DoorPositionX);

	}


	FindAudioComponent();
	CloseDoorSound = false;
	if (!AudioComponent) { return; }
	if (!OpenDoorSound)
	{

		AudioComponent->Play();
		OpenDoorSound = true;
	}

}

void UOpenDoor::CloseDoor(float DeltaTime)
{

	if (Random > 50)
	{
		CurrentPosY = FMath::FInterpTo(CurrentPosY, InitialPosY, DeltaTime, CloseDoorSpeed);
		FVector DoorPositionY = GetOwner()->GetActorLocation();
		DoorPositionY.Y = CurrentPosY;
		GetOwner()->SetActorLocation(DoorPositionY);
	}

	if (Random < 50)
	{
		CurrentPosX = FMath::FInterpTo(CurrentPosX, InitialPosX, DeltaTime, CloseDoorSpeed);
		FVector DoorPositionX = GetOwner()->GetActorLocation();
		DoorPositionX.X = CurrentPosX;
		GetOwner()->SetActorLocation(DoorPositionX);
	}

	FindAudioComponent();
	OpenDoorSound = false;
	if (!AudioComponent) { return; }
	if (!CloseDoorSound)
	{

		AudioComponent->Stop();
		CloseDoorSound = true;
	}

}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;
	// Find All Overlapping Actors.
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	// Add Up Their Masses.

	for (AActor* Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s is on the pressureplate!"), *Actor->GetName());
	}

	return TotalMass;
}