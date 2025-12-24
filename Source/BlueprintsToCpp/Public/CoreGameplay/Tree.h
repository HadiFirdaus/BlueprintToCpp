// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tree.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API ATree : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATree();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class USceneComponent* RootSceneComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class USceneComponent* ScaleSceneComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class USceneComponent* RotationSceneComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class UStaticMeshComponent* TreeMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class USceneComponent* PFXRootSceneComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class UParticleSystemComponent* PFXFallingLeave01;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class UParticleSystemComponent* PFXFallingLeave02;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class UParticleSystemComponent* PFXFallingLeave03;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tree++")
	class UParticleSystemComponent* PFXFallingLeave04;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
