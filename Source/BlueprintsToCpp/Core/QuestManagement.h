// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Quest/QuestData.h"
#include "QuestManagement.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompletedQuestSignatureTEMP, int32, Index);

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API UQuestManagement : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UQuestManagement();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//<TEST>
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CompleteQuest(FName QuestId, bool CompleteWholeQuest);

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCompletedQuestSignatureTEMP CompletedQuest;
	//Initialize the quest
	UFUNCTION(BlueprintCallable, Category="QuestManagement++")
	class UDataTable* GetQuestDT() const;

	UFUNCTION(BlueprintCallable, Category="QuestManagement++")
	void SetQuestDT(class UDataTable* QQuest_DT);

	UFUNCTION(BlueprintCallable, Category="QuestManagement++")
	bool IsOneQuestComplete(FQuestData QuestData);
	UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	int32 GetQuestIndexFromName(FName QuestId);
	UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	bool IsOneActiveIndex(int32 Index);
private:
	static class UDataTable* Quest_DT;
	//<TEST/>

public:
	UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	void Temporary(FName RowName);
	//UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	FQuestData* GetCurrentQuest(FName RowName);
	//UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	FName GetQuestId(FQuestData* CurrentQuest);
/*	UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	int32 GetCurrentProgress(FQuestData& CurrentQuest);
	UFUNCTION(BlueprintCallable, Category = "QuestManagement++")
	int32 GetCurrentTotalProgress(FQuestData& CurrentQuest);*/
private:

};
