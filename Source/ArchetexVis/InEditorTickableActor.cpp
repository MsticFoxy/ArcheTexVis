// Fill out your copyright notice in the Description page of Project Settings.


#include "InEditorTickableActor.h"

// Sets default values
AInEditorTickableActor::AInEditorTickableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInEditorTickableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Separated Tick functionality and making sure that it truly can only happen in the editor. 
//Might be a bit overkill but you can easily consolidate if you'd like. 
void AInEditorTickableActor::Tick(float DeltaTime)
{
	if (GetWorld() != nullptr && GetWorld()->WorldType == EWorldType::Editor)
	{
#if WITH_EDITOR
		BlueprintEditorTick(DeltaTime);
#endif
	}
	else
	{
		Super::Tick(DeltaTime);
	}
}

// This ultimately is what controls whether or not it can even tick at all in the editor view port. 
//But, it is EVERY view port so it still needs to be blocked from preview windows and junk.
bool AInEditorTickableActor::ShouldTickIfViewportsOnly() const
{
	if (GetWorld() != nullptr && GetWorld()->WorldType == EWorldType::Editor && UseEditorTick)
	{
		return true;
	}
	else
	{
		return false;
	}
}


