// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestManagement.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API UQuestManagement : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="QuestManagement++")
	static int32 GetSomeNum();

	UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	void SetSomeNum();

private:
	static int32 SomeNumStatic;
	
};
