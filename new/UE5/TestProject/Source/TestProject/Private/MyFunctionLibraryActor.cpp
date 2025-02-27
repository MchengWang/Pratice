// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFunctionLibraryActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyFunctionLibraryActor::AMyFunctionLibraryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance  if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyFunctionLibraryActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFunctionLibraryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<AActor*> OutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), OutActors);
	for (int32 i = 0; i < OutActors.Num(); i++)
		UE_LOG(LogTemp, Warning, TEXT("Actor is %s"), *OutActors[i]->GetName());

}

void AMyFunctionLibraryActor::MyOpenLevel()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("ThirdPersonMap"));
}

void AMyFunctionLibraryActor::MyCurrentLevelName()
{
	FString MyCurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *MyCurrentLevelName));
}

void AMyFunctionLibraryActor::MyQuitName()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->ConsoleCommand("quit");
}

