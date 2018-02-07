// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class CARGOCARNAGE_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool DoOnceFlag;
	FTimerHandle TriggerTimerHandler;

public:

	// List of gun properties

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Properties")
	bool IsAutomatic;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Properties")
	float ProjectileVelocity;

	//set as a percentage. 100 = 100% ect. Do not set below (NEED TO FIND LOWEST)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Properties")
	float Accuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Properties")
	int32 NumberOfProjectiles;

	//NOT IS USE AT THE MOMENT!
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Properties")
	float ProjectileSpread;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Properties")
	float RoundsPerSecond;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Properties")
	float ProjectileDamage;

//	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun")
//	UStaticMeshComponent* GunMesh;

//	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun")
//	UStaticMeshComponent* ProjectileSpawnPoint;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile")
	

//	UFUNCTION(BlueprintCallable, Category = "Gun")
//	void PullTrigger();

//	UFUNCTION(BlueprintCallable, Category = "Gun")
//	void ReleaseTrigger();

	UFUNCTION(BlueprintCallable, Category = "Gun")
	void Fire(AActor* Muzzle); //, AActor* ProjectileType);
	
	
};
