// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainDisplay.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTSTOCPP_API UMainDisplay : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category= "MainDisplay++")
	void RefreshChildren();
	
	/*UFUNCTION(BlueprintImplementableEvent, Category= "MainDisplay++")
	void AddItem();*/
	
protected:
	virtual void NativeConstruct() override;
};
