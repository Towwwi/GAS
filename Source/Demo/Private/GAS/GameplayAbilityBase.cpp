// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GameplayAbilityBase.h"

UGameplayAbilityBase::UGameplayAbilityBase()
{
	//Default
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	// Default tags that block abilities from activating
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Stun")));
}


