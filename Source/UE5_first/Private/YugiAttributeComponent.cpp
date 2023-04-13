// Fill out your copyright notice in the Description page of Project Settings.


#include "YugiAttributeComponent.h"

// Sets default values for this component's properties
UYugiAttributeComponent::UYugiAttributeComponent()
{
	Health = 100;
}

bool UYugiAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;
	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);
	return true;
}
