// Fill out your copyright notice in the Description page of Project Settings.


#include "ABaseActor.h"

// Sets default values
AABaseActor::AABaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootTransformComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootTransformComponent"));
	RootComponent = RootTransformComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AABaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

