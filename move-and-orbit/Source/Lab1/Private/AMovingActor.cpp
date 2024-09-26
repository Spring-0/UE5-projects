// Fill out your copyright notice in the Description page of Project Settings.


#include "AMovingActor.h"

// Sets default values
AAMovingActor::AAMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMovingActor::BeginPlay()
{
	Super::BeginPlay();
	MoveToNextPoint();

}

// Called every frame
void AAMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FirstPoint == nullptr || SecondPoint == nullptr) return;

	if (CurrentPoint != nullptr) {
		FVector Displacement = GetActorLocation() - CurrentPoint->GetActorLocation();
		
		if (Displacement.Size() < 100) MoveToNextPoint();

		FVector Direction = Displacement.GetSafeNormal();
		FRotator NewLookAt = FRotationMatrix::MakeFromX(Direction).Rotator();

		NewLookAt.Pitch = 0.0f;
		NewLookAt.Roll = 0.0f;
		NewLookAt.Yaw -= 180.0f;

		FRotator LerpedRotation = FMath::Lerp(GetActorRotation(), NewLookAt, DeltaTime);
		SetActorRotation(LerpedRotation);

		FVector LerpedLocation = FMath::Lerp(GetActorLocation(), CurrentPoint->GetActorLocation(), DeltaTime);
		SetActorLocation(LerpedLocation);

	}

}

void AAMovingActor::MoveToNextPoint()
{
	if (CurrentPoint == nullptr || CurrentPoint == SecondPoint) CurrentPoint = FirstPoint;
	else { CurrentPoint = SecondPoint; }
}

