// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GameplayAbilityBase.h"

UGameplayAbilityBase::UGameplayAbilityBase()
{
	// Default to Instance Per Actor
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	// Default tags that block this ability from activating
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Stun")));
}


