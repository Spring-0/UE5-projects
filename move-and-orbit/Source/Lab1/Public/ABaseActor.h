// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABaseActor.generated.h"

UCLASS(Abstract, Blueprintable)
class LAB1_API AABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Root Component");
	UStaticMeshComponent* Mesh;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Actor Visual")
	USceneComponent* RootTransformComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AABaseActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
