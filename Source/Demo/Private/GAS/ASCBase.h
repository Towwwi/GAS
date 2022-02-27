// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ASCBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UASCBase*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class DEMO_API UASCBase : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	bool CharacterAbilitiesGiven = false;
	bool StartupEffectsApplied = false;

	FReceivedDamageDelegate ReceivedDamage;

	//Called from DamageExecution. Broadcasts on ReceivedDamage whenever this ASC receives damage.
	virtual void ReceiveDamage(UASCBase* SourceASC, float UnmitigatedDamage, float MitigatedDamage);
};
