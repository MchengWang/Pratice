// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "MyTimelineActor.generated.h"

UCLASS()
class TESTPROJECT_API AMyTimelineActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyTimelineActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCurve")
	UCurveFloat* MyCurveFloat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCurve")
	UTimelineComponent* MyTimeline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCurve")
	USceneComponent* MyScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCurve")
	UStaticMeshComponent* MyStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCurve")
	UBoxComponent* MyBox;

	FOnTimelineFloat TimelineDelegate;
	FOnTimelineEvent TimelineFinishedDelegate;

	UFUNCTION()
	void TimelineStart(float value);

	UFUNCTION()
	void TimelineFinished();

	UFUNCTION()
	void BeginOverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EndOverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};