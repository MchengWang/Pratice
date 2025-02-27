// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySoftActor.generated.h"

UCLASS()
class TESTPROJECT_API AMySoftActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySoftActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	FSoftObjectPath AssetObjectPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	FSoftClassPath AssetClassPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	TSoftObjectPtr<AActor> AssetObjectPtr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	TSoftClassPtr<AActor> AssetClassPtr;
};
