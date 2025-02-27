// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyRunnable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;

	static UMyGameInstanceSubsystem* myInstanceSubsystem;

	UFUNCTION(BlueprintCallable, Category = "MyTestSubsystem")
	static UMyGameInstanceSubsystem* Get();

	UFUNCTION(BlueprintCallable, Category = "MyTestSubsystem")
	void StartThread();

	UFUNCTION(BlueprintCallable, Category = "MyTestSubsystem")
	void StopThread();

protected:
	TSharedPtr<FMyRunnable> myRunnable;
	FRunnableThread* myRunnableThread;
};
