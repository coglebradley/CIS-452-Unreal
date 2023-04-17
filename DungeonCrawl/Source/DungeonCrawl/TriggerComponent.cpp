// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent = GetOwner()->FindComponentByClass<UBoxComponent>();

	if (WallToMove == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Wall to Move not set on Trigger Component!"));
		return;
	}

	WallMover = WallToMove->FindComponentByClass<UWallMoverComponent>();
	UE_LOG(LogTemp, Warning, TEXT("Wall Mover set in BeginPlay"));
	// ...
	
}


// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (BoxComponent == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("BoxComponent not set on Trigger Component!"));
		return;
	}
	if (WallToMove == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("WallMoverComponent not set on Trigger Component!"));
		return;
	}

	TArray<AActor*> Actors;
	BoxComponent->GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		FString ActorName = Actor->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("Tick: Overlapped actor's name: %s"), *ActorName);

		if (Actor->ActorHasTag("OpenDoor1"))
		{
			UE_LOG(LogTemp, Warning, TEXT("Unlocking!"));
			WallMover->SetMoveTriggered(true);
		}
	}
	// ...
}

