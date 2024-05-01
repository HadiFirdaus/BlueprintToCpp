// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/QuestManagement.h"
#include "Engine/DataTable.h"

UDataTable* UQuestManagement::Quest_DT = nullptr;

UQuestManagement::UQuestManagement()
{
	//DataTable'/Game/Quests/Quest_DT.Quest_DT' copy ref
	static ConstructorHelpers::FObjectFinder<UDataTable> Quest_DTFinder(TEXT("DataTable'/Game/Quests/Quest_DT.Quest_DT'"));
	if (Quest_DTFinder.Succeeded()) {
		Quest_DT = Quest_DTFinder.Object;
		UE_LOG(LogTemp, Warning, TEXT("DT loaded"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Failed to load DT"));
	}
}

void UQuestManagement::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UQuestManagement::Deinitialize() {

}

UDataTable* UQuestManagement::GetQuestDT() const{
	return Quest_DT;
}

void UQuestManagement::SetQuestDT(UDataTable* QQuest_DT) {
	Quest_DT = QQuest_DT;
}

void UQuestManagement::CompleteQuest_Implementation(FName QuestId, bool CompleteWholeQuest)
{
	int32 QuestIndex = GetQuestIndex(QuestId);
	FQuestInfo Quest = QuestList[QuestIndex];
	if (CompleteWholeQuest) {
		QuestList[QuestIndex].Progress = Quest.ProgressTotal;
	}
	else
	{
		QuestList[QuestIndex].Progress = FMath::Min(Quest.Progress + 1, Quest.ProgressTotal);	//IncrementProgress
	}
	CompletedQuest.Broadcast(QuestIndex);	//Call CompletedQuest()
}

FQuestInfo UQuestManagement::GetQuest(FName Name) const
{
	return QuestList[GetQuestIndex(Name)];
}
