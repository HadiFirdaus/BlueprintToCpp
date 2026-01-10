// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreGameplay/Grabber.h"
#include "Kismet/KismetMathLibrary.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"	//For UPhysicsHandleComponent
#include "GameFramework/Actor.h"	//for GetOwner()
#include "Engine/World.h"	//LineTrace
#include "Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetPhysicsComponent()->SetTargetLocationAndRotation(GetHoldLocation(), GetOwner()->GetActorRotation());
}

FVector UGrabber::GetMaxGrabLocation() const
{
	FVector temp;
	temp = UKismetMathLibrary::GetForwardVector(GetComponentRotation())*MaxGrabDistance;
	return 	GetComponentLocation() + temp;
}

FVector UGrabber::GetHoldLocation() const
{
	FVector temp;
	temp = GetComponentRotation().Vector()*HoldDistance;
	return GetComponentLocation() + temp;
}

UPhysicsHandleComponent* UGrabber::GetPhysicsComponent() const
{
	return 	GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}

bool UGrabber::TracesForPhysicsBodies(AActor *& HitActor, UPrimitiveComponent *& HitComponent)
{
	FHitResult OutHit;
	const FVector Start = GetComponentLocation();
	const FVector End = GetMaxGrabLocation();
	ECollisionChannel TraceChannel = ECollisionChannel::ECC_Visibility;
	bool bHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, TraceChannel);
	if (bHit) {
		HitActor = OutHit.GetActor();
		HitComponent = OutHit.GetComponent();
		return bHit;
	}
	else {
		return false;
	}
}

void UGrabber::Releasing() const
{
	GetPhysicsComponent()->ReleaseComponent();
}

void UGrabber::Grabber()
{
	AActor* TheActor;
	UPrimitiveComponent* TheComponent;
	if (TracesForPhysicsBodies(TheActor, TheComponent)) {
		if (TheComponent) {
			TheComponent->SetSimulatePhysics(true);
			FVector GrabLocation = TheComponent->GetCenterOfMass(NAME_None);
			GetPhysicsComponent()->GrabComponentAtLocation(TheComponent, NAME_None, GrabLocation);
			if (TheActor) {
				NotifyQuestActor(TheActor);
			}
		}
	}
}