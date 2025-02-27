// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMaterialActor.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMyMaterialActor::AMyMaterialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyScene = CreateDefaultSubobject<USceneComponent>(TEXT("MyCustomScene"));
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyCustomStaticMesh"));

	RootComponent = MyScene;
	MyStaticMesh->SetupAttachment(MyScene);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> TempStaticMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	MyStaticMesh->SetStaticMesh(TempStaticMesh.Object);
}

// Called when the game starts or when spawned
void AMyMaterialActor::BeginPlay()
{
	Super::BeginPlay();
	
	UMaterialInterface* Material = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/Game/M_Material.M_Material'"));
	DynamicMaterial = MyStaticMesh->CreateDynamicMaterialInstance(0, Material);
	DynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor::Red);
	DynamicMaterial->SetScalarParameterValue("BaseMetallic", 1);

	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("DelayFunctionFinish"), this);
	UKismetSystemLibrary::Delay(this, 1.0f, LatentInfo);
}

// Called every frame
void AMyMaterialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyMaterialActor::DelayFunctionFinish()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Delay Finished!"));
}

