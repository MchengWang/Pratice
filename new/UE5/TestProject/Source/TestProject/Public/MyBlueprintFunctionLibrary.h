// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// 加载文件资源
	UFUNCTION(BlueprintCallable, Category = "File")
	static bool LoadStringFromFile(FString FilePath, FString& resultString);

	// 写入文件资源
	UFUNCTION(BlueprintCallable, Category = "File")
	static bool WriteStringToFile(TArray<FString> SaveFile, FString FilePath);

	// 获取文件所在路径
	UFUNCTION(BlueprintCallable, Category = "File")
	static FString GetFilePath(FString Path);

	// 获取文件名（无后缀）
	UFUNCTION(BlueprintCallable, Category = "File")
	static FString GetFileName(FString InPath, bool bRemovePath);

	// 获取文件后缀
	UFUNCTION(BlueprintCallable, Category = "File")
	static FString GetFileExtension(FString InPath, bool bInCludeDot);

	// 创建文件夹
	UFUNCTION(BlueprintCallable, Category = "File")
	static void CreateFolder(FString FolderName);

	// 删除文件夹
	UFUNCTION(BlueprintCallable, Category = "File")
	static void DeleteFolder(FString FolderName);

	// 移动文件夹
	UFUNCTION(BlueprintCallable, Category = "File")
	static bool MoveFileTo(FString To, FString From);

	// 查找文件目录下所有的文件夹或者文件
	UFUNCTION(BlueprintCallable, Category = "File")
	static TArray<FString> FindFileFolder(FString Path, FString Filter, bool Files, bool Directory);

	UFUNCTION(BlueprintCallable, Category = "函数库")
	static void TestPrintf();

	UFUNCTION(BlueprintCallable, Category = "Json")
	static void ReadJson(FString JsonValueString);

	UFUNCTION(BlueprintCallable, Category = "JsonToMap")
	static TMap<FString, FString> JsonToMap(FString JsonValueString);	

	UFUNCTION(BlueprintCallable, Category = "MapToJson")
	static FString MapToJson(TMap<FString, FString> InMap);

};
