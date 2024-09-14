// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AFirstPersonCharacter::Forward);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstPersonCharacter::Jump);

}

void AFirstPersonCharacter::Forward(float AxisValue)
{
	//UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();
	//if (CharacterMovement) {
	//	CharacterMovement->AddInputVector()
	//}
}

void AFirstPersonCharacter::Jump()
{
	UE_LOG(LogTemp, Warning, TEXT("Jump"));
}
