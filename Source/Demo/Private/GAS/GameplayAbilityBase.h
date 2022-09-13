// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Demo/Demo.h"
#include "GameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class UGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:

UGameplayAbilityBase();

// Abilities with this set will automatically activate when the input is pressed
UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
EAbilityInputID AbilityInputID = EAbilityInputID::None;

// Value to associate an ability with an slot without tying it to an automatically activated input.
// Passive abilities won't be tied to an input so we need a way to generically associate abilities with slots.
UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
EAbilityInputID AbilityID = EAbilityInputID::None;

// Tells an ability to activate immediately when its granted, used mostly in passives or as other abilities that activates on "Beginplay"
UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability")
bool ActivateAbilityOnGranted = false;
	
};
