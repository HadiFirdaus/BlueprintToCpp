// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/QuestManagement.h"
#include "Quest/QuestInfo.h"

void UQuestManagement::CompleteQuest(FName QuestId, bool CompleteWholeQuest)
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
	//CompletedQuest.Broadcast(QuestIndex);	//Call CompletedQuest()
}

FQuestInfo UQuestManagement::GetQuest(FName Name) const
{
	return QuestList[GetQuestIndex(Name)];
}