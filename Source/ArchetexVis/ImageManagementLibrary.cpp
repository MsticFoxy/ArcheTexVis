// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageManagementLibrary.h"
#include "Engine/Texture2D.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include <stdlib.h>
#include <string>
#include "Math/UnrealMathUtility.h"

bool UImageManagementLibrary::SaveTextureToFileAsJPG(UTexture2D* texture, FString path, FString fileName) {

	//Implement with OpenCV

	/*texture->UpdateResource();
	FTexture2DMipMap* MM = &texture->PlatformData->Mips[0];

	TArray<FColor> Out;
	int w = MM->SizeX;
	int h = MM->SizeY;

	Out.InsertZeroed(0, w*h);

	FByteBulkData* RawImageData = &MM->BulkData;

	FColor* FormatedImageData = static_cast<FColor*>(RawImageData->Lock(LOCK_READ_ONLY));

	for (int i = 0; i < (w*h); ++i)
	{
		Out[i] = FColor(FormatedImageData[i].R, FormatedImageData[i].G, FormatedImageData[i].B, 1);
	}

	RawImageData->Unlock();*/

	return false;
}

void UImageManagementLibrary::OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes, const bool& SingleFile, TArray<FString>& OutFileNames)
{
	if (GEngine)
	{
		if (GEngine->GameViewport)
		{
			void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
			IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
			if (DesktopPlatform)
			{
				//Opening the file picker!
				uint32 SelectionFlag = 0; //A value of 0 represents single file selection while a value of 1 represents multiple file selection
				if (!SingleFile)
				{
					SelectionFlag = 1;
				}
				DesktopPlatform->OpenFileDialog(ParentWindowHandle, DialogTitle, DefaultPath, FString(""), FileTypes, SelectionFlag, OutFileNames);
			}
		}
	}
}

void UImageManagementLibrary::OpenDirectoryDialog(const FString& DialogTitle, const FString& DefaultPath, FString& OutDirectoryNames)
{
	if (GEngine)
	{
		if (GEngine->GameViewport)
		{
			void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
			IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
			if (DesktopPlatform)
			{
				DesktopPlatform->OpenDirectoryDialog(ParentWindowHandle, DialogTitle, DefaultPath, OutDirectoryNames);
			}
		}
	}
}

int UImageManagementLibrary::ShellCommand(const FString command)
{
	//const TCHAR* url = *command;
	std::string msg(TCHAR_TO_UTF8(*command));
	const char* url = msg.c_str();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, url);
	return system(url);
	//return system("F:/Studium/Praxisprojekt/MaterialScannerHsH/x64/Release/MaterialScannerHsH F:/GameDevelopment/Projekte/ArchetexVis/Captures/Test/ F:/GameDevelopment/Projekte/ArchetexVis/Captures/test.png 15");
}

TArray<FVector> UImageManagementLibrary::GetHistogramData(UTexture2D* texture, int& max, int& count)
{
	TArray<FVector> ret = TArray<FVector>();
	ret.Init(FVector(0), 265);
	max = 0;
	count = texture->GetSizeX() * texture->GetSizeY();

	/*const FColor* FormatedImageData = static_cast<const FColor*>(texture->PlatformData->Mips[0].BulkData.LockReadOnly());
	for (int X = 0; X < texture->GetSizeX(); X++)
	{
		for (int Y = 0; Y < texture->GetSizeY(); Y++)
		{
			FColor PixelColor = FormatedImageData[Y * texture->GetSizeX() + X];
			ret[PixelColor.R].X += 1;
			ret[PixelColor.G].Y += 1;
			ret[PixelColor.B].Z += 1;
		}
	}
	for (int i = 0; i < ret.Num(); i++)
	{
		max = FMath::CeilToInt(FMath::Max(FMath::Max(ret[i].X, ret[i].X), FMath::Max(ret[i].Z, (float)max)));
	}

	texture->PlatformData->Mips[0].BulkData.Unlock();*/

	return ret;
}

TArray<FVector> UImageManagementLibrary::GetVectorscopeData(UTexture2D* texture, int& max, int& count)
{
	TArray<FVector> ret = TArray<FVector>();
	max = 0;
	count = texture->GetSizeX() * texture->GetSizeY();

	/*const FColor* FormatedImageData = static_cast<const FColor*>(texture->PlatformData->Mips[0].BulkData.LockReadOnly());
	for (int X = 0; X < texture->GetSizeX(); X++)
	{
		for (int Y = 0; Y < texture->GetSizeY(); Y++)
		{
			FColor PixelColor = FormatedImageData[Y * texture->GetSizeX() + X];
			float ry = 0.701f * PixelColor.R - 0.587f * PixelColor.G - 0.114f * PixelColor.B;
			float by = -0.299f * PixelColor.R - 0.587f * PixelColor.G + 0.886f * PixelColor.B;
			float u = by * 0.493f;
			float v = ry * 0.877f;
			ret.Add(FVector(u, v, 0));
		}
	}
	for (int i = 0; i < ret.Num(); i++)
	{
		max = FMath::CeilToInt(FMath::Max(FMath::Max(ret[i].X, ret[i].X), FMath::Max(ret[i].Z, (float)max)));
	}

	texture->PlatformData->Mips[0].BulkData.Unlock();*/

	return ret;
}
