// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestTriggerPickup.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLUEPRINTSTOCPP_API UQuestTriggerPickup : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestTriggerPickup();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QuestTriggerPickup++")
	FName QuestID;
		
};
