// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "DodgeballProjectile2.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SightSource = CreateDefaultSubobject<USceneComponent>(TEXT("Sight Source"));
	SightSource->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Fetch the character currently being controlled by the player
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	// Look at the player character every frame
	bCanSeePlayer = LookAtActor(PlayerCharacter);

	if (bCanSeePlayer != bPreviousCanSeePlayer)
	{
		if (bCanSeePlayer)
		{
			//Start throwing dodgeballs
			GetWorldTimerManager().SetTimer(ThrowTimerHandle,
				this,
				&AEnemyCharacter::ThrowDodgeball,
				ThrowingInterval,
				true,
				ThrowingDelay);
		}
		else
		{
			//Stop throwing dodgeballs
			GetWorldTimerManager().ClearTimer(ThrowTimerHandle);
		}
	}

	bPreviousCanSeePlayer = bCanSeePlayer;

}

bool AEnemyCharacter::LookAtActor(AActor* TargetActor)
{
	if (TargetActor == nullptr) return false;

	if (CanSeeActor(TargetActor))
	{
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();
		// Calculate the necessary rotation for the Start point to face the End point
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

		//Set the enemy's rotation to that rotation
		SetActorRotation(LookAtRotation);
		return true;
	}

	return false;
}

bool AEnemyCharacter::CanSeeActor(AActor* TargetActor)
{
	if (TargetActor == nullptr) return false;

	// Store the results of the Line Trace
	FHitResult Hit;

	// Where the Line Trace starts and ends
	FVector Start = SightSource->GetComponentLocation();
	FVector End = TargetActor->GetActorLocation();

	// The trace channel we want to compare against
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	FCollisionQueryParams QueryParams;
	// Ignore the actor that's executing this Line Trace
	QueryParams.AddIgnoredActor(this);
	// And the target we're checking for
	QueryParams.AddIgnoredActor(TargetActor);

	// Execute the Line Trace
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// Show the Line Trace inside the game
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}
// Called to bind functionality to input
//void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}
void AEnemyCharacter::ThrowDodgeball()
{
	if (DodgeballClass == nullptr)
	{
		return;
	}

	FVector ForwardVector = GetActorForwardVector();
	float SpawnDistance = 40.f;
	FVector SpawnLocation = GetActorLocation() + (ForwardVector * SpawnDistance);
	//Spawn new dodgeball
	GetWorld()->SpawnActor<ADodgeballProjectile2>(DodgeballClass, SpawnLocation, GetActorRotation());
}

