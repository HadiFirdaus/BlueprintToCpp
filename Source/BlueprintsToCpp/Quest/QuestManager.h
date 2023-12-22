// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestInfo.h"
#include "QuestManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompletedQuestSignature, int32, Index);

UCLASS()
class BLUEPRINTSTOCPP_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CompleteQuest(FName QuestId, bool CompleteWholeQuest);

	UFUNCTION(BlueprintPure)
	FQuestInfo GetQuest(FName Name) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	bool IsActiveQuest(FName QuestId) const;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCompletedQuestSignature CompletedQuest;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "C++")
	TArray<FQuestInfo>	QuestList;
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	int32 GetQuestIndex(FName QuestId) const;

	UFUNCTION()
	void FunctionToTestGit();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
