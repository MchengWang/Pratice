// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyMaterialActor.generated.h"

UCLASS()
class TESTPROJECT_API AMyMaterialActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyMaterialActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* 场景组件 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
	class USceneComponent* MyScene;

	/* 静态网格组件 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
	class UStaticMeshComponent* MyStaticMesh;

	UMaterialInstanceDynamic* DynamicMaterial;

	UFUNCTION()
	void DelayFunctionFinish();
};
