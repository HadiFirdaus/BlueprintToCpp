// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreGameplay/Tree.h"
#include "CuttableTree.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API ACuttableTree : public ATree
{
	GENERATED_BODY()

public:
	ACuttableTree();
	
protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CuttableTree++")
	FTransform StartRotation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CuttableTree++")
	FTransform TargetRotation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CuttableTree++")
	FTransform StartStump;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CuttableTree++")
	FTransform TargetStump;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CuttableTree++")
	class UStaticMeshComponent* TreeStumpComp;
};
