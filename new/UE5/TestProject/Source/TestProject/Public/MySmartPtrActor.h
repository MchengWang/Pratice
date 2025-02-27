// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySmartPtrActor.generated.h"

class A
{
public:
	A() : a(0), b(0.3f){}
	A(int a, float b) : a(a), b(b){}
	~A()
	{
		UE_LOG(LogTemp, Warning, TEXT("DeConstructor-A"));
	}

	int a = 0;
	float b = 0.4f;
};

UCLASS()
class TESTPROJECT_API AMySmartPtrActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMySmartPtrActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TestAFunction();
	void TestBFunction();
	void TestCFunction();
};
