// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "Demo/Demo.h"
#include "GameplayAbilitySpec.h"
#include "GameplayTagContainer.h"
#include "NewWeaponBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWeaponAmmoChangedDelegate, int32, OldValue, int32, NewValue);



UCLASS(Blueprintable, BlueprintType)
class ANewWeaponBase : public AActor
{
	GENERATED_BODY()

	//Use WeaponBase


};
