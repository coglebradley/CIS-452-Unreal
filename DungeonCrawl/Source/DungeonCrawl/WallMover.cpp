// Fill out your copyright notice in the Description page of Project Settings.


#include "WallMover.h"
#include "Math/UnrealmathUtility.h"

// Sets default values
AWallMover::AWallMover()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallMover::BeginPlay()
{
	Super::BeginPlay();
	StartingLocation = GetOwner()->GetActorLocation();
	
}

// Called every frame
void AWallMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector TargetLocation = StartingLocation + MoveOffset;
	float Speed = FVector::Distance(StartingLocation, TargetLocation) / MoveTime;
	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	GetOwner()->SetActorLocation(NewLocation);
}

