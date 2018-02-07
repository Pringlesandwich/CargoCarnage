// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Gun.h"
#include "BaseCharacter.h"
#include "GameFramework/Character.h" //possibly???????????????????????????
#include "PlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CARGOCARNAGE_API APlayableCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	APlayableCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Static names for axis bindings
	static const FName MoveUpBinding;
	static const FName MoveRightBinding;
	static const FName LookUpBinding;
	static const FName LookRightBinding;

//	UPROPERTY(EditAnywhere)
//	USceneComponent* PlayerRoot;

//	UPROPERTY(EditAnywhere)
//	UStaticMeshComponent * PlayerMesh;

//	UPROPERTY(EditAnywhere)
//	UArrowComponent* GunTemp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	AGun * Gun;

	UPROPERTY()
	FQuat Quat;

	UPROPERTY()
	FVector direction;

	UFUNCTION()
	void MoveUp(float Value);

	UFUNCTION()
	void MoveRight(float Value);
	
};
