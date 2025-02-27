// Fill out your copyright notice in the Description page of Project Settings.


#include "MySoftActor.h"
#include "UObject/SoftObjectPath.h"
#include "UObject/SoftObjectPtr.h"
#include "Engine/AssetManager.h"

// Sets default values
AMySoftActor::AMySoftActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMySoftActor::BeginPlay()
{
	Super::BeginPlay();

	// Õ¨≤Ωº”‘ÿ 
	/*FSoftObjectPath Path1 = FString(TEXT("/Script/Engine.Texture2D'/Game/StarterContent/Textures/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'"));
	TSharedPtr<FStreamableHandle> SyncStreamhandle = UAssetManager::GetStreamableManager().RequestAsyncLoad(Path1);
	if (SyncStreamhandle)
	{
		UTexture2D* Image1 = Cast<UTexture2D>(SyncStreamhandle->GetLoadedAsset());
		if (Image1)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *Image1->GetName()));
		}
	}*/

	FSoftObjectPath Path2 = FString(TEXT("/Script/Engine.Texture2D'/Game/StarterContent/Textures/T_Brick_Clay_Beveled_M.T_Brick_Clay_Beveled_M'"));
	TSharedPtr<FStreamableHandle> AsyncStreamhandle = UAssetManager::GetStreamableManager().RequestSyncLoad(Path2);
	if (AsyncStreamhandle)
	{
		UTexture2D* Image2 = Cast<UTexture2D>(AsyncStreamhandle->GetLoadedAsset());
		if (Image2)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *Image2->GetName()));
		}
	}
}

// Called every frame
void AMySoftActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

