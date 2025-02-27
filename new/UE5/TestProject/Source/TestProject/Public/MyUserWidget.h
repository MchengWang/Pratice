// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UPROPERTY(meta = (BindWidget))
	UButton* ButtonStart;

	UPROPERTY(meta = (BindWidget))
	UButton* ButtonQuit;

	// ½ø¶ÈÌõ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyHealth")
	float CurrentHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyHealth")
	float MaxHealth = 100.0f;
	
public:
	virtual bool Initialize() override;

	void UpdateHealth();

	UFUNCTION()
	void Start();

	UFUNCTION()
	void Quit();
};
