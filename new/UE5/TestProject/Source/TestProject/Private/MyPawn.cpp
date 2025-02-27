// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MyRootComponent"));
	MySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArmComponent"));
	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCameraComponent"));

	RootComponent = MyRoot;
	MySpringArm->SetupAttachment(MyRoot);
	MyCamera->SetupAttachment(MySpringArm);
	MySpringArm->bDoCollisionTest = false;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	TSubclassOf<UMyObject> MySubClassObject = UMyObject::StaticClass();
	MyTestObject = NewObject<UMyObject>(GetWorld(), MySubClassObject);
	if (MyTestObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("MyTestObject is %s"), *MyTestObject->GetName());
		UE_LOG(LogTemp, Warning, TEXT("My Health is %f"), MyTestObject->MyDataTableStruct.Health);
		UE_LOG(LogTemp, Warning, TEXT("My Name is %s"), *MyTestObject->MyDataTableStruct.Name);
		UE_LOG(LogTemp, Warning, TEXT("My Level is %d"), MyTestObject->MyDataTableStruct.Level);
	}

	MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetFirstPlayerController()->GetGameInstance());
	if (MyGameInstance)
	{
		UE_LOG(LogTemp, Warning, TEXT("MyInstance is %s"), *MyGameInstance->GetName());
		UE_LOG(LogTemp, Warning, TEXT("MyAppID is %s"), *MyGameInstance->MyAPPID);
		UE_LOG(LogTemp, Warning, TEXT("MyUserID is %s"), *MyGameInstance->MyUserID);
		UE_LOG(LogTemp, Warning, TEXT("MyName is %s"), *MyGameInstance->MyName);
	}

	FVector Location = FVector(0.5, 0.5, 0.5);
	FRotator Rotator = FRotator(-50, 0, 0);
	FVector Scale = FVector(1, 1, 1);
	SetActorLocation(Location);
	SetActorRotation(Rotator);
	SetActorScale3D(Scale);
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void AMyPawn::PrintF1()
//{
//
//}
//
//bool AMyPawn::PrintF2()
//{
//	return false;
//}
//
//void AMyPawn::TestA_Implementation()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("TestA"));
//}
//
//int AMyPawn::TestB_Implementation()
//{
//	return 0;
//}
//
//void AMyPawn::TestC_Implementation(const FString& MyString)
//{
//
//}
//
//int AMyPawn::TestD_Implementation(const FString& MyString)
//{
//	return 0;
//}
//
//void AMyPawn::Printtest()
//{
//
//}

void AMyPawn::Zoom(bool Direction, float ZoomSpeed)
{
	if (Direction)
	{
		if (MySpringArm->TargetArmLength >= 300 && MySpringArm->TargetArmLength < 5000)
		{
			MySpringArm->TargetArmLength += (ZoomSpeed * 2);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ArmLength is %f"), MySpringArm->TargetArmLength));
			UE_LOG(LogTemp, Warning, TEXT("SSSS"));
		}
	}
	else
	{
		if (MySpringArm->TargetArmLength >= 300 && MySpringArm->TargetArmLength <= 5000)
		{
			MySpringArm->TargetArmLength -= (ZoomSpeed * 2);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("ArmLength is %f"), MySpringArm->TargetArmLength));

		}
	}
	
}