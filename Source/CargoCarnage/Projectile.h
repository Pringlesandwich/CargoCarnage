// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class CARGOCARNAGE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile")
	USphereComponent* ProjectileCollision;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Projectile")
	UStaticMeshComponent * ProjectileMesh;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Projectile")
	UProjectileMovementComponent* ProjectileMovement;



	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	*/

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile")
		int32 Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile")
		float fProjectileSpeed = 300.0f;
	
};
