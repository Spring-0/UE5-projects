// Fill out your copyright notice in the Description page of Project Settings.


#include "AOrbitActor.h"

// Sets default values
AAOrbitActor::AAOrbitActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAOrbitActor::BeginPlay()
{
	Super::BeginPlay();
	Reset();

}

// Called every frame
void AAOrbitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RotateAroundActor != nullptr)
	{
		CurrentAngle += RotationSpeed * DeltaTime;
		if (CurrentAngle > 360) CurrentAngle -= 360;

		FVector NewLocation = RotateAroundActor->GetActorLocation() + RotationRadius.RotateAngleAxis(CurrentAngle, RotationAxis);
		FRotator NewRotation = FRotator(0.0f, CurrentAngle, 0.0f);

		SetActorLocationAndRotation(NewLocation, NewRotation);
		
	}

}

void AAOrbitActor::Reset()
{
	CurrentAngle = InitialRotationAngle;

	if (RotateAroundActor == nullptr) return;
	if (RotationRadius.IsZero()) RotationRadius = GetActorLocation() - RotateAroundActor->GetActorLocation();

}


