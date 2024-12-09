// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"
#include "I_HUD.generated.h"

class AI_PlayerController;
class UI_SpellWidget;

UCLASS()
class INTERFACELOL_API AI_HUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY() AI_PlayerController* playerController = nullptr;

	UPROPERTY(EditAnywhere) TSubclassOf<UUserWidget> spellWidgetToSpawn;
	UPROPERTY(EditAnywhere) UI_SpellWidget* spellWidget;

	virtual void BeginPlay() override;

	void ShowSpellWidget();
};
