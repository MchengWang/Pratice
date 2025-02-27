// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
	PlayerStateClass = AMyPlayerState::StaticClass();
	HUDClass = AMyHUD::StaticClass();
	GameStateClass = AMyGameState::StaticClass();
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();

	// 在集合中添加元素
	/*MyArray.Add(10);
	MyArray.Add(20);
	MyArray.Add(30);
	MyArray.AddUnique(50);

	PrintF();*/

	/*MyMap.Emplace(0, 1);
	MyMap.Emplace(1, 2);
	MyMap.Emplace(2, 3);
	PrintMap();*/

	int32 MyInt = 10;
	float MyFloat = 10.02f;
	bool MyBool = true;
	//char MyChar = 'A';
	FString MyString = TEXT("MyString");
	FVector MyVector = FVector(1, 1, 1);
	UE_LOG(LogTemp, Warning, TEXT("%d"), MyInt);
	UE_LOG(LogTemp, Warning, TEXT("%f"), MyFloat);
	UE_LOG(LogTemp, Warning, TEXT("%d"), MyBool);
	//UE_LOG(LogTemp, Warning, TEXT("%c"), MyChar);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *MyString);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *MyVector.ToString());
}

void AMyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AMyGameMode::PrintF()
{
	for (auto it = MyArray.CreateConstIterator(); it; it++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), *it);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("%d"), *it));
	}
}

void AMyGameMode::PrintMap()
{
	for (auto& key : MyMap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Key : %d, Vaule : %d"), key.Key, key.Value));
		UE_LOG(LogTemp, Warning, TEXT("Key : %d, Value : %d"), key.Key, key.Value);
	}
}
