// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerUserWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class UPlayerUserWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:

	/**
	* Attribute setters
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void SetMaxHealth(float MaxHealth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void SetCurrentHealth(float CurrentHealth);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void SetHealthPercentage(float HealthPercentage);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void SetHealthRegenRate(float HealthRegenRate);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void SetMaxMana(float MaxMana);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void SetCurrentMana(float CurrentMana);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void SetManaPercentage(float ManaPercentage);

};
