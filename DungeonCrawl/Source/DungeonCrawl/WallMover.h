// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallMover.generated.h"

UCLASS()
class DUNGEONCRAWL_API AWallMover : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWallMover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	FVector MoveOffset = FVector(0, 0, 600);

	UPROPERTY(EditAnywhere)
	float MoveTime = 4;

	UPROPERTY(EditAnywhere)
	bool MoveTriggered = false;
	
	FVector StartingLocation;

};
