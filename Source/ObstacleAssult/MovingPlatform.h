// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float MoveDistance = 10;

	UPROPERTY(EditAnywhere, Category = "Rotating Platform")
	FRotator RotationVelecity;
	//UPROPERTY(EditAnywhere, Category = "Rotating Platform")
	//float RotateSpeed = 10;

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	// Note: const ensures this changes no data.
	// Note: const can only call const functions.
	bool ShouldPlatformRotate() const;
	float GetDistanceMoved() const;

};
