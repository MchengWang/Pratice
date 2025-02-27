// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTimelineActor.h"

// Sets default values
AMyTimelineActor::AMyTimelineActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("MyTimelineComponent"));

	MyScene = CreateDefaultSubobject<USceneComponent>(TEXT("MySceneComponent"));
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMeshComponent"));
	MyBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> TmpStaticMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Architecture/Wall_400x400.Wall_400x400'"));
	if (TmpStaticMesh.Succeeded())
	{
		MyStaticMesh->SetStaticMesh(TmpStaticMesh.Object);
	}

	RootComponent = MyScene;
	MyStaticMesh->SetupAttachment(MyScene);
	MyBox->SetupAttachment(MyScene);
	MyBox->SetBoxExtent(FVector(200, 100, 100));
	MyBox->SetRelativeLocation(FVector(200, 0, 0));
}

// Called when the game starts or when spawned
void AMyTimelineActor::BeginPlay()
{
	Super::BeginPlay();
	
	TimelineDelegate.BindUFunction(this, TEXT("TimelineStart"));
	TimelineFinishedDelegate.BindUFunction(this, TEXT("TimelineFinished"));

	MyTimeline->AddInterpFloat(MyCurveFloat, TimelineDelegate);
	/*MyTimeline->SetLooping(false);
	MyTimeline->PlayFromStart();
	MyTimeline->Play();*/
	MyTimeline->SetTimelineFinishedFunc(TimelineFinishedDelegate);
	
	MyBox->OnComponentBeginOverlap.AddDynamic(this, &AMyTimelineActor::BeginOverlapFunction);
	MyBox->OnComponentEndOverlap.AddDynamic(this, &AMyTimelineActor::EndOverlapFunction);
}

// Called every frame
void AMyTimelineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTimelineActor::TimelineStart(float value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Timeline start"));
	float YawRotation = FMath::Lerp(0, 90, value);
	MyStaticMesh->SetRelativeRotation(FRotator(0, YawRotation, 0));
}

void AMyTimelineActor::TimelineFinished()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Timeline finished"));
}

void AMyTimelineActor::BeginOverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyCharacter* TmpCharacter = Cast<AMyCharacter>(OtherActor);
	if (TmpCharacter)
	{
		MyTimeline->PlayFromStart();
	}
}

void AMyTimelineActor::EndOverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMyCharacter* TmpCharacter = Cast<AMyCharacter>(OtherActor);
	if (TmpCharacter)
	{
		MyTimeline->ReverseFromEnd();
	}
}

