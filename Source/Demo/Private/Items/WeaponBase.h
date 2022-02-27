// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemBase.h"
#include "Sound/SoundCue.h"
#include "Demo/Demo.h"
#include "GameplayAbilitySpec.h"
#include "Character/Hero/PlayerControllerBase.h"
#include "WeaponBase.generated.h"


class AHeroCharacter;
class UASCBase;
class UGameplayAbilityBase;

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Pickup UMETA(DisplayName = "Pickup"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Max UMETA(DisplayName = "DefaultMAX")
};


/**
 * 
 */
UCLASS()
class AWeaponBase : public AItemBase
{
	GENERATED_BODY()

public:
	AWeaponBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item // Sound ")
	USoundCue* SwingSound;

	UFUNCTION(BlueprintCallable)
	void Equip(class AHeroCharacter* character);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbilityBase>> Abilities;

	UFUNCTION(BlueprintCallable)
	TArray<TSubclassOf<UGameplayAbilityBase>> GetAbilities();


	UPROPERTY(BlueprintReadOnly, Category = "Abilities")
	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;

	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Character")
	AHeroCharacter* OwningCharacter;

	virtual int32 GetAbilityLevel(EAbilityInputID AbilityID);

	// Required network scaffolding
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item // Combat")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item // Combat")
	class UBoxComponent* CombatCollision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item // Particles")
	bool bWeaponParticles;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "skeletal mesh")
	class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item // Sound ")
	class USoundCue* EquipWeaponSound;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	// Weapon State
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item")
	EWeaponState WeaponState;
	FORCEINLINE void SetWeaponState(EWeaponState) { WeaponState = WeaponState; }
	FORCEINLINE EWeaponState GetWeaponState() { return WeaponState; }


	UFUNCTION(BlueprintCallable)
	void CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void CombatOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void ActivateCollision();

	UFUNCTION(BlueprintCallable)
	void DeActivateCollision();

protected:
	virtual void BeginPlay() override;

};
