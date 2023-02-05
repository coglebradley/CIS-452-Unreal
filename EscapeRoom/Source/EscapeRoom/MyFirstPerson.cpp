// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstPerson.h"

// Sets default values
AMyFirstPerson::AMyFirstPerson()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFirstPerson::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstPerson::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyFirstPerson::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyFirstPerson::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyFirstPerson::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyFirstPerson::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("Lookup"), this, &AMyFirstPerson::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMyFirstPerson::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AMyFirstPerson::StopJumping);

}

