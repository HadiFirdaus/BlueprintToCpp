// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestTriggerCollect.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestTriggerCollect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestTriggerCollect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "QTriggerCollect++")
	bool IsCorrectItem(class AActor* Item);
	UFUNCTION(BlueprintCallable, Category = "QTriggerCollect++")
	void MarkItemSeen(AActor* NewItem);
	UFUNCTION(BlueprintPure, Category = "QTriggerCollect++")
	bool HasNotSeenItem(AActor* ItemToFind);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USphereComponent* SphereCollision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemTag;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSet<AActor*> SeenItems;
};
