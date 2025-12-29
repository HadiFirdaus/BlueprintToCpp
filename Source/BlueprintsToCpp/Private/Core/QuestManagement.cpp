// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/QuestManagement.h"
#include "Engine/DataTable.h"
#include "Quest/QuestData.h"

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
	CompletedQuest.Broadcast(123);	//Call CompletedQuest()
}

bool UQuestManagement::IsOneQuestComplete(FQuestData QuestData)
{
	return QuestData.Progress == QuestData.ProgressTotal;
}

bool UQuestManagement::IsOneActiveIndex(int32 Index)
{
	return false;
}

int32 UQuestManagement::GetQuestIndexFromName(FName QuestId) {
	FQuestData* Item = Quest_DT->FindRow<FQuestData>(QuestId, "");
	return 0;
}

void UQuestManagement::Temporary(FName RowName) {
	GetQuestId(GetCurrentQuest(RowName));
}

FQuestData* UQuestManagement::GetCurrentQuest(FName RowName)
{
	FQuestData* currentQuest = Quest_DT->FindRow<FQuestData>(RowName, "");
	return currentQuest;
}

FName UQuestManagement::GetQuestId(FQuestData* CurrentQuest) {
	UE_LOG(LogTemp, Warning, TEXT("ID is: %s"), *CurrentQuest->QuestId.ToString());
	return CurrentQuest->QuestId;
}