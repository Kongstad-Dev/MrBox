// copyright Kristoffer Petersen 2020

#pragma once

#include "Engine/TriggerVolume.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MRBOX_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	void FindAudioComponent();
	void IsPressurePlateSetOnActor();
	float TotalMassOfActors() const;

private:



	float InitialPosY;
	float CurrentPosY;

	float InitialPosX;
	float CurrentPosX;

	float DoorLastOpen = 0.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;


	UPROPERTY(EditAnywhere)
		float OpenDoorSpeed = 2.f;

	UPROPERTY(EditAnywhere)
		float CloseDoorSpeed = 2.f;

	//UPROPERTY(EditAnywhere)
	//float TargetYaw = 90.0f;

	UPROPERTY(EditAnywhere)
		float TargetPositionY = 0;

	UPROPERTY(EditAnywhere)
		float TargetPositionX = 0;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float MassToOpenDoors = 50.f;

	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;

	//Tracking sound played on doors.
	bool OpenDoorSound = false;
	bool CloseDoorSound = true;


	UPROPERTY(EditAnywhere)
		float Random;
};

