// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/QuestGameMode.h"
#include "Quest/QuestManager.h"
#include "Core/QuestManagement.h"

void AQuestGameMode::BeginPlay()
{
	Super::BeginPlay();
	//UQuestManagement* GetQuestManagement = GetGameInstance()->GetSubsystem<UQuestManagement>();
	//if (GetQuestManagement) {
	//	GetQuestManagement->SetQuestDT(QuestDT);
	//}
}

void AQuestGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

AQuestManager* AQuestGameMode::GetQuestInstance()
{
	return QuestInstance;
}
