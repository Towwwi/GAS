// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
public:

	void CreateHUD();

	UPROPERTY(EditAnywhere, Category = "UI")
		TSubclassOf<class UDamageTextWidget> DamageNumberClass;

	class UPlayerUserWidgetBase* GetHUD();

	UFUNCTION(Client, Reliable, WithValidation)
	void ShowDamageNumber(float DamageAmount, ACharacterBase* TargetCharacter);
	void ShowDamageNumber_Implementation(float DamageAmount, ACharacterBase* TargetCharacter);
	bool ShowDamageNumber_Validate(float DamageAmount, ACharacterBase* TargetCharacter);

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
		TSubclassOf<class UPlayerUserWidgetBase> UIHUDWidgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
		class UPlayerUserWidgetBase* UIHUDWidget;


	// Server only
	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnRep_PlayerState() override;
};
