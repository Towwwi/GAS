// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/EnemyCharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "GAS/AttributeSetBase.h"
#include "UI/EnemyBar.h"
#include "GameplayEffectTypes.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"
#include "GAS/ASCBase.h"

AEnemyCharacterBase::AEnemyCharacterBase()
{
	// Create ability system component, and set it to be explicitly replicated
	HardRefAbilitySystemComponent = CreateDefaultSubobject<UASCBase>(TEXT("ASC"));
	HardRefAbilitySystemComponent->SetIsReplicated(true);

	// Minimal Mode means that no GameplayEffects will replicate. They will only live on the Server. Attributes, GameplayTags, and GameplayCues will still replicate to us.
	HardRefAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	// Set our parent's TWeakObjectPtr
	AbilitySystemComponent = HardRefAbilitySystemComponent;

	// Create the attribute set, this replicates by default
	// Adding it as a subobject of the owning actor of an AbilitySystemComponent
	// automatically registers the AttributeSet with the AbilitySystemComponent
	HardRefAttributeSetBase = CreateDefaultSubobject<UAttributeSetBase>(TEXT("AttributeSet"));

	// Set our parent's TWeakObjectPtr
	AttributeSetBase = HardRefAttributeSetBase;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);


	EnemyBarComponent = CreateDefaultSubobject<UWidgetComponent>(FName("EnemyBarComponent"));
	EnemyBarComponent->SetupAttachment(RootComponent);
	EnemyBarComponent->SetRelativeLocation(FVector(0, 0, 120));
	EnemyBarComponent->SetWidgetSpace(EWidgetSpace::Screen);
	EnemyBarComponent->SetDrawSize(FVector2D(500, 500));

	EnemyBarClass = StaticLoadClass(UObject::StaticClass(), nullptr, TEXT("/Game/Blueprints/UI/UI_EnemyBar.UI_EnemyBar_C"));
	if (!EnemyBarClass)
	{
		//UE_LOG(LogTemp, Error, TEXT("%s() Failed to find Enemybar. If it was moved, please update the reference location in C++."), *FString(__FUNCTION__));
	}


}

void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent.IsValid())
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		InitializeAttributes();
		AddCharacterAbilities();

		SetHealth(GetMaxHealth());

		// Setup FloatingStatusBar UI for Locally Owned Players only, not AI or the server's copy of the PlayerControllers
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC && PC->IsLocalPlayerController())
		{
			if (EnemyBarClass)
			{
				EnemyBar = CreateWidget<UEnemyBar>(PC, EnemyBarClass);
				if (EnemyBar && EnemyBarComponent)
				{
					EnemyBarComponent->SetWidget(EnemyBar);

					// Setup the floating status bar
					EnemyBar->SetHealthPercentage(GetHealth() / GetMaxHealth());

					EnemyBar->SetCharacterName(CharacterName);
				}
			}
		}

		// Attribute change callbacks
		HealthChangedDelegateHandle = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSetBase->GetHealthAttribute()).AddUObject(this, &AEnemyCharacterBase::HealthChanged);

		// Tag change callbacks
		//AbilitySystemComponent->RegisterGameplayTagEvent(FGameplayTag::RequestGameplayTag(FName("State.Debuff.Stun")), EGameplayTagEventType::NewOrRemoved).AddUObject(this, &AEnemyCharacterBase::StunTagChanged);
	
	}
}


void AEnemyCharacterBase::HealthChanged(const FOnAttributeChangeData& Data)
{
	float Health = Data.NewValue;

	// Update floating status bar
	if (EnemyBar)
	{
		EnemyBar->SetHealthPercentage(Health / GetMaxHealth());
	}

	// Death
	if (!IsAlive() && !AbilitySystemComponent->HasMatchingGameplayTag(DeadTag))
	{
		Die();
	}
}
