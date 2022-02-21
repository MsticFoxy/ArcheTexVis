// Copyright Rama All Rights Reserved.

#pragma once

//Kinda Important (used once in a while)
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"

//UMG
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "VictoryBPFunctionLibrary.generated.h"

UENUM(BlueprintType)
enum EJoyImageFormats
{
	/**
	 * Example of a comment inside a custom enum <3 Rama
	 * @see FWalkableSlopeOverride::WalkableSlopeAngle
	 */
	JPG		UMETA(DisplayName="JPG        "),
	
	PNG		UMETA(DisplayName="PNG        "),
	BMP		UMETA(DisplayName="BMP        "),
	ICO		UMETA(DisplayName="ICO        "),
	EXR		UMETA(DisplayName="EXR        "),
	ICNS	UMETA(DisplayName="ICNS        "),
	
	JoyImageFormats_Max		UMETA(Hidden),
};

/*
	Victory to You! <3 Rama
*/
UCLASS()
class UVictoryBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	//~~~~~~~~~~~~~~~~~~~
	// 	  Load Object
	//~~~~~~~~~~~~~~~~~~~
	
	/** The FName that is expected is the exact same format as when you right click on asset -> Copy Reference! You can directly paste copied references into this node! IsValid lets you know if the path was correct or not and I was able to load the object. MAKE SURE TO SAVE THE RETURNED OBJECT AS A VARIABLE. Otherwise your shiny new asset will get garbage collected. I recommend you cast the return value to the appropriate object and then promote it to a variable :)  -Rama */
	UFUNCTION(BlueprintCallable, Category = "Victory BP Library|Misc", Meta = (DeterminesOutputType = "ObjectClass"))
	static UObject* LoadObjectFromAssetPath(TSubclassOf<UObject> ObjectClass, FName Path, bool& IsValid);

	/** Uses the same format as I use for LoadObjectFromAssetPath! Use this node to get the asset path of objects in the world! -Rama */
	UFUNCTION(BlueprintPure, Category = "Victory BP Library|Misc")
	static FName GetObjectPath(UObject* Obj);
	
	//~~~~~~~~~~~~
	// 	  Math
	//~~~~~~~~~~~~
	
	/** Easily add to an integer! <3 Rama*/
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "+=",Keywords = "increment integer"), Category = "Victory BP Library|Math|Integer")
	static void VictoryIntPlusEquals(UPARAM(ref) int32& Int, int32 Add, int32& IntOut);

	/** Easily subtract from an integer! <3 Rama*/
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "-=",Keywords = "decrement integer"), Category = "Victory BP Library|Math|Integer")
	static void VictoryIntMinusEquals(UPARAM(ref) int32& Int, int32 Sub, int32& IntOut);

	/** Easily add to a float! <3 Rama*/
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "+=",Keywords = "increment float"), Category = "Victory BP Library|Math|Float")
	static void VictoryFloatPlusEquals(UPARAM(ref) float& Float, float Add, float& FloatOut);

	/** Easily subtract from a float! <3 Rama*/
	UFUNCTION(BlueprintCallable, meta = (CompactNodeTitle = "-=",Keywords = "decrement float"), Category = "Victory BP Library|Math|Float")
	static void VictoryFloatMinusEquals(UPARAM(ref) float& Float, float Sub, float& FloatOut);
	
	/** Sort an integer array, smallest value will be at index 0 after sorting. Modifies the input array, no new data created. <3 Rama */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "sort integer array"), Category = "Victory BP Library|Array")
	static void VictorySortIntArray(UPARAM(ref) TArray<int32>& IntArray, TArray<int32>& IntArrayRef)
	{
		IntArray.Sort();
		IntArrayRef = IntArray;
	}

	/** Sort a float array, smallest value will be at index 0 after sorting. Modifies the input array, no new data created. */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "sort float array"), Category = "Victory BP Library|Array")
	static void VictorySortFloatArray(UPARAM(ref) TArray<float>& FloatArray, TArray<float>& FloatArrayRef)
	{
		FloatArray.Sort();
		FloatArrayRef = FloatArray;
	}
	 
	/** Sort a string array alphabetically! */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "sort string array"), Category = "Victory BP Library|Array")
	static void VictorySortStringArray(UPARAM(ref) TArray<FString>& StringArray, TArray<FString>& StringArrayRef)
	{
		StringArray.Sort();
		StringArrayRef = StringArray;
	}
	
	//~~~~~~~~~~~~
	// 	  UMG
	//~~~~~~~~~~~~
	/**
	 * Find first widget of a certain class and return it.
	 * @param WidgetClass The widget class to filter by.
	 * @param TopLevelOnly Only a widget that is a direct child of the viewport will be returned.
	 */
	UFUNCTION(Category = "Victory BP Library|UMG", BlueprintCallable, BlueprintCosmetic, Meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "WidgetClass"))
	static UUserWidget* GetFirstWidgetOfClass(UObject* WorldContextObject, TSubclassOf<UUserWidget> WidgetClass, bool TopLevelOnly);
	
	UFUNCTION(Category = "Victory BP Library|UMG", BlueprintCallable, BlueprintCosmetic, Meta = (DefaultToSelf = "ParentWidget", DeterminesOutputType = "WidgetClass", DynamicOutputParam = "ChildWidgets"))
	static void WidgetGetChildrenOfClass(UWidget* ParentWidget, TArray<UUserWidget*>& ChildWidgets, TSubclassOf<UUserWidget> WidgetClass, bool bImmediateOnly);
	 
	//~~~~~~~~~~~~~~~~
	//  Image Files!
	//~~~~~~~~~~~~~~~~
	
	/** Load a Texture2D from a JPG,PNG,BMP,ICO,EXR,ICNS file! IsValid tells you if file path was valid or not. Enjoy! -Rama */
	UFUNCTION(BlueprintCallable, Category = "Victory BP Library|Load Texture From File",meta=(Keywords="image png jpg jpeg bmp bitmap ico icon exr icns"))
	static UTexture2D* Victory_LoadTexture2D_FromFile(const FString& FullFilePath,EJoyImageFormats ImageFormat,bool& IsValid, int32& Width, int32& Height);
	
	/** Load a Texture2D from a JPG,PNG,BMP,ICO,EXR,ICNS file! IsValid tells you if file path was valid or not. The image type is assumed from an extension such as .jpg, .png, .bmp. Enjoy! -Rama */
	UFUNCTION(BlueprintCallable, Category = "Victory BP Library|Load Texture From File",meta=(Keywords="image png jpg jpeg bmp bitmap ico icon exr icns"))
	static UTexture2D* Victory_LoadTexture2D_FromFileByExtension(const FString& FullFilePath,bool& IsValid, int32& Width, int32& Height);
	
	//~~~~~~~~~~~~
	// Capture 2D
	//~~~~~~~~~~~~
	
	/** Contributed by Community Member Kris! */
	UFUNCTION(Category = "Victory BP Library|SceneCapture", BlueprintPure)
	static bool CaptureComponent2D_Project(class USceneCaptureComponent2D* Target, FVector Location, FVector2D& OutPixelLocation);

	/** Contributed by Community Member Kris! */
	UFUNCTION(Category = "Victory BP Library|SceneCapture", BlueprintPure, Meta = (DefaultToSelf = "Target"))
	static bool Capture2D_Project(class ASceneCapture2D* Target, FVector Location, FVector2D& OutPixelLocation);

	/** 
		I highly recommend that your Texture Render Target Format be "RTF RGB8 SRGB" both so it is compatible, and so it looks the same as in-game 
			<3 Rama. 
			
		Make sure to include the appropriate image extension in your file path! Recommended: .bmp, .jpg, .png. Contributed by Community Member Kris! 
	*/
	UFUNCTION(Category = "Victory BP Library|SceneCapture", BlueprintCallable)
	static bool CaptureComponent2D_SaveImage(class USceneCaptureComponent2D* Target, const FString ImagePath, const FLinearColor ClearColour);

	/** 
		I highly recommend that your Texture Render Target Format be "RTF RGB8 SRGB" both so it is compatible, and so it looks the same as in-game 
			<3 Rama. 
			
		Make sure to include the appropriate image extension in your file path! Recommended: .bmp, .jpg, .png. Contributed by Community Member Kris! 
	*/
	UFUNCTION(Category = "Victory BP Library|SceneCapture", BlueprintCallable, Meta = (DefaultToSelf = "Target"))
	static bool Capture2D_SaveImage(class ASceneCapture2D* Target, const FString ImagePath, const FLinearColor ClearColour);
	
	//~~~~~~~~~~~~
	// 	  Misc
	//~~~~~~~~~~~~
	/**
	 * Get All Bone Names Below Bone, requires a physics asset, by Rama
	 *
	 * @param StartingBoneName The name of the bone to find all bones below.
	 *
	 * @param BoneNames , all of the bone names below the starting bone.
	 *
	 * @return total number of bones found
	 */
	UFUNCTION(BlueprintCallable, Category="Victory BP Library|Components|SkinnedMesh")
	static int32 GetAllBoneNamesBelowBone(USkeletalMeshComponent* SkeletalMeshComp, FName StartingBoneName,  TArray<FName>& BoneNames );
	
	//~~~~~~~~~~~~
	// 	File I/O
	//~~~~~~~~~~~~

	UFUNCTION(BlueprintCallable, Category = "Victory BP Library|File IO")
	static FDateTime Victory_GetFileTimeStamp(const FString& File);
	
	UFUNCTION(BlueprintCallable, Category = "Victory BP Library|File IO")
	static void Victory_SetTimeStamp(const FString& File, const FDateTime& TimeStamp);

	/** Obtain all files in a provided directory, with optional extension filter. All files are returned if Ext is left blank. Returns false if operation could not occur. */
	UFUNCTION(BlueprintPure, Category = "Victory BP Library|File IO")
	static bool Victory_GetFiles(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);

	/** Obtain all files in a provided root directory, including all subdirectories, with optional extension filter. All files are returned if Ext is left blank. The full file path is returned because the file could be in any subdirectory. Returns false if operation could not occur. */
	UFUNCTION(BlueprintPure, Category = "Victory BP Library|File IO")
	static bool Victory_GetFilesInRootAndAllSubFolders(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);
	
	//~~~~~~~~~~
	// 	OS
	//~~~~~~~~~~
	
	UFUNCTION(BlueprintPure, Category = "Victory BP Library|String")
	static void Victory_GetStringFromOSClipboard(FString& FromClipboard);

	UFUNCTION(BlueprintCallable, Category = "Victory BP Library|String")
	static void Victory_SaveStringToOSClipboard(const FString& ToClipboard);
	
	/** Is the Current Game Window the Foreground window in the OS, or in the Editor? This will be accurate in standalone running of the game as well as in the editor PIE */
	UFUNCTION(BlueprintPure, Category = "Victory BP Library|Game Window")
	static bool ClientWindow__GameWindowIsForeGroundInOS();
	
	//~~~~~~~~~~~~~~
	// 	Windows OS
	//~~~~~~~~~~~~~~
	
	/** Flashes the game on the windows OS task bar! Please note this won't look the best in PIE, flashing is smoother in Standalone or packaged game. You can use GameWindowIsForeGroundInOS to see if there is a need to get the user's attention! <3 Rama */
	UFUNCTION(BlueprintCallable, Category = "Victory BP Library|Game Window")
	static void FlashGameOnTaskBar(APlayerController* PC, bool FlashContinuous=false, int32 MaxFlashCount = 3, int32 FlashFrequencyMilliseconds=500);
};
