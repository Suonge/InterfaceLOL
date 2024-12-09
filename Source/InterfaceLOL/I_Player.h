// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


#include "I_Player.generated.h"

UCLASS()
class INTERFACELOL_API AI_Player : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere) UInputMappingContext* mappingContext = nullptr;
	UPROPERTY(EditAnywhere) UInputAction* inputVertical = nullptr;
	UPROPERTY(EditAnywhere) UInputAction* inputHorizontal = nullptr;

	UPROPERTY() UEnhancedInputComponent* enhancedInputComponent = nullptr;
	
	UPROPERTY(EditAnywhere) float vitesseDeplacement = 100.0f;
	UPROPERTY(EditAnywhere) float mana = 2000.0f;
	UPROPERTY(EditAnywhere) float manaMax = 2000.0f;
	

public:
	AI_Player();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AddMappingContext();
	
	UFUNCTION() void PlayerMoveVertical (const FInputActionValue& _value);
	UFUNCTION() void PlayerMoveHorizontal (const FInputActionValue& _value);

public:
	FORCEINLINE void AddVitesseDeplacement(float _vitesse){vitesseDeplacement += _vitesse;}
	FORCEINLINE void SupVitesseDeplacement(float _vitesse){vitesseDeplacement -= _vitesse;}
	FORCEINLINE float GetVitesseDeplacemnt(){return vitesseDeplacement;}
	FORCEINLINE void SetMana(float _mana){mana -= _mana;}
	FORCEINLINE float GetMana(){return mana;}
	FORCEINLINE float GetManaMax(){return manaMax;}
};
