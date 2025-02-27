// Copyright Epic Games, Inc. All Rights Reserved.

#include "FileSystemBPLibrary.h"
#include "FileSystem.h"

UFileSystemBPLibrary::UFileSystemBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UFileSystemBPLibrary::FileSystemSampleFunction(float Param)
{
	return -1;
}

FString UFileSystemBPLibrary::GetCleanDirectory(EFileDirectoryType directoryType, FString filePath)
{
	if (directoryType == EFileDirectoryType::Absolute)
	{
		return FPaths::ConvertRelativePathToFull(filePath);
	}
	else
	{
		FString projectDir = FPaths::ProjectDir();
		return FPaths::ConvertRelativePathToFull(projectDir + filePath);
	}
}

bool UFileSystemBPLibrary::FileisExists(EFileDirectoryType directoryType, FString filePath)
{
	return FPaths::FileExists(*(GetCleanDirectory(directoryType, filePath)));
}

bool UFileSystemBPLibrary::DirectoryIsExists(EFileDirectoryType directoryType, FString filePath)
{
	return FPaths::DirectoryExists(*(GetCleanDirectory(directoryType, filePath)));
}

bool UFileSystemBPLibrary::DeleteFile(EFileDirectoryType directoryType, FString filePath)
{
	return FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*(GetCleanDirectory(directoryType, filePath)));
}

bool UFileSystemBPLibrary::DeleteDirectory(EFileDirectoryType directoryType, FString filePath)
{
	return FPlatformFileManager::Get().GetPlatformFile().DeleteDirectory(*(GetCleanDirectory(directoryType, filePath)));
}

TArray<uint8> UFileSystemBPLibrary::ReadBytesFromFile(EFileDirectoryType directoryType, FString filePath)
{
	TArray<uint8> Results;
	bool success = FFileHelper::LoadFileToArray(Results, *GetCleanDirectory(directoryType, filePath));
	return Results;
}

void UFileSystemBPLibrary::ReadFStringFromFile(EFileDirectoryType directoryType, FString filePath, FString& fileData, bool& IsSuccess)
{
	fileData.Empty();
	IsSuccess = FFileHelper::LoadFileToString(fileData, *GetCleanDirectory(directoryType, filePath));
}

void UFileSystemBPLibrary::WriteBytesToFile(EFileDirectoryType directoryType, FString filePath, TArray<uint8>& dataBytes, bool& IsSuccess)
{
	IsSuccess = FFileHelper::SaveArrayToFile(dataBytes, *GetCleanDirectory(directoryType ,filePath));
}

void UFileSystemBPLibrary::WriteFStringToFile(EFileDirectoryType directoryType, FString filePath, FString fileData, bool& IsSuccess, EEncodingOptionsType fileEncoding)
{
	IsSuccess = FFileHelper::SaveStringToFile(fileData, *GetCleanDirectory(directoryType, filePath), (FFileHelper::EEncodingOptions)fileEncoding);
}

FString UFileSystemBPLibrary::StringToBase64Encode(const FString& source)
{
	return FBase64::Encode(source);
}

FString UFileSystemBPLibrary::BytesToBase64Encode(const TArray<uint8>& source)
{
	return FBase64::Encode(source);
}

bool UFileSystemBPLibrary::Base64DecodeFString(const FString& source, FString& dest)
{
	return FBase64::Decode(source, dest);
}

bool UFileSystemBPLibrary::Base64DecodeBytes(const FString& source, TArray<uint8>& dest)
{
	return FBase64::Decode(source, dest);
}

FString UFileSystemBPLibrary::URLEncode(const FString& source)
{
	return FGenericPlatformHttp::UrlEncode(source);
}

FString UFileSystemBPLibrary::URLDecode(const FString& source)
{
	return FGenericPlatformHttp::UrlDecode(source);
}

FString UFileSystemBPLibrary::GetUTCTimestamp()
{
	FString Timestamp;
	FDateTime time = FDateTime::UtcNow();
	int64 unixTimestamp = time.ToUnixTimestamp();
	Timestamp = FString::Printf(TEXT("%lld"), unixTimestamp);
	return Timestamp;
}

FString UFileSystemBPLibrary::GetMillUTCTimestamp()
{
	FDateTime currentTime = FDateTime::UtcNow();
	int64 timestampMillSeconds = currentTime.ToUnixTimestamp() * 1000 + currentTime.GetMillisecond();
	FString MillTimestamp = FString::Printf(TEXT("%lld"), timestampMillSeconds);
	return MillTimestamp;
}