// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Demo/Private/GAS/ASCBase.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStateBase.generated.h"



/**
 * 
 */
UCLASS()
class APlayerStateBase : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	APlayerStateBase();

	// GETTERS
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	class UAttributeSetBase* GetAttributeSetBase() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState // Getters")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState // Getters")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState // Getters")
	float GetMana() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerState // Getters")
	float GetMaxMana() const;

protected:
	
	//Osoitin omaan ASC
	UPROPERTY()
	class UASCBase* ASC;

	//Osoitin AttributeSetBase
	UPROPERTY()
	class UAttributeSetBase* AttributeSetBase;

	// Attribute changed callbacks
	virtual void HealthChanged(const FOnAttributeChangeData& Data);
	virtual void MaxHealthChanged(const FOnAttributeChangeData& Data);

	virtual void ManaChanged(const FOnAttributeChangeData& Data);
	virtual void MaxManaChanged(const FOnAttributeChangeData& Data);

};
