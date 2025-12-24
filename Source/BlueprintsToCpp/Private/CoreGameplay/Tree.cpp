// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreGameplay/Tree.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ATree::ATree()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	RootSceneComp = CreateDefaultSubobject<USceneComponent>("RootSceneComp");
	ScaleSceneComp = CreateDefaultSubobject<USceneComponent>("ScaleSceneComp");
	RotationSceneComp = CreateDefaultSubobject<USceneComponent>("RotationSceneComp");
	TreeMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("TreeMeshComp");
	PFXRootSceneComp = CreateDefaultSubobject<USceneComponent>("PFXRootSceneComp");
	PFXFallingLeave01 = CreateDefaultSubobject<UParticleSystemComponent>("PFXFallingLeave01");
	PFXFallingLeave02 = CreateDefaultSubobject<UParticleSystemComponent>("PFXFallingLeave02");
	PFXFallingLeave03 = CreateDefaultSubobject<UParticleSystemComponent>("PFXFallingLeave03");
	PFXFallingLeave04 = CreateDefaultSubobject<UParticleSystemComponent>("PFXFallingLeave04");
		
	RootComponent = RootSceneComp;
	
	ScaleSceneComp->SetupAttachment(RootSceneComp);
	RotationSceneComp->SetupAttachment(ScaleSceneComp);
	TreeMeshComp->SetupAttachment(RotationSceneComp);
	PFXRootSceneComp->SetupAttachment(RotationSceneComp);
	PFXFallingLeave01->SetupAttachment(PFXRootSceneComp);
	PFXFallingLeave02->SetupAttachment(PFXRootSceneComp);
	PFXFallingLeave03->SetupAttachment(PFXRootSceneComp);
	PFXFallingLeave04->SetupAttachment(PFXRootSceneComp);
}

// Called when the game starts or when spawned
void ATree::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

