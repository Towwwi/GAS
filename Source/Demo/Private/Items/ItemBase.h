// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class AItemBase : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
		class USphereComponent* CollisionVolume;

	/** mesh component*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
		class UStaticMeshComponent* Mesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
