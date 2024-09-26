// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABaseActor.h"
#include "AOrbitActor.generated.h"

UCLASS()
class LAB1_API AAOrbitActor : public AABaseActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotateAround")
	AActor* RotateAroundActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotateAround")
	float RotationSpeed = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotateAround")
	FVector RotationRadius = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotateAround")
	FVector RotationAxis = FVector::UpVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotateAround", meta=(ClampMin="0.0", ClampMax="360.0", UIMin="0.0", UIMax="360.0"))
	float InitialRotationAngle = 0.f;

protected:
	float CurrentAngle = 0.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AAOrbitActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Reset();

};
