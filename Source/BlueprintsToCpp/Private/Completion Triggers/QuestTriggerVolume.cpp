// Fill out your copyright notice in the Description page of Project Settings.


#include "Completion Triggers/QuestTriggerVolume.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AQuestTriggerVolume::AQuestTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponentRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponentRoot"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = SceneComponentRoot;
}

// Called when the game starts or when spawned
void AQuestTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AQuestTriggerVolume::OnBeginOverlapBox);
}

// Called every frame
void AQuestTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuestTriggerVolume::OnBeginOverlapBox(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor) {
		UE_LOG(LogTemp, Warning, TEXT("Collide"));

	}
}