// Fill out your copyright notice in the Description page of Project Settings.


#include "MyelegateActor.h"

// Sets default values
AMyelegateActor::AMyelegateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyelegateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

