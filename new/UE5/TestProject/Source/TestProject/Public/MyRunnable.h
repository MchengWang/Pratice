// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"


/**
 *
 */
class TESTPROJECT_API FMyRunnable : public FRunnable
{
public:
	FMyRunnable();
	FMyRunnable(FString InThreadName);
	~FMyRunnable();

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual void Exit() override;
	FString ThreadName;

private:
	bool IsRunning;
};
