// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.h"
#include "QuestMarker.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestMarker();

	UFUNCTION(BlueprintCallable)
	void RefreshVisibility();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	AQuestManager* GetQuestManager() const;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class USceneComponent* SceneRoot;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	class UParticleSystemComponent* ParticleSystemOne;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName QuestName;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 ShowAtProgress = 0;

private:
	UFUNCTION()
	void QuestUpdated(int32 Index);
};
