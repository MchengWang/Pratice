// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayerController.h"
#include "MyPawn.h"
#include "MyGameState.h"
#include "MyPlayerState.h"
#include "MyHUD.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	AMyGameMode();

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	void PrintF();
	void PrintMap();

public:
	TArray<int32> MyArray;
	TMap<int32, int32> MyMap;
};
