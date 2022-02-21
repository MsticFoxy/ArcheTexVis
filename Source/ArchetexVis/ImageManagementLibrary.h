// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Char.h"
#include "Engine/Texture2D.h"
#include "ImageManagementLibrary.generated.h"


/**
 * 
 */
UCLASS()
class ARCHETEXVIS_API UImageManagementLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		static bool SaveTextureToFileAsJPG(UTexture2D* texture, FString path, FString fileName);

	UFUNCTION(BlueprintCallable, Category = "FilePicker")
		static void OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes, const bool& SingleFile, TArray<FString>& OutFileNames);

	UFUNCTION(BlueprintCallable, Category = "FilePicker")
		static void OpenDirectoryDialog(const FString& DialogTitle, const FString& DefaultPath, FString& OutDirectoryNames);

	UFUNCTION(BlueprintCallable, Category = "FilePicker")
		static int ShellCommand(const FString command);

	UFUNCTION(BlueprintCallable, Category = "ImageAnalysis")
		static TArray<FVector> GetHistogramData(UTexture2D* texture, int& max, int& count);

	UFUNCTION(BlueprintCallable, Category = "ImageAnalysis")
		static TArray<FVector> GetVectorscopeData(UTexture2D* texture, int& max, int& count);
};
