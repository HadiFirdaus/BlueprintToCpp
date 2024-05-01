// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/QuestManagement.h"

int32 UQuestManagement::SomeNumStatic = 0;

int32 UQuestManagement::GetSomeNum() {
	return SomeNumStatic;
}

void UQuestManagement::SetSomeNum()
{
	SomeNumStatic++;
}