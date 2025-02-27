// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FileSystem/Public/FileSystemBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFileSystemBPLibrary() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
FILESYSTEM_API UClass* Z_Construct_UClass_UFileSystemBPLibrary();
FILESYSTEM_API UClass* Z_Construct_UClass_UFileSystemBPLibrary_NoRegister();
FILESYSTEM_API UEnum* Z_Construct_UEnum_FileSystem_EEncodingOptionsType();
FILESYSTEM_API UEnum* Z_Construct_UEnum_FileSystem_EFileDirectoryType();
UPackage* Z_Construct_UPackage__Script_FileSystem();
// End Cross Module References

// Begin Enum EFileDirectoryType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFileDirectoryType;
static UEnum* EFileDirectoryType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFileDirectoryType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFileDirectoryType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_FileSystem_EFileDirectoryType, (UObject*)Z_Construct_UPackage__Script_FileSystem(), TEXT("EFileDirectoryType"));
	}
	return Z_Registration_Info_UEnum_EFileDirectoryType.OuterSingleton;
}
template<> FILESYSTEM_API UEnum* StaticEnum<EFileDirectoryType>()
{
	return EFileDirectoryType_StaticEnum();
}
struct Z_Construct_UEnum_FileSystem_EFileDirectoryType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Absolute.DisplayName", "Absolute Directory" },
		{ "Absolute.Name", "EFileDirectoryType::Absolute" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
		{ "Relative.DisplayName", "Relative Directory" },
		{ "Relative.Name", "EFileDirectoryType::Relative" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFileDirectoryType::Relative", (int64)EFileDirectoryType::Relative },
		{ "EFileDirectoryType::Absolute", (int64)EFileDirectoryType::Absolute },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_FileSystem_EFileDirectoryType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_FileSystem,
	nullptr,
	"EFileDirectoryType",
	"EFileDirectoryType",
	Z_Construct_UEnum_FileSystem_EFileDirectoryType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_FileSystem_EFileDirectoryType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_FileSystem_EFileDirectoryType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_FileSystem_EFileDirectoryType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_FileSystem_EFileDirectoryType()
{
	if (!Z_Registration_Info_UEnum_EFileDirectoryType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFileDirectoryType.InnerSingleton, Z_Construct_UEnum_FileSystem_EFileDirectoryType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFileDirectoryType.InnerSingleton;
}
// End Enum EFileDirectoryType

// Begin Enum EEncodingOptionsType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEncodingOptionsType;
static UEnum* EEncodingOptionsType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEncodingOptionsType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEncodingOptionsType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_FileSystem_EEncodingOptionsType, (UObject*)Z_Construct_UPackage__Script_FileSystem(), TEXT("EEncodingOptionsType"));
	}
	return Z_Registration_Info_UEnum_EEncodingOptionsType.OuterSingleton;
}
template<> FILESYSTEM_API UEnum* StaticEnum<EEncodingOptionsType>()
{
	return EEncodingOptionsType_StaticEnum();
}
struct Z_Construct_UEnum_FileSystem_EEncodingOptionsType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AutoDetect.Name", "EEncodingOptionsType::AutoDetect" },
		{ "BlueprintType", "true" },
		{ "ForceAnsi.Name", "EEncodingOptionsType::ForceAnsi" },
		{ "ForceUnicode.Name", "EEncodingOptionsType::ForceUnicode" },
		{ "ForceUTF8.Name", "EEncodingOptionsType::ForceUTF8" },
		{ "ForceUTF8WithoutBOM.Name", "EEncodingOptionsType::ForceUTF8WithoutBOM" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEncodingOptionsType::AutoDetect", (int64)EEncodingOptionsType::AutoDetect },
		{ "EEncodingOptionsType::ForceAnsi", (int64)EEncodingOptionsType::ForceAnsi },
		{ "EEncodingOptionsType::ForceUnicode", (int64)EEncodingOptionsType::ForceUnicode },
		{ "EEncodingOptionsType::ForceUTF8", (int64)EEncodingOptionsType::ForceUTF8 },
		{ "EEncodingOptionsType::ForceUTF8WithoutBOM", (int64)EEncodingOptionsType::ForceUTF8WithoutBOM },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_FileSystem_EEncodingOptionsType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_FileSystem,
	nullptr,
	"EEncodingOptionsType",
	"EEncodingOptionsType",
	Z_Construct_UEnum_FileSystem_EEncodingOptionsType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_FileSystem_EEncodingOptionsType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_FileSystem_EEncodingOptionsType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_FileSystem_EEncodingOptionsType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_FileSystem_EEncodingOptionsType()
{
	if (!Z_Registration_Info_UEnum_EEncodingOptionsType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEncodingOptionsType.InnerSingleton, Z_Construct_UEnum_FileSystem_EEncodingOptionsType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEncodingOptionsType.InnerSingleton;
}
// End Enum EEncodingOptionsType

// Begin Class UFileSystemBPLibrary Function Base64DecodeBytes
struct Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics
{
	struct FileSystemBPLibrary_eventBase64DecodeBytes_Parms
	{
		FString source;
		TArray<uint8> dest;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xaa \xef\xbf\xbd\xd6\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xaa \xef\xbf\xbd\xd6\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_source_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_source;
	static const UECodeGen_Private::FBytePropertyParams NewProp_dest_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_dest;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventBase64DecodeBytes_Parms, source), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_source_MetaData), NewProp_source_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_dest_Inner = { "dest", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_dest = { "dest", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventBase64DecodeBytes_Parms, dest), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventBase64DecodeBytes_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventBase64DecodeBytes_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_dest_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_dest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "Base64DecodeBytes", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::FileSystemBPLibrary_eventBase64DecodeBytes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::FileSystemBPLibrary_eventBase64DecodeBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execBase64DecodeBytes)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_source);
	P_GET_TARRAY_REF(uint8,Z_Param_Out_dest);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFileSystemBPLibrary::Base64DecodeBytes(Z_Param_source,Z_Param_Out_dest);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function Base64DecodeBytes

// Begin Class UFileSystemBPLibrary Function Base64DecodeFString
struct Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics
{
	struct FileSystemBPLibrary_eventBase64DecodeFString_Parms
	{
		FString source;
		FString dest;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xaa String\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xce\xaa String" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_source_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_source;
	static const UECodeGen_Private::FStrPropertyParams NewProp_dest;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventBase64DecodeFString_Parms, source), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_source_MetaData), NewProp_source_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_dest = { "dest", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventBase64DecodeFString_Parms, dest), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventBase64DecodeFString_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventBase64DecodeFString_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_dest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "Base64DecodeFString", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::FileSystemBPLibrary_eventBase64DecodeFString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::FileSystemBPLibrary_eventBase64DecodeFString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execBase64DecodeFString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_source);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_dest);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFileSystemBPLibrary::Base64DecodeFString(Z_Param_source,Z_Param_Out_dest);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function Base64DecodeFString

// Begin Class UFileSystemBPLibrary Function BytesToBase64Encode
struct Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics
{
	struct FileSystemBPLibrary_eventBytesToBase64Encode_Parms
	{
		TArray<uint8> source;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xbd\xda\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xd6\xbd\xda\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_source_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_source_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_source;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::NewProp_source_Inner = { "source", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventBytesToBase64Encode_Parms, source), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_source_MetaData), NewProp_source_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventBytesToBase64Encode_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::NewProp_source_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::NewProp_source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "BytesToBase64Encode", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::FileSystemBPLibrary_eventBytesToBase64Encode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::FileSystemBPLibrary_eventBytesToBase64Encode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execBytesToBase64Encode)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_source);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFileSystemBPLibrary::BytesToBase64Encode(Z_Param_Out_source);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function BytesToBase64Encode

// Begin Class UFileSystemBPLibrary Function DeleteDirectory
struct Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics
{
	struct FileSystemBPLibrary_eventDeleteDirectory_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventDeleteDirectory_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventDeleteDirectory_Parms, filePath), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventDeleteDirectory_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventDeleteDirectory_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "DeleteDirectory", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::FileSystemBPLibrary_eventDeleteDirectory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::FileSystemBPLibrary_eventDeleteDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execDeleteDirectory)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFileSystemBPLibrary::DeleteDirectory(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function DeleteDirectory

// Begin Class UFileSystemBPLibrary Function DeleteFile
struct Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics
{
	struct FileSystemBPLibrary_eventDeleteFile_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventDeleteFile_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventDeleteFile_Parms, filePath), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventDeleteFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventDeleteFile_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "DeleteFile", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::FileSystemBPLibrary_eventDeleteFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::FileSystemBPLibrary_eventDeleteFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execDeleteFile)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFileSystemBPLibrary::DeleteFile(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function DeleteFile

// Begin Class UFileSystemBPLibrary Function DirectoryIsExists
struct Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics
{
	struct FileSystemBPLibrary_eventDirectoryIsExists_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventDirectoryIsExists_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventDirectoryIsExists_Parms, filePath), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventDirectoryIsExists_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventDirectoryIsExists_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "DirectoryIsExists", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::FileSystemBPLibrary_eventDirectoryIsExists_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::FileSystemBPLibrary_eventDirectoryIsExists_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execDirectoryIsExists)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFileSystemBPLibrary::DirectoryIsExists(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function DirectoryIsExists

// Begin Class UFileSystemBPLibrary Function FileisExists
struct Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics
{
	struct FileSystemBPLibrary_eventFileisExists_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventFileisExists_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventFileisExists_Parms, filePath), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventFileisExists_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventFileisExists_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "FileisExists", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::FileSystemBPLibrary_eventFileisExists_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::FileSystemBPLibrary_eventFileisExists_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execFileisExists)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UFileSystemBPLibrary::FileisExists(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function FileisExists

// Begin Class UFileSystemBPLibrary Function FileSystemSampleFunction
struct Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics
{
	struct FileSystemBPLibrary_eventFileSystemSampleFunction_Parms
	{
		float Param;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "FileSystemTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "FileSystem sample test testing" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Param;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventFileSystemSampleFunction_Parms, Param), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventFileSystemSampleFunction_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::NewProp_Param,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "FileSystemSampleFunction", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::FileSystemBPLibrary_eventFileSystemSampleFunction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::FileSystemBPLibrary_eventFileSystemSampleFunction_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execFileSystemSampleFunction)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Param);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UFileSystemBPLibrary::FileSystemSampleFunction(Z_Param_Param);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function FileSystemSampleFunction

// Begin Class UFileSystemBPLibrary Function GetCleanDirectory
struct Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics
{
	struct FileSystemBPLibrary_eventGetCleanDirectory_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventGetCleanDirectory_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventGetCleanDirectory_Parms, filePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventGetCleanDirectory_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "GetCleanDirectory", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::FileSystemBPLibrary_eventGetCleanDirectory_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::FileSystemBPLibrary_eventGetCleanDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execGetCleanDirectory)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFileSystemBPLibrary::GetCleanDirectory(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function GetCleanDirectory

// Begin Class UFileSystemBPLibrary Function GetMillUTCTimestamp
struct Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics
{
	struct FileSystemBPLibrary_eventGetMillUTCTimestamp_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xc8\xa1 UTC \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1 UTC \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventGetMillUTCTimestamp_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "GetMillUTCTimestamp", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::FileSystemBPLibrary_eventGetMillUTCTimestamp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::FileSystemBPLibrary_eventGetMillUTCTimestamp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execGetMillUTCTimestamp)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFileSystemBPLibrary::GetMillUTCTimestamp();
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function GetMillUTCTimestamp

// Begin Class UFileSystemBPLibrary Function GetUTCTimestamp
struct Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics
{
	struct FileSystemBPLibrary_eventGetUTCTimestamp_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xc8\xa1 UTC \xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xc8\xa1 UTC \xca\xb1\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventGetUTCTimestamp_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "GetUTCTimestamp", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::FileSystemBPLibrary_eventGetUTCTimestamp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::FileSystemBPLibrary_eventGetUTCTimestamp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execGetUTCTimestamp)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFileSystemBPLibrary::GetUTCTimestamp();
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function GetUTCTimestamp

// Begin Class UFileSystemBPLibrary Function ReadBytesFromFile
struct Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics
{
	struct FileSystemBPLibrary_eventReadBytesFromFile_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		TArray<uint8> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventReadBytesFromFile_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventReadBytesFromFile_Parms, filePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventReadBytesFromFile_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "ReadBytesFromFile", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::FileSystemBPLibrary_eventReadBytesFromFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::FileSystemBPLibrary_eventReadBytesFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execReadBytesFromFile)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<uint8>*)Z_Param__Result=UFileSystemBPLibrary::ReadBytesFromFile(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function ReadBytesFromFile

// Begin Class UFileSystemBPLibrary Function ReadFStringFromFile
struct Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics
{
	struct FileSystemBPLibrary_eventReadFStringFromFile_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		FString fileData;
		bool IsSuccess;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_fileData;
	static void NewProp_IsSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSuccess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventReadFStringFromFile_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventReadFStringFromFile_Parms, filePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_fileData = { "fileData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventReadFStringFromFile_Parms, fileData), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_IsSuccess_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventReadFStringFromFile_Parms*)Obj)->IsSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_IsSuccess = { "IsSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventReadFStringFromFile_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_IsSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_fileData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::NewProp_IsSuccess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "ReadFStringFromFile", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::FileSystemBPLibrary_eventReadFStringFromFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::FileSystemBPLibrary_eventReadFStringFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execReadFStringFromFile)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_fileData);
	P_GET_UBOOL_REF(Z_Param_Out_IsSuccess);
	P_FINISH;
	P_NATIVE_BEGIN;
	UFileSystemBPLibrary::ReadFStringFromFile(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath,Z_Param_Out_fileData,Z_Param_Out_IsSuccess);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function ReadFStringFromFile

// Begin Class UFileSystemBPLibrary Function StringToBase64Encode
struct Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics
{
	struct FileSystemBPLibrary_eventStringToBase64Encode_Parms
	{
		FString source;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd FString \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd FString \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd Base64 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_source_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_source;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventStringToBase64Encode_Parms, source), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_source_MetaData), NewProp_source_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventStringToBase64Encode_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::NewProp_source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "StringToBase64Encode", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::FileSystemBPLibrary_eventStringToBase64Encode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::FileSystemBPLibrary_eventStringToBase64Encode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execStringToBase64Encode)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_source);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFileSystemBPLibrary::StringToBase64Encode(Z_Param_source);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function StringToBase64Encode

// Begin Class UFileSystemBPLibrary Function URLDecode
struct Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics
{
	struct FileSystemBPLibrary_eventURLDecode_Parms
	{
		FString source;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// URL \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "URL \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_source_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_source;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventURLDecode_Parms, source), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_source_MetaData), NewProp_source_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventURLDecode_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::NewProp_source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "URLDecode", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::FileSystemBPLibrary_eventURLDecode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::FileSystemBPLibrary_eventURLDecode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execURLDecode)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_source);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFileSystemBPLibrary::URLDecode(Z_Param_source);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function URLDecode

// Begin Class UFileSystemBPLibrary Function URLEncode
struct Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics
{
	struct FileSystemBPLibrary_eventURLEncode_Parms
	{
		FString source;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "CommandLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// URL \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "URL \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_source_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_source;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventURLEncode_Parms, source), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_source_MetaData), NewProp_source_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventURLEncode_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::NewProp_source,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "URLEncode", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::FileSystemBPLibrary_eventURLEncode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::FileSystemBPLibrary_eventURLEncode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execURLEncode)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_source);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UFileSystemBPLibrary::URLEncode(Z_Param_source);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function URLEncode

// Begin Class UFileSystemBPLibrary Function WriteBytesToFile
struct Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics
{
	struct FileSystemBPLibrary_eventWriteBytesToFile_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		TArray<uint8> dataBytes;
		bool IsSuccess;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static const UECodeGen_Private::FBytePropertyParams NewProp_dataBytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_dataBytes;
	static void NewProp_IsSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSuccess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventWriteBytesToFile_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventWriteBytesToFile_Parms, filePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_dataBytes_Inner = { "dataBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_dataBytes = { "dataBytes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventWriteBytesToFile_Parms, dataBytes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_IsSuccess_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventWriteBytesToFile_Parms*)Obj)->IsSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_IsSuccess = { "IsSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventWriteBytesToFile_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_IsSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_dataBytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_dataBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::NewProp_IsSuccess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "WriteBytesToFile", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::FileSystemBPLibrary_eventWriteBytesToFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::FileSystemBPLibrary_eventWriteBytesToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execWriteBytesToFile)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_GET_TARRAY_REF(uint8,Z_Param_Out_dataBytes);
	P_GET_UBOOL_REF(Z_Param_Out_IsSuccess);
	P_FINISH;
	P_NATIVE_BEGIN;
	UFileSystemBPLibrary::WriteBytesToFile(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath,Z_Param_Out_dataBytes,Z_Param_Out_IsSuccess);
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function WriteBytesToFile

// Begin Class UFileSystemBPLibrary Function WriteFStringToFile
struct Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics
{
	struct FileSystemBPLibrary_eventWriteFStringToFile_Parms
	{
		EFileDirectoryType directoryType;
		FString filePath;
		FString fileData;
		bool IsSuccess;
		EEncodingOptionsType fileEncoding;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "File" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_directoryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_directoryType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_filePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_fileData;
	static void NewProp_IsSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSuccess;
	static const UECodeGen_Private::FBytePropertyParams NewProp_fileEncoding_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_fileEncoding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_directoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_directoryType = { "directoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventWriteFStringToFile_Parms, directoryType), Z_Construct_UEnum_FileSystem_EFileDirectoryType, METADATA_PARAMS(0, nullptr) }; // 3384260615
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_filePath = { "filePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventWriteFStringToFile_Parms, filePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_fileData = { "fileData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventWriteFStringToFile_Parms, fileData), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_IsSuccess_SetBit(void* Obj)
{
	((FileSystemBPLibrary_eventWriteFStringToFile_Parms*)Obj)->IsSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_IsSuccess = { "IsSuccess", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FileSystemBPLibrary_eventWriteFStringToFile_Parms), &Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_IsSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_fileEncoding_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_fileEncoding = { "fileEncoding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileSystemBPLibrary_eventWriteFStringToFile_Parms, fileEncoding), Z_Construct_UEnum_FileSystem_EEncodingOptionsType, METADATA_PARAMS(0, nullptr) }; // 1354877766
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_directoryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_directoryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_filePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_fileData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_IsSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_fileEncoding_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::NewProp_fileEncoding,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileSystemBPLibrary, nullptr, "WriteFStringToFile", nullptr, nullptr, Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::FileSystemBPLibrary_eventWriteFStringToFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::FileSystemBPLibrary_eventWriteFStringToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileSystemBPLibrary::execWriteFStringToFile)
{
	P_GET_ENUM(EFileDirectoryType,Z_Param_directoryType);
	P_GET_PROPERTY(FStrProperty,Z_Param_filePath);
	P_GET_PROPERTY(FStrProperty,Z_Param_fileData);
	P_GET_UBOOL_REF(Z_Param_Out_IsSuccess);
	P_GET_ENUM(EEncodingOptionsType,Z_Param_fileEncoding);
	P_FINISH;
	P_NATIVE_BEGIN;
	UFileSystemBPLibrary::WriteFStringToFile(EFileDirectoryType(Z_Param_directoryType),Z_Param_filePath,Z_Param_fileData,Z_Param_Out_IsSuccess,EEncodingOptionsType(Z_Param_fileEncoding));
	P_NATIVE_END;
}
// End Class UFileSystemBPLibrary Function WriteFStringToFile

// Begin Class UFileSystemBPLibrary
void UFileSystemBPLibrary::StaticRegisterNativesUFileSystemBPLibrary()
{
	UClass* Class = UFileSystemBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Base64DecodeBytes", &UFileSystemBPLibrary::execBase64DecodeBytes },
		{ "Base64DecodeFString", &UFileSystemBPLibrary::execBase64DecodeFString },
		{ "BytesToBase64Encode", &UFileSystemBPLibrary::execBytesToBase64Encode },
		{ "DeleteDirectory", &UFileSystemBPLibrary::execDeleteDirectory },
		{ "DeleteFile", &UFileSystemBPLibrary::execDeleteFile },
		{ "DirectoryIsExists", &UFileSystemBPLibrary::execDirectoryIsExists },
		{ "FileisExists", &UFileSystemBPLibrary::execFileisExists },
		{ "FileSystemSampleFunction", &UFileSystemBPLibrary::execFileSystemSampleFunction },
		{ "GetCleanDirectory", &UFileSystemBPLibrary::execGetCleanDirectory },
		{ "GetMillUTCTimestamp", &UFileSystemBPLibrary::execGetMillUTCTimestamp },
		{ "GetUTCTimestamp", &UFileSystemBPLibrary::execGetUTCTimestamp },
		{ "ReadBytesFromFile", &UFileSystemBPLibrary::execReadBytesFromFile },
		{ "ReadFStringFromFile", &UFileSystemBPLibrary::execReadFStringFromFile },
		{ "StringToBase64Encode", &UFileSystemBPLibrary::execStringToBase64Encode },
		{ "URLDecode", &UFileSystemBPLibrary::execURLDecode },
		{ "URLEncode", &UFileSystemBPLibrary::execURLEncode },
		{ "WriteBytesToFile", &UFileSystemBPLibrary::execWriteBytesToFile },
		{ "WriteFStringToFile", &UFileSystemBPLibrary::execWriteFStringToFile },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFileSystemBPLibrary);
UClass* Z_Construct_UClass_UFileSystemBPLibrary_NoRegister()
{
	return UFileSystemBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UFileSystemBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FileSystemBPLibrary.h" },
		{ "ModuleRelativePath", "Public/FileSystemBPLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeBytes, "Base64DecodeBytes" }, // 3922375476
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_Base64DecodeFString, "Base64DecodeFString" }, // 51713213
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_BytesToBase64Encode, "BytesToBase64Encode" }, // 2482537018
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_DeleteDirectory, "DeleteDirectory" }, // 4028484226
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_DeleteFile, "DeleteFile" }, // 1273630290
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_DirectoryIsExists, "DirectoryIsExists" }, // 355345884
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_FileisExists, "FileisExists" }, // 4019076961
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_FileSystemSampleFunction, "FileSystemSampleFunction" }, // 2776548689
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_GetCleanDirectory, "GetCleanDirectory" }, // 2605950270
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_GetMillUTCTimestamp, "GetMillUTCTimestamp" }, // 945208747
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_GetUTCTimestamp, "GetUTCTimestamp" }, // 543943808
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_ReadBytesFromFile, "ReadBytesFromFile" }, // 2819998731
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_ReadFStringFromFile, "ReadFStringFromFile" }, // 563386123
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_StringToBase64Encode, "StringToBase64Encode" }, // 1227947635
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_URLDecode, "URLDecode" }, // 2746094438
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_URLEncode, "URLEncode" }, // 2499405365
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_WriteBytesToFile, "WriteBytesToFile" }, // 27808840
		{ &Z_Construct_UFunction_UFileSystemBPLibrary_WriteFStringToFile, "WriteFStringToFile" }, // 2502529216
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFileSystemBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UFileSystemBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_FileSystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFileSystemBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFileSystemBPLibrary_Statics::ClassParams = {
	&UFileSystemBPLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFileSystemBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UFileSystemBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFileSystemBPLibrary()
{
	if (!Z_Registration_Info_UClass_UFileSystemBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFileSystemBPLibrary.OuterSingleton, Z_Construct_UClass_UFileSystemBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFileSystemBPLibrary.OuterSingleton;
}
template<> FILESYSTEM_API UClass* StaticClass<UFileSystemBPLibrary>()
{
	return UFileSystemBPLibrary::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFileSystemBPLibrary);
UFileSystemBPLibrary::~UFileSystemBPLibrary() {}
// End Class UFileSystemBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EFileDirectoryType_StaticEnum, TEXT("EFileDirectoryType"), &Z_Registration_Info_UEnum_EFileDirectoryType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3384260615U) },
		{ EEncodingOptionsType_StaticEnum, TEXT("EEncodingOptionsType"), &Z_Registration_Info_UEnum_EEncodingOptionsType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1354877766U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFileSystemBPLibrary, UFileSystemBPLibrary::StaticClass, TEXT("UFileSystemBPLibrary"), &Z_Registration_Info_UClass_UFileSystemBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFileSystemBPLibrary), 401244205U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_1502051580(TEXT("/Script/FileSystem"),
	Z_CompiledInDeferFile_FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
