// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "I_SpellWidget.generated.h"

class AI_HUD;

UCLASS()
class INTERFACELOL_API UI_SpellWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget)) UButton* buttonA;
	UPROPERTY(meta = (BindWidget)) UImage* imageA;
	UPROPERTY(meta = (BindWidget)) UTextBlock* textA;
	UPROPERTY(meta = (BindWidget)) UProgressBar* manaBar;
	UPROPERTY(EditAnywhere) class AI_Player* player = nullptr;

	UPROPERTY() bool spellActivationA = false;
	UPROPERTY() bool startCooldownA = false;
	UPROPERTY() float spellTimerA = 0.0f;
	UPROPERTY() float spellCostA = 500.0f;
	UPROPERTY(EditAnywhere) float speedBonusA = 400.0f;
	UPROPERTY(EditAnywhere) float spellDuractionA = 5.0f;
	UPROPERTY(EditAnywhere) float spellCooldownA = 10.0f;
	
private:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	void TimerSpellA(float _deltaTime);
	void CooldownSpellA(float _deltaTime);
	void chargeMana();
public:
	UFUNCTION() void ClickSpellA();
	UFUNCTION() void PlayerInit();
};
