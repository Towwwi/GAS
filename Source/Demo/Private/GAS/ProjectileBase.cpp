// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/ProjectileBase.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystem.h"

// default values
AProjectileBase::AProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovement"));
}


void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

