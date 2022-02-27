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

// class UASCBase;
// class UGameplayAbilityBase;
// class USkeletalMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class ANewWeaponBase : public AActor
{
	GENERATED_BODY()
// 	
// public:
// 	// Sets default values for this actor's properties
// 	ANewWeaponBase();
// 
// 	// Whether or not to spawn this weapon with collision enabled (pickup mode).
// 	// Set to false when spawning directly into a player's inventory or true when spawning into the world in pickup mode.
// 	UPROPERTY(BlueprintReadWrite)
// 		bool bSpawnWithCollision;
// 
// 	// This tag is primarily used by the first person Animation Blueprint to determine which animations to play
// 	// (Rifle vs Rocket Launcher)
// 	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GASShooter|GSWeapon")
// 		FGameplayTag WeaponTag;
// 
// 	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GASShooter|GSWeapon")
// 		FGameplayTagContainer RestrictedPickupTags;
// 
// 	// Implement IAbilitySystemInterface
// 	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
// 
// 	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GASShooter|GSWeapon")
// 		virtual USkeletalMeshComponent* GetWeaponMesh1P() const;
// // 
// // 	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "GASShooter|GSWeapon")
// // 		virtual USkeletalMeshComponent* GetWeaponMesh3P() const;
// 
// 	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
// 
// 	virtual void PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker) override;
// 
// 	void SetOwningCharacter(AHeroCharacter* InOwningCharacter);
// 
// 	// Pickup on touch
// 	virtual void NotifyActorBeginOverlap(class AActor* Other) override;
// 
// 	// Called when the player equips this weapon
// 	virtual void Equip();
// 
// 	// Called when the player unequips this weapon
// 	virtual void UnEquip();
// 
// 	virtual void AddAbilities();
// 
// 	virtual void RemoveAbilities();
// 
// 	virtual int32 GetAbilityLevel(EAbilityInputID AbilityID);
// 
// 
// 	// Resets things like fire mode to default
// 	UFUNCTION(BlueprintCallable, Category = "GASShooter|GSWeapon")
// 	virtual void ResetWeapon();
// 
// 	UFUNCTION(NetMulticast, Reliable)
// 	void OnDropped(FVector NewLocation);
// 	virtual void OnDropped_Implementation(FVector NewLocation);
// 	virtual bool OnDropped_Validate(FVector NewLocation);
// 
// 	UFUNCTION(BlueprintCallable, Category = "GASShooter|Animation")
// 		UAnimMontage* GetEquip1PMontage() const;
// 
// 	UFUNCTION(BlueprintCallable, Category = "GASShooter|Audio")
// 		class USoundCue* GetPickupSound() const;
// 
// 	UFUNCTION(BlueprintCallable, Category = "GASShooter|GSWeapon")
// 		FText GetDefaultStatusText() const;
// 
// 
// protected:
// 	UPROPERTY()
// 		UASCBase* AbilitySystemComponent;
// 
// 	// Collision capsule for when weapon is in pickup mode
// 	UPROPERTY(VisibleAnywhere)
// 		class UCapsuleComponent* CollisionComp;
// 
// 	UPROPERTY(VisibleAnywhere, Category = "GASShooter|GSWeapon")
// 		USkeletalMeshComponent* WeaponMesh1P;
// 
// 
// 	// Relative Location of weapon 3P Mesh when in pickup mode
// 	// 1P weapon mesh is invisible so it doesn't need one
// 	UPROPERTY(EditDefaultsOnly, Category = "GASShooter|GSWeapon")
// 		FVector WeaponMesh3PickupRelativeLocation;
// 
// 	// Relative Location of weapon 1P Mesh when equipped
// 	UPROPERTY(EditDefaultsOnly, Category = "GASShooter|GSWeapon")
// 		FVector WeaponMesh1PEquippedRelativeLocation;
// 
// 	// Relative Location of weapon 3P Mesh when equipped
// 	UPROPERTY(EditDefaultsOnly, Category = "GASShooter|GSWeapon")
// 		FVector WeaponMesh3PEquippedRelativeLocation;
// 
// 	UPROPERTY(BlueprintReadOnly, Replicated, Category = "GASShooter|GSWeapon")
// 		AHeroCharacter* OwningCharacter;
// 
// 	UPROPERTY(EditAnywhere, Category = "GASShooter|GSWeapon")
// 		TArray<TSubclassOf<UGameplayAbilityBase>> Abilities;
// 
// 	UPROPERTY(BlueprintReadOnly, Category = "GASShooter|GSWeapon")
// 		TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
// 
// 	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GASShooter|GSWeapon")
// 		FGameplayTag DefaultFireMode;
// 
// 	// Things like fire mode for rifle
// 	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASShooter|GSWeapon")
// 		FText DefaultStatusText;
// 
// 	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASShooter|Animation")
// 		UAnimMontage* Equip1PMontage;
// 
// 	// Sound played when player picks it up
// 	UPROPERTY(EditDefaultsOnly, Category = "GASShooter|Audio")
// 		class USoundCue* PickupSound;
// 
// 	// Cache tags
// 	FGameplayTag WeaponPrimaryInstantAbilityTag;
// 	FGameplayTag WeaponSecondaryInstantAbilityTag;
// 	FGameplayTag WeaponAlternateInstantAbilityTag;
// 	FGameplayTag WeaponIsFiringTag;
// 
// 	virtual void BeginPlay() override;
// 	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
// 
// 	// Called when the player picks up this weapon
// 	virtual void PickUpOnTouch(AHeroCharacter* InCharacter);



};
