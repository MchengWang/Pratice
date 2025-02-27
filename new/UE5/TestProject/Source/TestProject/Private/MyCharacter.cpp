// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MySpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpringArmComponent"));
	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCameraComponent"));
	MyWidgetHealth = CreateDefaultSubobject<UWidgetComponent>(TEXT("MyWidgetComponent"));

	MyWidgetHealth->SetupAttachment(RootComponent);
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UMG_Health.UMG_Health_C'"));
	MyWidgetHealth->SetWidgetClass(WidgetClass.Class);
	MyWidgetHealth->SetRelativeLocation(FVector(0, 0, 100));
	MyWidgetHealth->SetWidgetSpace(EWidgetSpace::Screen);
	MyWidgetHealth->SetDrawSize(FVector2D(400, 20));

	MySpringArm->TargetArmLength = 400.0f;
	MyCamera->SetupAttachment(MySpringArm);
	MySpringArm->SetupAttachment(RootComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	MySpringArm->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	Attack();
	CalculateHealth(); 

	GetWorld()->GetTimerManager().SetTimer(Time, this, &AMyCharacter::PrintF, 1.0, true);

	// 清除定时器
	if (Time.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(Time);
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	StartLocation = MyCamera->GetComponentLocation();
	ForwardVector = MyCamera->GetForwardVector();
	EndLocation = StartLocation + ForwardVector * 9999;
	//// 根据通道查询
	//bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);

	//if (bHit)
	//{
	//	AActor* HitActor = HitResult.GetActor();
	//	FVector ImpacePoint = HitResult.ImpactPoint;
	//	FVector HitLocation = HitResult.Location;
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *HitActor->GetName()));
	//}

	// 根据对象查询检测
	FCollisionObjectQueryParams objectType;
	objectType.AddObjectTypesToQuery(ECC_WorldDynamic);
	objectType.AddObjectTypesToQuery(ECC_WorldStatic);
	/*bool bHit2 = GetWorld()->LineTraceSingleByObjectType(HitResult, StartLocation, EndLocation, objectType);
	if (bHit2)
	{
		AActor* HitActor2 = HitResult.GetActor();
		FVector Impactpoint2 = HitResult.ImpactPoint;
		FVector HitLocation = HitResult.Location;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *HitActor2->GetName()));
	}*/

	// 根据多射线通道检测
	/*bool HitMulti = GetWorld()->LineTraceMultiByChannel(HitResults, StartLocation, EndLocation, ECC_Visibility);
	if (HitMulti)
	{
		for (int32 i = 0; i < HitResults.Num(); i++)
		{
			AActor* HitMultiActor = HitResults[i].GetActor();
			FVector HitLocation = HitResults[i].Location;
			FVector HitImpactpoint = HitResults[i].ImpactPoint;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *HitMultiActor->GetName()));
		}	
	}*/

	// 多射线对象查询检测
	bool HitMulti2 = GetWorld()->LineTraceMultiByObjectType(HitResults, StartLocation, EndLocation, objectType);
	if (HitMulti2)
	{
		for (int32 i = 0; i < HitResults.Num(); i++)
		{
			AActor* HitMultiActor2 = HitResults[i].GetActor();
			FVector HitLocation2 = HitResults[i].Location;
			FVector HitImpactpoint2 = HitResults[i].ImpactPoint;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *HitMultiActor2->GetName()));
		}
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
	}
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector ForwardDiretion = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDiretion = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(ForwardDiretion, MovementVector.Y);
		AddMovementInput(RightDiretion, MovementVector.X);
	}
}

void AMyCharacter::Look(const FInputActionValue& Value)
{
	FVector2D lookAxisVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(lookAxisVector.Y);
	}
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UMyHealthWidget* MyWidget = Cast<UMyHealthWidget>(MyWidgetHealth->GetUserWidgetObject());
	if (MyWidget)
	{
		if (MyWidget->CurrentHealth <= 0)
		{
			return 0.0f;
		}

		MyWidget->CurrentHealth -= 5.0f;
	}
	return 0.0f;
}

void AMyCharacter::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Attack"));
}

void AMyCharacter::CalculateHealth()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("CalculateHealth"));
}

void AMyCharacter::PrintF()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Time"));
}

