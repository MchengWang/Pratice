// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDelegateActor.h"

// Sets default values
AMyDelegateActor::AMyDelegateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 单播代理绑定
	NoParamDelegate.BindUObject(this, &AMyDelegateActor::NoParamFunction);
	OneParamDelegate.BindUObject(this, &AMyDelegateActor::OneParamFunction);
	TwoParamDelegate.BindUObject(this, &AMyDelegateActor::TwoParamFunction);
	ThreeParamDelegate.BindUObject(this, &AMyDelegateActor::ThreeParamFunction);
	RevalDelegate.BindUObject(this, &AMyDelegateActor::RevalParamFunction);

	// 多播代理绑定
	OneParamMultiDelegate.AddUObject(this, &AMyDelegateActor::MultiDelegateFunction1);
	OneParamMultiDelegate.AddUObject(this, &AMyDelegateActor::MultiDelegateFunction2);
	OneParamMultiDelegate.AddUObject(this, &AMyDelegateActor::MultiDelegateFunction3);
}

// Called when the game starts or when spawned
void AMyDelegateActor::BeginPlay()
{
	Super::BeginPlay();

	// 使用单播代理
	NoParamDelegate.ExecuteIfBound();
	OneParamDelegate.ExecuteIfBound("OneParamDelegate");
	TwoParamDelegate.ExecuteIfBound("TwoParamDelegate", 10);
	ThreeParamDelegate.ExecuteIfBound("ThreeParamDelegate", 10, 0.5);
	FString strValue = RevalDelegate.Execute();
	
	// 使用多播代理
	OneParamMultiDelegate.Broadcast("OneParamMultiDelegate");

	// 使用动态多播代理
	DynamicMultiDelegate.Broadcast("DynamicMultiDelegate");
}

// Called every frame
void AMyDelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyDelegateActor::NoParamFunction()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("NoParamDelegate"));
}

void AMyDelegateActor::OneParamFunction(FString str)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("OneParamDelegate: %s"), *str));
}

void AMyDelegateActor::TwoParamFunction(FString str, int32 value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("TwoParamDelegate: %s, %d"), *str, value));
}

void AMyDelegateActor::ThreeParamFunction(FString str, int32 value, float value1)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("ThreeParamDelegate: %s, %d, %f"), *str, value, value1));
}

FString AMyDelegateActor::RevalParamFunction()
{
	FString str = TEXT("RevalParamFunction");
	return str;
}

void AMyDelegateActor::MultiDelegateFunction1(FString str)
{
	FString TmpStr = str.Append("1");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *TmpStr));
}

void AMyDelegateActor::MultiDelegateFunction2(FString str)
{
	FString TmpStr = str.Append("2");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *TmpStr));
}

void AMyDelegateActor::MultiDelegateFunction3(FString str)
{
	FString TmpStr = str.Append("3");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *TmpStr));
}
