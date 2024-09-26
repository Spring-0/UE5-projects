// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABaseActor.h"
#include "AMovingActor.generated.h"

UCLASS()
class LAB1_API AAMovingActor : public AABaseActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditInstanceOnly, Category="Movement Point")
	AActor* FirstPoint;

	UPROPERTY(EditInstanceOnly, Category="Movement Point")
	AActor* SecondPoint;

private:
	AActor* CurrentPoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AAMovingActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void MoveToNextPoint();
};
