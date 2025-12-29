// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "QuestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API AQuestGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintPure, Category = "QGameMode++")
	class AQuestManager* GetQuestInstance();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "QGameMode++")
	class UDataTable* QuestDT;

private:
	UPROPERTY()
	class AQuestManager* QuestInstance;
};
