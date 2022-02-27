// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemBase.h"
#include "Components/SphereComponent.h"

// Sets default values
AItemBase::AItemBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	RootComponent = CollisionVolume;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();

	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AItemBase::OnOverlapEnd);
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverLapbegin on Pickup"));
}

void AItemBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnOverLapEnd on Pickup"));


}

