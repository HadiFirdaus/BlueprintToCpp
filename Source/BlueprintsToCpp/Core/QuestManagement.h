// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Quest/QuestInfo.h"
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

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CompleteQuest(FName QuestId, bool CompleteWholeQuest);

	UFUNCTION(BlueprintPure)
	FQuestInfo GetQuest(FName Name) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	bool IsActiveQuest(FName QuestId) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	void IsActiveIndex(int32 Index, bool& Active) const;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCompletedQuestSignatureTEMP CompletedQuest;

	UFUNCTION(BlueprintCallable, Category="QuestManagement++")
	class UDataTable* GetQuestDT() const;

	UFUNCTION(BlueprintCallable, Category="QuestManagement++")
	void SetQuestDT(class UDataTable* QQuest_DT);


protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	TArray<FQuestInfo> QuestList;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	int32 GetQuestIndex(FName QuestId) const;

private:
	static class UDataTable* Quest_DT;
	
};
