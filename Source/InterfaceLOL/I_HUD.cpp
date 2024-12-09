// Fill out your copyright notice in the Description page of Project Settings.

#include "I_PlayerController.h"
#include "I_SpellWidget.h"
#include "I_HUD.h"


void AI_HUD::BeginPlay()
{
	Super::BeginPlay();
	playerController = GetWorld()->GetFirstPlayerController<AI_PlayerController>();
	playerController->ShowCursor();
	
	ShowSpellWidget();
}

void AI_HUD::ShowSpellWidget()
{
	if (!playerController)return;
	spellWidget = CreateWidget<UI_SpellWidget>(playerController, spellWidgetToSpawn);
	if (!spellWidget)return;
	spellWidget->AddToViewport();
}
