// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/QuestGameMode.h"
#include "Quest/QuestManager.h"

void AQuestGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AQuestGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

AQuestManager* AQuestGameMode::GetQuestInstance()
{
	return QuestInstance;
}
