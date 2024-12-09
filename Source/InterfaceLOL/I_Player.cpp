// Fill out your copyright notice in the Description page of Project Settings.


#include "I_Player.h"
#include "I_GameMode.h"

// Sets default values
AI_Player::AI_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AI_Player::BeginPlay()
{
	Super::BeginPlay();
	AI_GameMode* _gameMode = GetWorld()->GetAuthGameMode<AI_GameMode>();
	if (_gameMode){_gameMode->SetPlayerTest(this);}
	AddMappingContext();
}

// Called every frame
void AI_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AI_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	enhancedInputComponent->BindAction(inputVertical, ETriggerEvent::Triggered, this, &AI_Player::PlayerMoveVertical);
	enhancedInputComponent->BindAction(inputHorizontal, ETriggerEvent::Triggered, this, &AI_Player::PlayerMoveHorizontal);
}

void AI_Player::AddMappingContext()
{
	APlayerController* _playerController = GetWorld()->GetFirstPlayerController();
	if (_playerController == nullptr) { return; }

	ULocalPlayer* _localPlayer = _playerController->GetLocalPlayer();
	if (_localPlayer == nullptr) { return; }

	UEnhancedInputLocalPlayerSubsystem* _system = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (_system == nullptr) { return; }

	_system->AddMappingContext(mappingContext, 0);
}

void AI_Player::PlayerMoveVertical(const FInputActionValue& _value)
{
	float _axisValue = _value.Get<float>();
	AddActorWorldOffset(GetActorForwardVector() * GetWorld()->GetDeltaSeconds() * vitesseDeplacement * _axisValue);
}

void AI_Player::PlayerMoveHorizontal(const FInputActionValue& _value)
{
	float _axisValue = _value.Get<float>();
	AddActorWorldOffset( GetActorRightVector() * GetWorld()->GetDeltaSeconds() * vitesseDeplacement * _axisValue);
}

