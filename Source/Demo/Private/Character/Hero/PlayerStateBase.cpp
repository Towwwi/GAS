// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Hero/PlayerStateBase.h"
#include "GAS/AttributeSetBase.h"

APlayerStateBase::APlayerStateBase()
{

	// Luodaan ASC ja laitetaan replikaatio p‰‰lle
	ASC = CreateDefaultSubobject<UASCBase>(TEXT("ASC"));
	ASC->SetIsReplicated(true);

	// Mixed mode means we only are replicated the GEs to ourself, not the GEs to simulated proxies. If another GDPlayerState (Hero) receives a GE,
	// we won't be told about it by the Server. Attributes, GameplayTags, and GameplayCues will still replicate to us.
	ASC->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	//Nostetaan NetUpdateFreguency samaan kuin Character-luokalla.
	NetUpdateFrequency = 100.0f;

	// Create the attribute set, this replicates by default
	// Adding it as a subobject of the owning actor of an AbilitySystemComponent
	// automatically registers the AttributeSet with the AbilitySystemComponent
	AttributeSetBase = CreateDefaultSubobject<UAttributeSetBase>(TEXT("AttributeSetBase"));
}

//Apply dying and HP bar percentage
void APlayerStateBase::HealthChanged(const FOnAttributeChangeData& Data)
{
	float Health = Data.NewValue;

	// Update floating status bar
// 	AHeroCharacter* Hero = Cast<AHeroCharacter>(GetPawn());
// 	if (Hero)
// 	{
// 		UFloatingStatusBarWidget* HeroFloatingStatusBar = Hero->GetFloatingStatusBar();
// 		if (HeroFloatingStatusBar)
// 		{
// 			HeroFloatingStatusBar->SetHealthPercentage(Health / GetMaxHealth());
// 		}
// 	}

	// Update the HUD
	// Handled in the UI itself using the AsyncTaskAttributeChanged node as an example how to do it in Blueprint

	// If the player died, handle death
	// 	   TODO!
// 	if (!IsAlive() && !AbilitySystemComponent->HasMatchingGameplayTag(DeadTag))
// 	{
// 		if (Hero)
// 		{
// 			Hero->HeroDie();
// 		}
// 	}
}

void APlayerStateBase::MaxHealthChanged(const FOnAttributeChangeData& Data)
{

}

void APlayerStateBase::ManaChanged(const FOnAttributeChangeData& Data)
{
	float Mana = Data.NewValue;

	// Update floating status bar
// 	AHeroCharacter* Hero = Cast<AHeroCharacter>(GetPawn());
// 	if (Hero)
// 	{
// 		UFloatingStatusBarWidget* HeroFloatingStatusBar = Hero->GetFloatingStatusBar();
// 		if (HeroFloatingStatusBar)
// 		{
// 			HeroFloatingStatusBar->SetManaPercentage(Mana / GetMaxMana());
// 		}
// 	}

	// Update the HUD
	// Handled in the UI itself using the AsyncTaskAttributeChanged node as an example how to do it in Blueprint
}

void APlayerStateBase::MaxManaChanged(const FOnAttributeChangeData& Data)
{

}








//Palauttaa meid‰n oman ASC:n
class UAbilitySystemComponent* APlayerStateBase::GetAbilitySystemComponent() const
{
	return ASC;
}

class UAttributeSetBase* APlayerStateBase::GetAttributeSetBase() const
{
	return AttributeSetBase;
}

float APlayerStateBase::GetHealth() const
{
	return AttributeSetBase->GetHealth();
}

float APlayerStateBase::GetMaxHealth() const
{
	return AttributeSetBase->GetMaxHealth();
}

float APlayerStateBase::GetMana() const
{
	return AttributeSetBase->GetMana();
}

float APlayerStateBase::GetMaxMana() const
{
	return AttributeSetBase->GetMaxMana();
}