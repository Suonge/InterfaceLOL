// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "I_Player.h"
#include "GameFramework/GameModeBase.h"
#include "I_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class INTERFACELOL_API AI_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY() AI_Player* player = nullptr;
	
public:
	FORCEINLINE void SetPlayer(AI_Player* _player) { this->player = _player; }
	FORCEINLINE AI_Player* GetPlayer() { return player; }
	void SetPlayerTest(AI_Player* _player);
};
