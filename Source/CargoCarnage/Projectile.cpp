// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{

	/*

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent * DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SetRootComponent(DefaultSceneRoot);

	ProjectileCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	ProjectileCollision->InitSphereRadius(1.0f);
	ProjectileCollision->AttachTo(GetRootComponent());
	ProjectileCollision->SetCollisionProfileName(TEXT("NoCollision"));

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
	ProjectileMesh->AttachTo(GetRootComponent());

	ProjectileCollision->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnBeginOverlap);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->SetUpdatedComponent(GetRootComponent());
	ProjectileMovement->InitialSpeed = fProjectileSpeed;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	*/

	Damage = -20;
	InitialLifeSpan = 600.0f;


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*

void AProjectile::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{

		/*
		IiDamageable * damageable = Cast<IiDamageable>(OtherActor);
		if (damageable && !OtherActor->Tags.Contains(TEXT("Friendly"))) {
			IiDamageable::Execute_AffectHealth(damageable->_getUObject(), this->Damage); //This way works for c++ and blueprints
		}

		*/
		//Destroy();

	

	


//}

