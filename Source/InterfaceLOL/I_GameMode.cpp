// Fill out your copyright notice in the Description page of Project Settings.


#include "I_GameMode.h"

void AI_GameMode::SetPlayerTest(AI_Player* _player)
{
	UE_LOG(LogTemp, Warning, TEXT("AI_GameMode::SetPlayerTest"));
	player = _player;
}
