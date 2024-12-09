// Fill out your copyright notice in the Description page of Project Settings.


#include "I_SpellWidget.h"
#include "GameFramework/PlayerController.h"
#include "I_Player.h"
#include "I_GameMode.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"


void UI_SpellWidget::NativeConstruct()
{
	Super::NativeConstruct();
	buttonA->OnClicked.AddUniqueDynamic(this, &UI_SpellWidget::ClickSpellA);
	FTimerHandle _timerHandle;
	GetWorld()->GetTimerManager().SetTimer(_timerHandle, this, &UI_SpellWidget::PlayerInit, 0.2f);
}

void UI_SpellWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	TimerSpellA(InDeltaTime);
	CooldownSpellA(InDeltaTime);
}

void UI_SpellWidget::TimerSpellA(float _deltaTime)
{
	if (!spellActivationA) return;
	spellTimerA += _deltaTime;
	if (spellTimerA > spellDuractionA){
		if (startCooldownA)return;
		player->SupVitesseDeplacement(speedBonusA);
		imageA->SetColorAndOpacity(FLinearColor(0,0,0));
		spellTimerA = 0.0f;
		spellActivationA = false;
		startCooldownA = true;
	}
}

void UI_SpellWidget::CooldownSpellA(float _deltaTime)
{
	if (!startCooldownA) return;
	spellTimerA += _deltaTime;
	float _cooldown = spellCooldownA - spellTimerA;
	int32 _arrondie = FMath::CeilToInt(_cooldown);
	FString _textCooldown = FString::FromInt(_arrondie);
	textA->SetText(FText::FromString(_textCooldown));
	if (spellTimerA > spellCooldownA){
		spellTimerA = 0.0f;
		startCooldownA = false;
		imageA->SetColorAndOpacity(FLinearColor(1,1,1));
		textA->SetText(FText::FromString(""));
	}
	
}

void UI_SpellWidget::chargeMana()
{
	float _valeurActuel = player->GetMana();
	float _valeurMax = player->GetManaMax();
	float _valeurBarre = _valeurActuel / _valeurMax;
	manaBar->SetPercent(_valeurBarre);
}

void UI_SpellWidget::ClickSpellA()
{
	if (!player){return;}
	UE_LOG(LogTemp, Warning, TEXT("Click Spell A"));
	if (player->GetMana() > 200.0f)
	{
		if (spellActivationA || startCooldownA){return;}
		spellActivationA = true;
		player->SetMana(spellCostA);
		chargeMana();
		player->AddVitesseDeplacement(speedBonusA);
		imageA->SetColorAndOpacity(FLinearColor::Green);
	}
}

void UI_SpellWidget::PlayerInit()
{
	AI_GameMode* _gm = GetWorld()->GetAuthGameMode<AI_GameMode>();
	if (!_gm){return;}
	player = _gm->GetPlayer();
}
