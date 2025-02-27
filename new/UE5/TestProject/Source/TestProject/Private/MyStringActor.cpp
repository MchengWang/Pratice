// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStringActor.h"
#include "Kismet/KismetStringLibrary.h"

// Sets default values
AMyStringActor::AMyStringActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyStringActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyStringActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyStringActor::MyStringOperation()
{
	FString MyString = TEXT("123456789_AbcdEFG");
	// 查找字符串是否包含指定字符
	bool isFind1 = MyString.Contains("b", ESearchCase::IgnoreCase, ESearchDir::FromStart);
	bool isFind2 = UKismetStringLibrary::Contains(MyString, "b");
	
	// 判断字符串是否相等
	bool isFind3 = MyString.Equals("123");

	// 拼接字符串
	FString MyString2 = MyString.Append("OBJ");

	// 字符串的长度
	int32 Num = MyString.Len();
	int32 Num2 = UKismetStringLibrary::Len(MyString);

	// 字符串是否为空
	bool isEmpty = MyString.IsEmpty();

	// 从指定位置开始的字符串返回一个子字符串
	FString MyChildString = UKismetStringLibrary::GetSubstring(MyString, 0, 3);

	// 从指定字符串中查找子字符串的起始索引值
	int32 Index1 = UKismetStringLibrary::FindSubstring(MyString, "123", false, false, 0);

	// 返回第几个字符的ASCII
	int32 Index2 = UKismetStringLibrary::GetCharacterAsNumber(MyString, 0);

	// 返回一个数组
	TArray<FString> MyArrayString;
	MyArrayString = UKismetStringLibrary::GetCharacterArrayFromString(MyString);

	// 大写
	FString MyUpperString = MyString.ToUpper();

	// 小写
	FString MyLowerString = MyString.ToLower();

	// 在字符串的左侧或者右侧天聪指定数量的字符
	FString MyLeftpadString = MyString.LeftPad(3);
	FString MyRightpadString = MyString.RightPad(3);

	// 检查字符串中是否包含数字字符
	bool isNumber = MyString.IsNumeric();

	// 字符串是否以给定的字符串开头或者结尾
	bool isStart = MyString.StartsWith("abcd", ESearchCase::IgnoreCase);
	bool isEnd = MyString.EndsWith("123", ESearchCase::IgnoreCase);

	// 字符串替换
	UKismetStringLibrary::Replace(MyString, "a", "s", ESearchCase::IgnoreCase);

	// 返回最左或者最右边给定的字符数
	UKismetStringLibrary::Left(MyString, 2);
	UKismetStringLibrary::Right(MyString, 2);

	// 返回最左边或者最右边给定的字符数，从末尾切掉给定数量的字符
	UKismetStringLibrary::LeftChop(MyString, 1);
	UKismetStringLibrary::RightChop(MyString, 2);

	// 从起始位置返回 Count 个字符的子字符串
	UKismetStringLibrary::Mid(MyString, 2, 3);

	// 分割处左字符串和右字符串
	FString Left;
	FString Right;
	MyString.Split("_", &Left, &Right, ESearchCase::IgnoreCase, ESearchDir::FromStart);

	// 从分割符划分的元字符中获取字符串数组，并且可选删除空字符串
	TArray<FString> MyStringArrayPrase;
	MyString.ParseIntoArray(MyStringArrayPrase, TEXT("_"), true);
	for (auto TestArray : MyStringArrayPrase)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *TestArray));
	}
}
