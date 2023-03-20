// Fill out your copyright notice in the Description page of Project Settings.


#include "DodgeballProjectile2.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "TopDownCharacter.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ADodgeballProjectile2::ADodgeballProjectile2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereComponent->SetSphereRadius(35.f);
	SphereComponent->SetCollisionProfileName(FName("Dodgeball"));
	SphereComponent->SetSimulatePhysics(true);

	SphereComponent->SetNotifyRigidBodyCollision(true);

	SphereComponent->OnComponentHit.AddDynamic(this, &ADodgeballProjectile2::OnHit);

	RootComponent = SphereComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = 1500.f;
}

void ADodgeballProjectile2::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (BounceSound != nullptr && NormalImpulse.Size() > 1000.0f)
	{
		UGameplayStatics::PlaySoundAtLocation(this, BounceSound, GetActorLocation(), 1.0f, FMath::RandRange(0.7f, 1.3f), 0.0f,BounceSoundAttenuation);
	}
	ATopDownCharacter* Player = Cast < ATopDownCharacter>(OtherActor);
	if (Player != nullptr)
	{

	}
	if (HitParticles != nullptr)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), HitParticles, GetActorTransform());
	}
	Destroy();
}

// Called when the game starts or when spawned
void ADodgeballProjectile2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADodgeballProjectile2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

