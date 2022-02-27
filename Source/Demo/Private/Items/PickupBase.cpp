// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/PickupBase.h"
#include "Character/Hero/HeroCharacter.h"
#include "AbilitySystemComponent.h"
#include "GAS/GameplayAbilityBase.h"
#include "Demo/Demo.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Sound/SoundCue.h"
#include "TimerManager.h"

// Sets default values
APickupBase::APickupBase()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	bIsActive = true;
	bCanRespawn = true;
	RespawnTime = 5.0f;

	CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(FName("CollisionComp"));
	CollisionComp->InitCapsuleSize(40.0f, 50.0f);
	CollisionComp->SetCollisionObjectType(COLLISION_PICKUP);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = CollisionComp;

	RestrictedPickupTags.AddTag(FGameplayTag::RequestGameplayTag("State.Dead"));
	RestrictedPickupTags.AddTag(FGameplayTag::RequestGameplayTag("State.KnockedDown"));
}

void APickupBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APickupBase, bIsActive);
	DOREPLIFETIME(APickupBase, PickedUpBy);
}

void APickupBase::NotifyActorBeginOverlap(AActor* Other)
{
	if (GetLocalRole() == ROLE_Authority && Other && Other != this)
	{
		PickupOnTouch(Cast<AHeroCharacter>(Other));
	}
}

bool APickupBase::CanBePickedUp(AHeroCharacter* TestCharacter) const
{
	return bIsActive && TestCharacter && TestCharacter->IsAlive() && !IsPendingKill() && !TestCharacter->GetAbilitySystemComponent()->HasAnyMatchingGameplayTags(RestrictedPickupTags) && K2_CanBePickedUp(TestCharacter);
}

bool APickupBase::K2_CanBePickedUp_Implementation(AHeroCharacter* TestCharacter) const
{
	return true;
}

void APickupBase::PickupOnTouch(AHeroCharacter* Pawn)
{
	if (CanBePickedUp(Pawn))
	{
		GivePickupTo(Pawn);
		PickedUpBy = Pawn;
		bIsActive = false;
		OnPickedUp();

		if (bCanRespawn && RespawnTime > 0.0f)
		{
			GetWorldTimerManager().SetTimer(TimerHandle_RespawnPickup, this, &APickupBase::RespawnPickup, RespawnTime, false);
		}
		else
		{
			Destroy();
		}
	}
}

void APickupBase::GivePickupTo(AHeroCharacter* Pawn)
{
	UAbilitySystemComponent* ASC = Pawn->GetAbilitySystemComponent();

	if (!ASC)
	{
		UE_LOG(LogTemp, Error, TEXT("%s Pawn's ASC is null."), *FString(__FUNCTION__));
		return;
	}

	for (TSubclassOf<UGameplayAbilityBase> AbilityClass : AbilityClasses)
	{
		if (!AbilityClass)
		{
			continue;
		}

		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1, static_cast<int32>(AbilityClass.GetDefaultObject()->AbilityInputID), this);
		ASC->GiveAbilityAndActivateOnce(AbilitySpec);
	}

	FGameplayEffectContextHandle EffectContext = ASC->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	for (TSubclassOf<UGameplayEffect> EffectClass : EffectClasses)
	{
		if (!EffectClass)
		{
			continue;
		}

		//TODO
		FGameplayEffectSpecHandle NewHandle = ASC->MakeOutgoingSpec(EffectClass, Pawn->GetCharacterLevel(), EffectContext); 

		if (NewHandle.IsValid())
		{
			ASC->ApplyGameplayEffectSpecToSelf(*NewHandle.Data.Get());
		}
	}
}

void APickupBase::OnPickedUp()
{
	K2_OnPickedUp();

	if (PickupSound && PickedUpBy)
	{
		UGameplayStatics::SpawnSoundAttached(PickupSound, PickedUpBy->GetRootComponent());
	}
}

void APickupBase::RespawnPickup()
{
	bIsActive = true;
	PickedUpBy = NULL;
	OnRespawned();

	TSet<AActor*> OverlappingPawns;
	GetOverlappingActors(OverlappingPawns, AHeroCharacter::StaticClass());

	for (AActor* OverlappingPawn : OverlappingPawns)
	{
		PickupOnTouch(CastChecked<AHeroCharacter>(OverlappingPawn));
	}
}

void APickupBase::OnRespawned()
{
	K2_OnRespawned();
}

void APickupBase::OnRep_IsActive()
{
	if (bIsActive)
	{
		OnRespawned();
	}
	else
	{
		OnPickedUp();
	}
}

