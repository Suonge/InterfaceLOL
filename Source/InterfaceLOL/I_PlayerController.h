// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "I_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INTERFACELOL_API AI_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void ShowCursor();
	void HideCursor();
};
