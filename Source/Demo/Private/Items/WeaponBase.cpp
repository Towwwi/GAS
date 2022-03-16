// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/WeaponBase.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/BoxComponent.h"
#include "Character/Hero/HeroCharacter.h"
#include "Sound/SoundCue.h"
#include "GAS/ASCBase.h"
#include "Demo/Demo.h"
#include "GAS/GameplayAbilityBase.h"
#include "Character/Hero/HeroCharacter.h"
#include "GameplayAbilitySpec.h"
#include "Kismet/GameplayStatics.h" 
#include "Net/UnrealNetwork.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Weapons are not replicated

AWeaponBase::AWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal mesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());

	CombatCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Combat collision"));
	CombatCollision->SetupAttachment(GetRootComponent());

	bReplicates = true;

	WeaponState = EWeaponState::EWS_Pickup;


}

void AWeaponBase::Equip(class AHeroCharacter* character)
{

	if (WeaponState == EWeaponState::EWS_Pickup)
	{ 
	
	SetInstigator(character);
	SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	SkeletalMesh->SetSimulatePhysics(false);


		// Visuals
	 	if (character)
	 	{
	 		if (EquipWeaponSound)
	 		{
	 			UGameplayStatics::PlaySoundAtLocation(this, EquipWeaponSound, GetActorLocation());
	 		}
	 		if (!bWeaponParticles)
			{
	 			//IdleParticlesComponent->Deactivate();
	 		}
		}


	if (character)
	{
		const USkeletalMeshSocket* RightHandSocket = character->GetMesh()->GetSocketByName("WeaponSocket");
		if (RightHandSocket)
		{
			RightHandSocket->AttachActor(this, character->GetMesh());

			character->SetEquippedWeapon(this);
			character->SetActiveOverlappingItem(nullptr);

		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("righthandsocket null"));
		}
	}
	}

	else
	{
	return;
	}
}


// void AWeaponBase::ServerEquip_Implementation(class AHeroCharacter* character)
// {
// 
// }
// 
// bool AWeaponBase::ServerEquip_Validate(class AHeroCharacter* character)
// {
// 	return true;
// }


void AWeaponBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{

}

void AWeaponBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if ((WeaponState == EWeaponState::EWS_Pickup) && OtherActor)
	{
		AHeroCharacter* Main = Cast<AHeroCharacter>(OtherActor);
		if (Main)
		{
			Main->SetActiveOverlappingItem(this);
		}
	}
}

void AWeaponBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	if (OtherActor)
	{
		AHeroCharacter* Main = Cast<AHeroCharacter>(OtherActor);
		if (Main)
		{
			Main->SetActiveOverlappingItem(nullptr); // if endoverlap with weapon, set overlappeditem to nullpointer
		}
	}
}

FORCEINLINE void AWeaponBase::SetWeaponState(EWeaponState State)
{
	WeaponState = State;
}

void AWeaponBase::CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AWeaponBase::CombatOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AWeaponBase::ActivateCollision()
{

}

void AWeaponBase::DeActivateCollision()
{

}


void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}


int32 AWeaponBase::GetAbilityLevel(EAbilityInputID AbilityID)
{
	// All abilities for now are level 1
	return 1;
}


TArray<TSubclassOf<UGameplayAbilityBase>> AWeaponBase::GetAbilities()
{
	return Abilities;
}
