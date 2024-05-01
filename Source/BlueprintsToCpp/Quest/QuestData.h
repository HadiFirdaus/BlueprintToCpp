// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct BLUEPRINTSTOCPP_API FQuestData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName QuestId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Progress;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ProgressTotal;
};
