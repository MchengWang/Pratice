// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyObject.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyGameInstance.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UENUM(BlueprintType)
namespace MyEnumType
{
	enum MyCustomEnum
	{
		Type1,
		Type2,
		Type3
	};
}

USTRUCT(BlueprintType)
struct FMyTestStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyTestStruct")
	int32 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyTestStruct")
	FString MyName;
};

UCLASS()
class TESTPROJECT_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 仅在类默认设置可见
	/*UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnly;*/

	// 仅在实例化细节面板可见
	/*UPROPERTY(VisibleInstanceOnly)
	FString VisibleInstancestring;*/

	// 类默认设置和实例化细节面板可见
	/*UPROPERTY(VisibleAnywhere)
	FVector VisibleAnywhereVector;*/

	// 仅在类默认设置可见
	/*UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyInt;*/

	// 仅在实例化细节面板可见
	/*UPROPERTY(EditInstanceOnly)
	FString EditInstanceOnlystring;*/

	// 类默认设置和实例化细节面板可见
	/*UPROPERTY(EditAnywhere)
	FVector EditAnywhereVector;*/

	// 仅在蓝图中可读
	/*UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 BlueprintReadOnlyInt;*/

	// 在蓝图中可读写
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 BlueprintReadWriteInt;*/

	// 分类目录
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyIntValue")
	int32 Value1;*/

	// 分类目录
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyIntValue | MySubIntValue")
	int32 Value2;*/

	// meta 元数据说明符
	// DisplayName 别名
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "MyValur3DisplayName"))
	int32 MyValue3;*/

	// EditCondition 条件控制编辑
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Controller"))
	bool isController;*/

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "isController"))
	float value3;*/

	// Tooltip解释说明我们的变量
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "isControllerTrue"))
	bool isTrue;*/

	// 暴露我们的函数在蓝图中调用
	/*UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void PrintF1();*/

	// 纯虚函数的定义 BlueprintPure
	/*UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MyFunction")
	bool PrintF2();*/

	//// BlurprintImplementablEevent 在 C++ 声明，在蓝图中重载
	//UFUNCTION(BlueprintImplementableEvent)
	//void Test1();

	//UFUNCTION(BlueprintImplementableEvent)
	//int Test2();

	//UFUNCTION(BlueprintImplementableEvent)
	//void Test11(const FString& MyString);

	//UFUNCTION(BlueprintImplementableEvent)
	//int Test22(const FString& MyString);

	// BlueprintNativeEvent 在 c++ 中声明定义，蓝图可以重载或不重载
	/*UFUNCTION(BlueprintNativeEvent)
	void TestA();

	UFUNCTION(BlueprintNativeEvent)
	int TestB();

	UFUNCTION(BlueprintNativeEvent)
	void TestC(const FString& MyString);

	UFUNCTION(BlueprintNativeEvent)
	int TestD(const FString& MyString);*/

	// 元数据说明符 Meta
	/*UFUNCTION(BlueprintCallable, Category = "MyFunction", meta = (DisPlayName = "MyPrinttest"))
	void Printtest();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnum")
	TEnumAsByte<MyEnumType::MyCustomEnum> MyCustomEnum;*/

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCustomStruct")
	FMyTestStruct MyCustomObject;*/

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnum")
	TEnumAsByte<MyEnumType::MyCustomEnum> MyCustomEnum2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyTestExposeOnSpawnValue", meta = (ExposeOnSpawn = "true"))
	float ExposeOnSpawnValue;*/

	UPROPERTY()
	UMyObject* MyTestObject;

	UPROPERTY()
	UMyGameInstance* MyGameInstance;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
	USceneComponent* MyRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
	USpringArmComponent* MySpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
	UCameraComponent* MyCamera;

	UFUNCTION()
	/* 鼠标滑轮移动镜头缩放 */
	void Zoom(bool Direction, float ZoomSpeed);
};
