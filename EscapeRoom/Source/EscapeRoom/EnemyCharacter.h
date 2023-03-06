// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class ESCAPEROOM_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SightSource;

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool LookAtActor(AActor* TargetActor);

	bool CanSeeActor(AActor* TargetActor);

	void ThrowDodgeball();

	bool bCanSeePlayer = false;

	bool bPreviousCanSeePlayer = false;

	FTimerHandle ThrowTimerHandle;

	float ThrowingInterval = 2.f;
	float ThrowingDelay = 0.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Dodgeball)
	TSubclassOf<class ADodgeballProjectile2> DodgeballClass;

};
