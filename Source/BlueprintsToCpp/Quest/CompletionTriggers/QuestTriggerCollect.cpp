// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest/CompletionTriggers/QuestTriggerCollect.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AQuestTriggerCollect::AQuestTriggerCollect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SceneRoot;
}

// Called when the game starts or when spawned
void AQuestTriggerCollect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestTriggerCollect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AQuestTriggerCollect::IsCorrectItem(class AActor* Item)
{
	return Item->ActorHasTag(ItemTag);
}
