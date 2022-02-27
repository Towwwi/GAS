// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "DefaultDamageExecutionCalc.generated.h"

/**
 * 
 */
UCLASS()
class UDefaultDamageExecutionCalc : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	// Constructor and overrides
	UDefaultDamageExecutionCalc();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
