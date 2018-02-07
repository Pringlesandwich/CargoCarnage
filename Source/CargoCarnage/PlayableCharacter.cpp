// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayableCharacter.h"



const FName APlayableCharacter::MoveUpBinding("MoveUp");
const FName APlayableCharacter::MoveRightBinding("MoveRight");
const FName APlayableCharacter::LookUpBinding("LookUp");
const FName APlayableCharacter::LookRightBinding("LookRight");




//TODO - MAJOR PROBLEM - DEFAULT ROOT COMPONENT IS BEING CREATED AND IS NOT CAPSUL COMPONENT!!!!!!!!!!!!!!!!!!!







// Sets default values
APlayableCharacter::APlayableCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


//	PlayerRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PlayerRoot"));
//	RootComponent = PlayerRoot;

	//PlayerMesh->AttachTo(GetRootComponent());

	//USceneComponent * DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	//SetRootComponent(PlayerMesh);
	
//	GunTemp = CreateDefaultSubobject<UArrowComponent>(TEXT("GunTemp"));
//	GunTemp->AttachTo(GetCapsuleComponent());
	
}

void APlayableCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	
	check(PlayerInputComponent);
/*
	PlayerInputComponent->BindAxis("MoveUp", this, &APlayableCharacter::MoveUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayableCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp");
	PlayerInputComponent->BindAxis("LookRight");
	*/
	PlayerInputComponent->BindAxis("MoveUp", this, &APlayableCharacter::MoveUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayableCharacter::MoveRight);

	//PlayerInputComponent->BindAxis(MoveUpBinding);
	//PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(LookUpBinding);
	PlayerInputComponent->BindAxis(LookRightBinding);


	//TODO

	//add input "Space" to trigger fire() in Gun
	//PlayerInputComponent->BindAction("Fire", IE_Pressed, )

		//IE_Pressed, this, &APawnWithCamera::ZoomIn);




}


void APlayableCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("We are using PlayableCharacter!"));
	}


	//THIS IS CURRENTLY BEING DONE IN BLUEPRINTS!!!!
/*
	UWorld * World = GetWorld();
	if (World)
	{

		FTransform WeaponSpawnPoint = this->GetTransform();
		Gun = World->SpawnActor<AGun>(WeaponSpawnPoint.GetLocation(), WeaponSpawnPoint.GetRotation().Rotator());
		Gun->AttachRootComponentTo(GetMesh());


	}

*/



}


void APlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	const float LookUpValue = GetInputAxisValue(LookUpBinding);
	const float LookRightValue = GetInputAxisValue(LookRightBinding);
	
	
	//bool that then detects controller movement
	bool bIsLooking = false;
	//if (InputComponent->GetAxisValue("LookUp") > 0.4 || InputComponent->GetAxisValue("LookUp") < -0.4 || InputComponent->GetAxisValue("LookRight") > 0.4 || InputComponent->GetAxisValue("LookRight") < -0.4)
	if(LookUpValue > 0.4 || LookUpValue < -0.4 || LookRightValue > 0.4 || LookRightValue < -0.4)
	{
		bIsLooking = true;
	}
	else
	{
		bIsLooking = false;
	}



	if (bIsLooking)
	{


		//TODO - this can be shrunk to one line, keeping for testing
		//create a FVector dependent on look axis input
		float XValue = LookUpValue;
		float YValue = LookRightValue;
		direction = FVector(XValue, YValue, 0.0f);


	//	UE_LOG(LogTemp, Warning, TEXT("Look Axis FVector: %f , %f"), XValue, YValue);

	}

	//Convert Vector to Quarternion
	Quat = direction.ToOrientationQuat();

	//set rotation of Player
	SetActorRotation(Quat);

	
	
}



void APlayableCharacter::MoveUp(float Value)
{
	if(Controller != NULL)
	this->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void APlayableCharacter::MoveRight(float Value)
{
	if (Controller != NULL)
	this->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
}
