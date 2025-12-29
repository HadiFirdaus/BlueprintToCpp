// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	ParticleSystemOne = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemOne"));
	ParticleSystemOne->SetupAttachment(SceneRoot);
}

void AQuestMarker::BeginPlay()
{
	Super::BeginPlay();
	GetQuestManager()->CompletedQuest.AddDynamic(this, &AQuestMarker::QuestUpdated);	//Bind Event to CompletedQuest() with QuestUpdated() Event
	RefreshVisibility();
}

void AQuestMarker::RefreshVisibility()
{
	FQuestInfo Quest = GetQuestManager()->GetQuest(QuestName);
	bool Visibility = GetQuestManager()->IsActiveQuest(QuestName) && Quest.Progress==ShowAtProgress;
	ParticleSystemOne->SetVisibility(Visibility);
}

void AQuestMarker::QuestUpdated(int32 Index)
{
	RefreshVisibility();
}
