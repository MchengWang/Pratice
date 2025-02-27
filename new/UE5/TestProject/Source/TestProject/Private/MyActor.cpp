// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyScene = CreateDefaultSubobject<USceneComponent>(TEXT("MyCustomScene"));
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyCustomStaticMesh"));
	MyParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MyCustomParticleSystem"));
	MyBox = CreateDefaultSubobject<UBoxComponent>(TEXT("MyCustomBox"));
	MyAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("MyCustomAudio"));

	// 设置父子关系
	RootComponent = MyScene;
	MyStaticMesh->SetupAttachment(MyScene);
	MyParticleSystem->SetupAttachment(MyScene);
	MyBox->SetupAttachment(MyScene);
	MyAudio->SetupAttachment(MyBox);

	// 静态加载资源
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TempStaticMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	MyStaticMesh->SetStaticMesh(TempStaticMesh.Object);
	static ConstructorHelpers::FObjectFinder<UParticleSystem> TempParticleSystem(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	MyParticleSystem->SetTemplate(TempParticleSystem.Object);
	static ConstructorHelpers::FObjectFinder<USoundWave> TempSound(TEXT("/Script/Engine.SoundWave'/Game/StarterContent/Audio/Collapse01.Collapse01'"));
	MyAudio->SetSound(TempSound.Object);

	// 静态加载类
	static ConstructorHelpers::FClassFinder<AActor> TempMyActor(TEXT("/Script/Engine.Blueprint'/Game/StarterContent/Blueprints/Blueprint_CeilingLight.Blueprint_CeilingLight_C'"));
	MyActor = TempMyActor.Class;

	// 碰撞设置
	//MyBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MyBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//MyBox->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	//MyBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//MyBox->SetCollisionEnabled(ECollisionEnabled::ProbeOnly);
	//MyBox->SetCollisionEnabled(ECollisionEnabled::QueryAndProbe);

	// 碰撞对象类型
	//MyBox->SetCollisionObjectType(ECC_WorldStatic); 
	MyBox->SetCollisionObjectType(ECC_WorldDynamic);
	//MyBox->SetCollisionObjectType(ECC_Pawn);
	//MyBox->SetCollisionObjectType(ECC_PhysicsBody);
	//MyBox->SetCollisionObjectType(ECC_Vehicle);
	//MyBox->SetCollisionObjectType(ECC_Destructible);
	
	// 碰撞响应
	//MyBox->SetCollisionResponseToAllChannels(ECR_Block);
	MyBox->SetCollisionResponseToAllChannels(ECR_Overlap);
	//MyBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	//MyBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	//MyBox->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	//MyBox->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Ignore);

	// 设置 Box 的大小
	MyBox->SetBoxExtent(FVector(64, 64, 64));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// 如果粒子系统在开始创建时就生效，则将其失效
	if (MyParticleSystem)
	{
		MyParticleSystem->Deactivate();
	}

	if (MyActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("MyActor is %s"), *MyActor->GetName());
	}

	// 动态加载资源
	UStaticMesh* MyTempStaticMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MyTempStaticMesh)
	{
		MyStaticMesh->SetStaticMesh(MyTempStaticMesh);
	}
	
	// 动态加载类资源
	UClass* MyTempClass = LoadClass<AActor>(this, TEXT("/Script/Engine.Blueprint'/Game/StarterContent/Blueprints/Blueprint_WallSconce.Blueprint_WallSconce_C'"));
	if (MyTempClass)
	{
		AActor* SpawnActor = GetWorld()->SpawnActor<AActor>(MyTempClass, FVector::ZeroVector, FRotator::ZeroRotator);
	}

	MyBox->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::BeginOverlapFunction);
	MyBox->OnComponentEndOverlap.AddDynamic(this, &AMyActor::EndOverlapFunction);
	MyBox->OnComponentHit.AddDynamic(this, &AMyActor::HitFunction);
}

// Called every frame 
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector MyOffset = FVector(1 ,0 , 0);
	FHitResult HitResult;
	AddActorLocalOffset(MyOffset, false, &HitResult);
	//AddActorWorldOffset(MyOffset, false, &HitResult);
}

void AMyActor::BeginOverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{ 
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
	if (MyCharacter)
	{
		UGameplayStatics::ApplyDamage(MyCharacter, 5.0f, nullptr, this, UDamageType::StaticClass());
	}

	// 开启粒子系统
	MyParticleSystem->Activate();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Begin Over lap Event is success!"));
	//Destroy();
	MyParticleSystem->DestroyComponent();
}

void AMyActor::EndOverlapFunction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// 关闭粒子系统
	MyParticleSystem->Deactivate();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("End Over lap Event is success!"));
}

void AMyActor::HitFunction(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("HitFuction is triggered!"));
}