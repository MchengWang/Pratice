// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"

UMyGameInstanceSubsystem* UMyGameInstanceSubsystem::myInstanceSubsystem = nullptr;

bool UMyGameInstanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UMyGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	myInstanceSubsystem = this;
	UE_LOG(LogTemp, Warning, TEXT("Initialize MyGameInstanceSubsystems"));
}

void UMyGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Warning, TEXT("Deinitialize MyGameInstanceSubsystems"));
}

UMyGameInstanceSubsystem* UMyGameInstanceSubsystem::Get() 
{
	return myInstanceSubsystem;
}

void UMyGameInstanceSubsystem::StartThread()
{
	myRunnable = MakeShared<FMyRunnable>(TEXT("MyRunnable"));
	myRunnableThread = FRunnableThread::Create(myRunnable.Get(), *(myRunnable->ThreadName));
	UE_LOG(LogTemp, Warning, TEXT("StartThread MyGameInstanceSubsystems"));
}

void UMyGameInstanceSubsystem::StopThread()
{
	if (myRunnable.IsValid())
	{
		myRunnable->Stop();
	}

	if (myRunnableThread)
	{
		myRunnableThread->WaitForCompletion();
		delete myRunnableThread;
		myRunnableThread = nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("EndThread MyGameInstanceSubsystems"));
}
