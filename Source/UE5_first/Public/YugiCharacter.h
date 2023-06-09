// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YugiCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UYugiActorComponent;
class UAnimMontage;
class UYugiAttributeComponent;

UCLASS()
class UE5_FIRST_API AYugiCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category="Attack")
	UAnimMontage* AttackAnim;

	FTimerHandle TimerHandle_PrimaryAttack;

	
public:
	// Sets default values for this character's properties
	AYugiCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	UYugiActorComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	UYugiAttributeComponent* AttributeComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void PrimaryAttack();
	void PrimaryInteract();
	void PrimaryAttack_TimeElapsed();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
