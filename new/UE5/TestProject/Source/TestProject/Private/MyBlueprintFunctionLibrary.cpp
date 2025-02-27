// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/HAL/FileManagerGeneric.h"

bool UMyBlueprintFunctionLibrary::LoadStringFromFile(FString FilePath, FString&   resultString)
{
	if (!FilePath.IsEmpty())
	{
		if (FFileHelper::LoadFileToString(resultString, *FilePath))
		{
			return true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ERROR"));
		}
	}
	return false;
}

bool UMyBlueprintFunctionLibrary::WriteStringToFile(TArray<FString> SaveFile, FString FilePath)
{
	if (!FilePath.IsEmpty())
	{
		if (FFileHelper::SaveStringArrayToFile(SaveFile, *FilePath))
		{
			return true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ERROR"));
		}
	}
	return false;
}

FString UMyBlueprintFunctionLibrary::GetFilePath(FString Path)
{
	FString result = FPaths::GetPath(*Path);
	return result;
}

FString UMyBlueprintFunctionLibrary::GetFileName(FString InPath, bool bRemovePath)
{
	return FPaths::GetBaseFilename(*InPath, bRemovePath);
}

FString UMyBlueprintFunctionLibrary::GetFileExtension(FString InPath, bool bInCludeDot)
{
	return FPaths::GetExtension(*InPath, bInCludeDot);
}

void UMyBlueprintFunctionLibrary::CreateFolder(FString FolderName)
{
	FString Path = FPaths::ProjectContentDir() / *FolderName;
	FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*Path);
}

void UMyBlueprintFunctionLibrary::DeleteFolder(FString FolderName)
{
	FString Path1 = FPaths::ProjectContentDir() / *FolderName;
	FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*Path1);
}

bool UMyBlueprintFunctionLibrary::MoveFileTo(FString To, FString From)
{
	return IFileManager::Get().Move(*To, *From);
}

TArray<FString> UMyBlueprintFunctionLibrary::FindFileFolder(FString Path, FString Filter, bool Files, bool Directory)
{
	TArray<FString> FilePathList;
	FilePathList.Empty();
	FFileManagerGeneric::Get().FindFilesRecursive(FilePathList, *Path, *Filter, Files, Directory);
	return FilePathList;
}

void UMyBlueprintFunctionLibrary::TestPrintf()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("111"));
}

void UMyBlueprintFunctionLibrary::ReadJson(FString JsonValueString)
{
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValueString);
	TSharedPtr<FJsonObject> JsonObject;
	bool isOk = FJsonSerializer::Deserialize(JsonReader, JsonObject);
	if (isOk)
	{
		int32 code = JsonObject->GetIntegerField("code");
		FString msg = JsonObject->GetStringField("msg");
		TSharedPtr<FJsonObject> DataObject = JsonObject->GetObjectField("data");
		FString MyUserName = DataObject->GetStringField("username");
		FString MyUserID = DataObject->GetStringField("userid");
		FString MyToken = DataObject->GetStringField("token");
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%d"), code));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *msg));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *MyUserName));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *MyUserID));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s"), *MyToken));
	}
}

TMap<FString, FString> UMyBlueprintFunctionLibrary::JsonToMap(FString JsonValueString)
{
	TMap<FString, FString> result;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValueString);
	TSharedPtr<FJsonObject> JsonObject;
	bool isOk = FJsonSerializer::Deserialize(JsonReader, JsonObject);
	if (isOk)
	{
		TMap<FString, TSharedPtr<FJsonValue>> keys = JsonObject->Values;
		for (auto currJson = keys.CreateIterator(); currJson; ++currJson)
		{
			FString key = (*currJson).Key;
			FString value = JsonObject->GetStringField(key);
			result.Add(key, value );
		}
	}
	return result;
}

FString UMyBlueprintFunctionLibrary::MapToJson(TMap<FString, FString> InMap)
{
	FString JsonStr;
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWrite = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonStr);
	JsonWrite->WriteObjectStart();
	TArray<FString> keys;
	InMap.GetKeys(keys);
	for (size_t i = 0; i < keys.Num(); i++)
	{
		FString* value = InMap.Find(keys[i]);
		JsonWrite->WriteValue(keys[i], *value);
	}
	JsonWrite->WriteObjectEnd();
	JsonWrite->Close();
	return JsonStr;
}

