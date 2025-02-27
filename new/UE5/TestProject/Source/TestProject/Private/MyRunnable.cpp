// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRunnable.h"
#include "HAL/ThreadSafeBool.h"
#include "MyGameInstanceSubsystem.h"

FMyRunnable::FMyRunnable()
{
	UE_LOG(LogTemp, Warning, TEXT("构造函数（无参）"));
}

FMyRunnable::FMyRunnable(FString InThreadName)
	:ThreadName(InThreadName)
{
	UE_LOG(LogTemp, Warning, TEXT("构造函数（有参）"));
}

FMyRunnable::~FMyRunnable()
{
	UE_LOG(LogTemp, Warning, TEXT("析构函数"));
}

bool FMyRunnable::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("initialize Thread"));
	return true;
}

uint32 FMyRunnable::Run()
{
	IsRunning = true;
	while (IsRunning)
	{
		FPlatformProcess::Sleep(3.0);
		UMyGameInstanceSubsystem* instance = UMyGameInstanceSubsystem::Get();
		if (instance)
		{
			UE_LOG(LogTemp, Warning, TEXT("Run Thread"));
		}
	}
	return uint32();
}

void FMyRunnable::Stop()
{
	IsRunning = false;
	UE_LOG(LogTemp, Warning, TEXT("Stop Thread"));
}

void FMyRunnable::Exit()
{
	UE_LOG(LogTemp, Warning, TEXT("Exit Thread"));
}
