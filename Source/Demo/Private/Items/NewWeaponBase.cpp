// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/NewWeaponBase.h"
#include "GAS/ASCBase.h"
#include "GAS/GameplayAbilityBase.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Character/Hero/HeroCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Character/Hero/PlayerControllerBase.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
// ANewWeaponBase::ANewWeaponBase()
// {
//  	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
// 	PrimaryActorTick.bCanEverTick = true;
// 
// }

// UAbilitySystemComponent* ANewWeaponBase::GetAbilitySystemComponent() const
// {
// 	return AbilitySystemComponent;
// }
// 
// USkeletalMeshComponent* ANewWeaponBase::GetWeaponMesh1P() const
// {
// 	return WeaponMesh1P;
// }
// 
// 
// void ANewWeaponBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
// {
// 	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
// 
// 	DOREPLIFETIME_CONDITION(ANewWeaponBase, OwningCharacter, COND_OwnerOnly);
// }
// 
// void ANewWeaponBase::PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker)
// {
// 	Super::PreReplication(ChangedPropertyTracker);
// 
// 
// }
// 
// void ANewWeaponBase::SetOwningCharacter(AHeroCharacter* InOwningCharacter)
// {
// 	OwningCharacter = InOwningCharacter;
// 	if (OwningCharacter)
// 	{
// 		// Called when added to inventory
// 		AbilitySystemComponent = Cast<UASCBase>(OwningCharacter->GetAbilitySystemComponent());
// 		SetOwner(InOwningCharacter);
// 		AttachToComponent(OwningCharacter->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
// 		CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
// 
// 		if (OwningCharacter->GetCurrentWeapon() != this)
// 		{
// 
// 		}
// 	}
// 	else
// 	{
// 		AbilitySystemComponent = nullptr;
// 		SetOwner(nullptr);
// 		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
// 	}
// }
// 
// void ANewWeaponBase::NotifyActorBeginOverlap(AActor* Other)
// {
// 	Super::NotifyActorBeginOverlap(Other);
// 
// 	if (!IsPendingKill() && !OwningCharacter)
// 	{
// 		PickUpOnTouch(Cast<AHeroCharacter>(Other));
// 	}
// }
// 
// void ANewWeaponBase::Equip()
// {
// 	if (!OwningCharacter)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("%s %s OwningCharacter is nullptr"), *FString(__FUNCTION__), *GetName());
// 		return;
// 	}
// 
// 	FName AttachPoint = OwningCharacter->GetWeaponAttachPoint();
// 
// 	if (WeaponMesh1P)
// 	{
// 		WeaponMesh1P->AttachToComponent(OwningCharacter->GetFirstPersonMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, AttachPoint);
// 		WeaponMesh1P->SetRelativeLocation(WeaponMesh1PEquippedRelativeLocation);
// 		WeaponMesh1P->SetRelativeRotation(FRotator(0, 0, -90.0f));
// 
// 		if (OwningCharacter->IsInFirstPersonPerspective())
// 		{
// 			WeaponMesh1P->SetVisibility(true, true);
// 		}
// 		else
// 		{
// 			WeaponMesh1P->SetVisibility(false, true);
// 		}
// 	}
// 
// }
// 
// void ANewWeaponBase::UnEquip()
// {
// 	if (OwningCharacter == nullptr)
// 	{
// 		return;
// 	}
// 
// 	// Necessary to detach so that when toggling perspective all meshes attached won't become visible.
// 
// 	WeaponMesh1P->DetachFromComponent(FDetachmentTransformRules::KeepRelativeTransform);
// 	WeaponMesh1P->SetVisibility(false, true);
// 
// }
// 
// void ANewWeaponBase::AddAbilities()
// {
// 	if (!IsValid(OwningCharacter) || !OwningCharacter->GetAbilitySystemComponent())
// 	{
// 		return;
// 	}
// 
// 	UASCBase* ASC = Cast<UASCBase>(OwningCharacter->GetAbilitySystemComponent());
// 
// 	if (!ASC)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("%s %s Role: %s ASC is null"), *FString(__FUNCTION__), *GetName(), GET_ACTOR_ROLE_FSTRING(OwningCharacter));
// 		return;
// 	}
// 
// 	// Grant abilities, but only on the server	
// 	if (GetLocalRole() != ROLE_Authority)
// 	{
// 		return;
// 	}
// 
// 	for (TSubclassOf<UGameplayAbilityBase>& Ability : Abilities)
// 	{
// 		AbilitySpecHandles.Add(ASC->GiveAbility(
// 			FGameplayAbilitySpec(Ability, GetAbilityLevel(Ability.GetDefaultObject()->AbilityID), static_cast<int32>(Ability.GetDefaultObject()->AbilityInputID), this)));
// 	}
// }
// 
// void ANewWeaponBase::RemoveAbilities()
// {
// 	if (!IsValid(OwningCharacter) || !OwningCharacter->GetAbilitySystemComponent())
// 	{
// 		return;
// 	}
// 
// 	UASCBase* ASC = Cast<UASCBase>(OwningCharacter->GetAbilitySystemComponent());
// 
// 	if (!ASC)
// 	{
// 		return;
// 	}
// 
// 	// Remove abilities, but only on the server	
// 	if (GetLocalRole() != ROLE_Authority)
// 	{
// 		return;
// 	}
// 
// 	for (FGameplayAbilitySpecHandle& SpecHandle : AbilitySpecHandles)
// 	{
// 		ASC->ClearAbility(SpecHandle);
// 	}
// }
// 
// int32 ANewWeaponBase::GetAbilityLevel(EAbilityInputID AbilityID)
// {
// 	// All abilities for now are level 1
// 	return 1;
// }
// 
// 
// void ANewWeaponBase::OnDropped_Implementation(FVector NewLocation)
// {
// 	SetOwningCharacter(nullptr);
// 	ResetWeapon();
// 
// 	SetActorLocation(NewLocation);
// 	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
// 
// 	if (WeaponMesh1P)
// 	{
// 		WeaponMesh1P->AttachToComponent(CollisionComp, FAttachmentTransformRules::SnapToTargetIncludingScale);
// 		WeaponMesh1P->SetVisibility(false, true);
// 	}
// 
// }
// 
// bool ANewWeaponBase::OnDropped_Validate(FVector NewLocation)
// {
// 	return true;
// }
// 
// 
// UAnimMontage* ANewWeaponBase::GetEquip1PMontage() const
// {
// 	return Equip1PMontage;
// }
// 
// USoundCue* ANewWeaponBase::GetPickupSound() const
// {
// 	return PickupSound;
// }
// 
// FText ANewWeaponBase::GetDefaultStatusText() const
// {
// 	return DefaultStatusText;
// }
// 
// 
// 
// void ANewWeaponBase::BeginPlay()
// {
// 	ResetWeapon();
// 
// 	if (!OwningCharacter && bSpawnWithCollision)
// 	{
// 		// Spawned into the world without an owner, enable collision as we are in pickup mode
// 		CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
// 	}
// 
// 	Super::BeginPlay();
// }
// 
// void ANewWeaponBase::EndPlay(EEndPlayReason::Type EndPlayReason)
// {
// 	Super::EndPlay(EndPlayReason);
// }
// 
// void ANewWeaponBase::PickUpOnTouch(AHeroCharacter* InCharacter)
// {
// 	if (!InCharacter || !InCharacter->IsAlive() || !InCharacter->GetAbilitySystemComponent() || InCharacter->GetAbilitySystemComponent()->HasAnyMatchingGameplayTags(RestrictedPickupTags))
// 	{
// 		return;
// 	}
// }
