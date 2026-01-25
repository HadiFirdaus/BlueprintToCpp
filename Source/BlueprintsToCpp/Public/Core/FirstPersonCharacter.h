// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category= "FirstPersonCharacter++")
	class UCameraComponent* FirstPersonCameraComponent;
	UPROPERTY(EditDefaultsOnly, Category= "FirstPersonCharacter++")
	class UPhysicsHandleComponent* PhysicsHandle;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "FirstPersonCharacter++")
	void AddInputVector(float AxisValue, FVector ActorVector);
	
private:
	void Forward(float AxisValue);
	void Jump();

};
