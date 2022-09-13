// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "EnemyCharacterBase.generated.h"


/**
 * All AI Characters derive from this class
 */
UCLASS()
class AEnemyCharacterBase : public ACharacterBase
{
	GENERATED_BODY()

public:
	AEnemyCharacterBase();

protected:

	//hard pointer to AbilitySystemComponent
	UPROPERTY()
	class UASCBase* HardRefAbilitySystemComponent;

	// hard pointer to AttributeSetBase
	UPROPERTY()
	class UAttributeSetBase* HardRefAttributeSetBase;

	virtual void BeginPlay() override;
	
	FDelegateHandle HealthChangedDelegateHandle;

	// Attribute changed callbacks
	virtual void HealthChanged(const FOnAttributeChangeData& Data);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "HealthBar")
	TSubclassOf<class UEnemyBar> EnemyBarClass;

	UPROPERTY()
	class UEnemyBar* EnemyBar;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "HealthBar")
	class UWidgetComponent* EnemyBarComponent;
};
