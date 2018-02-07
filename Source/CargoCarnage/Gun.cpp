// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "TimerManager.h"
#include "Projectile.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


//	USceneComponent * DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
//	SetRootComponent(DefaultSceneRoot);

	//GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	//GunMesh->AttachTo(GetRootComponent());
	
	//ProjectileSpawnPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileSpawnPoint"));
	//ProjectileSpawnPoint->AttachTo(GunMesh);

	DoOnceFlag = true;

	//set default gun properties
	IsAutomatic = true;
	ProjectileVelocity = 1500;
	Accuracy = 100.0f;
	NumberOfProjectiles = 1;
	ProjectileSpread = 0.0f;
	RoundsPerSecond = 5.0f;
	ProjectileDamage = 20.0f;


}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*

void AGun::PullTrigger()
{
	if (DoOnceFlag) {
		Fire();
		GetWorldTimerManager().SetTimer(TriggerTimerHandler, this, &AGun::Fire, 1.0f / this->RoundsPerSecond, true);
		DoOnceFlag = false;
	}
}

void AGun::ReleaseTrigger()
{
	GetWorldTimerManager().ClearTimer(TriggerTimerHandler);
	DoOnceFlag = true;
}


*/

void AGun::Fire(AActor* Muzzle) //, AActor* ProjectileType)
{

	//TODO - do I need to reference a projectile_BP or just build the projectile well enough?

	UWorld* const World = GetWorld();
	if (World) {

//		for (int a = 0, a = > NumberOfProjectiles, a + 1)
//		{

		FTransform SpawnPoint; // = (0.0f, 0.0f, 0.0f); //Muzzle->GetComponentTransform();

		//World->SpawnActor<ProjectileBruv>(SpawnPoint.GetLocation(), SpawnPoint.GetRotation().Rotator());

		AActor* NewProjectile = World->SpawnActor <AProjectile>(SpawnPoint.GetLocation(), SpawnPoint.GetRotation().Rotator());


//		}


	}

	
}

