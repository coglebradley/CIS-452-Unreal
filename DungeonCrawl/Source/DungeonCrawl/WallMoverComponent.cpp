// Fill out your copyright notice in the Description page of Project Settings.


#include "WallMoverComponent.h"
#include "Math/UnrealmathUtility.h"

// Sets default values for this component's properties
UWallMoverComponent::UWallMoverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWallMoverComponent::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetOwner()->GetActorLocation();

	// ...
	
}


// Called every frame
void UWallMoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (MoveTriggered)
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		FVector TargetLocation = StartingLocation + MoveOffset;
		float Speed = FVector::Distance(StartingLocation, TargetLocation) / MoveTime;
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
		GetOwner()->SetActorLocation(NewLocation);
	}
	
	// ...
}

void UWallMoverComponent::SetMoveTriggered(bool NewMoveTriggered)
{
	MoveTriggered = NewMoveTriggered;
}

