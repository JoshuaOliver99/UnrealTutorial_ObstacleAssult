// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	// Logging...
	FString name = GetName();
	UE_LOG(LogTemp, Display, TEXT("---------- This is a demo log displaying a float! %f"), MoveDistance);
	UE_LOG(LogTemp, Display, TEXT("---------- This is a demo log displaying a string! %s"), *name); // Note this needs a "*" because of FString conversion
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{


	// ----- Send platform back if gone too far...
	if (ShouldPlatformRotate())
	{
		// Reverse direction of motion if gone too far
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	// ----- Move platform forward...
	else
	{
		// Get current lcoation
		FVector CurrentLocation = GetActorLocation();
		// Add vector to that location
		CurrentLocation += PlatformVelocity * DeltaTime;
		// Set the location
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelecity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformRotate() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Distance(StartLocation, GetActorLocation());
}

