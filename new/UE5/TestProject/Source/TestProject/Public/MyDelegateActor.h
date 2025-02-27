// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDelegateActor.generated.h"

// 单播代理
DECLARE_DELEGATE(NoParamDelegate);
DECLARE_DELEGATE_OneParam(OneParamDelegate, FString);
DECLARE_DELEGATE_TwoParams(TwoParamDelegate, FString, int32);
DECLARE_DELEGATE_ThreeParams(ThreeParamDelegate, FString, int32, float);
DECLARE_DELEGATE_RetVal(FString, RevalDelegate);

// 多播代理
DECLARE_MULTICAST_DELEGATE_OneParam(OneParamMultiDelegate, FString);

// 动态多播代理 (可在蓝图中进行事件的绑定)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicMultiDelegate, FString, param);

UCLASS()
class TESTPROJECT_API AMyDelegateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDelegateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 单播代理声明
	NoParamDelegate NoParamDelegate;
	OneParamDelegate OneParamDelegate;
	TwoParamDelegate TwoParamDelegate;
	ThreeParamDelegate ThreeParamDelegate;
	RevalDelegate RevalDelegate;

	// 代理绑定函数
	UFUNCTION()
	void MultiDelegateFunction1(FString str);
	UFUNCTION()
	void MultiDelegateFunction2(FString str);
	UFUNCTION()
	void MultiDelegateFunction3(FString str);

	void NoParamFunction();
	void OneParamFunction(FString str);
	void TwoParamFunction(FString str, int32 value);
	void ThreeParamFunction(FString str, int32 value, float value1);
	FString RevalParamFunction();

	// 多播代理声明
	OneParamMultiDelegate OneParamMultiDelegate;

	// 多播动态代理声明
	UPROPERTY(BlueprintAssignable)
	FDynamicMultiDelegate DynamicMultiDelegate;
};
