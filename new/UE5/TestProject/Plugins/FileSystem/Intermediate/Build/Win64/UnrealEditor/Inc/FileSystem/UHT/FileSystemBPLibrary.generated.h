// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FileSystemBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EEncodingOptionsType : uint8;
enum class EFileDirectoryType : uint8;
#ifdef FILESYSTEM_FileSystemBPLibrary_generated_h
#error "FileSystemBPLibrary.generated.h already included, missing '#pragma once' in FileSystemBPLibrary.h"
#endif
#define FILESYSTEM_FileSystemBPLibrary_generated_h

#define FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_29_RPC_WRAPPERS \
	DECLARE_FUNCTION(execGetMillUTCTimestamp); \
	DECLARE_FUNCTION(execGetUTCTimestamp); \
	DECLARE_FUNCTION(execURLDecode); \
	DECLARE_FUNCTION(execURLEncode); \
	DECLARE_FUNCTION(execBase64DecodeBytes); \
	DECLARE_FUNCTION(execBase64DecodeFString); \
	DECLARE_FUNCTION(execBytesToBase64Encode); \
	DECLARE_FUNCTION(execStringToBase64Encode); \
	DECLARE_FUNCTION(execWriteFStringToFile); \
	DECLARE_FUNCTION(execWriteBytesToFile); \
	DECLARE_FUNCTION(execReadFStringFromFile); \
	DECLARE_FUNCTION(execReadBytesFromFile); \
	DECLARE_FUNCTION(execDeleteDirectory); \
	DECLARE_FUNCTION(execDeleteFile); \
	DECLARE_FUNCTION(execDirectoryIsExists); \
	DECLARE_FUNCTION(execFileisExists); \
	DECLARE_FUNCTION(execGetCleanDirectory); \
	DECLARE_FUNCTION(execFileSystemSampleFunction);


#define FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_29_INCLASS \
private: \
	static void StaticRegisterNativesUFileSystemBPLibrary(); \
	friend struct Z_Construct_UClass_UFileSystemBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UFileSystemBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FileSystem"), NO_API) \
	DECLARE_SERIALIZER(UFileSystemBPLibrary)


#define FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFileSystemBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFileSystemBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFileSystemBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFileSystemBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UFileSystemBPLibrary(UFileSystemBPLibrary&&); \
	UFileSystemBPLibrary(const UFileSystemBPLibrary&); \
public: \
	NO_API virtual ~UFileSystemBPLibrary();


#define FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_26_PROLOG
#define FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_29_RPC_WRAPPERS \
	FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_29_INCLASS \
	FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FILESYSTEM_API UClass* StaticClass<class UFileSystemBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Serendipity_Desktop_test_TestProject_Plugins_FileSystem_Source_FileSystem_Public_FileSystemBPLibrary_h


#define FOREACH_ENUM_EFILEDIRECTORYTYPE(op) \
	op(EFileDirectoryType::Relative) \
	op(EFileDirectoryType::Absolute) 

enum class EFileDirectoryType : uint8;
template<> struct TIsUEnumClass<EFileDirectoryType> { enum { Value = true }; };
template<> FILESYSTEM_API UEnum* StaticEnum<EFileDirectoryType>();

#define FOREACH_ENUM_EENCODINGOPTIONSTYPE(op) \
	op(EEncodingOptionsType::AutoDetect) \
	op(EEncodingOptionsType::ForceAnsi) \
	op(EEncodingOptionsType::ForceUnicode) \
	op(EEncodingOptionsType::ForceUTF8) \
	op(EEncodingOptionsType::ForceUTF8WithoutBOM) 

enum class EEncodingOptionsType : uint8;
template<> struct TIsUEnumClass<EEncodingOptionsType> { enum { Value = true }; };
template<> FILESYSTEM_API UEnum* StaticEnum<EEncodingOptionsType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
