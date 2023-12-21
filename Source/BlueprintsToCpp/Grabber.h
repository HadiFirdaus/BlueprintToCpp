// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grabber.generated.h"

/*
*
*/
UCLASS(Blueprintable, ClassGroup = "Custom", meta = (BlueprintSpawnableComponent))
class BLUEPRINTSTOCPP_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Grabber++")
	FVector GetMaxGrabLocation() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Grabber++")
	FVector GetHoldLocation() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Grabber++")
	class UPhysicsHandleComponent* GetPhysicsComponent() const;
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Grabber++")
	void NotifyQuestActor(AActor* Actor);
	
	UFUNCTION(BlueprintCallable, Category = "Grabber++")
	bool TracesForPhysicsBodies(AActor*& HitActor,class UPrimitiveComponent*& HitComponent);
	
	UFUNCTION(BlueprintCallable, Category="Grabber++")
	void Releasing() const;

	UFUNCTION(BlueprintCallable, Category = "Grabber++")
	void Grabber();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Grabber++")
	float MaxGrabDistance = 100.0f;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Grabber++")
	float HoldDistance = 100.0f;
	
	UPROPERTY(BlueprintReadOnly)
	float GrabRadius = 50.0f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
