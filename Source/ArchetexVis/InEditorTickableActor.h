// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InEditorTickableActor.generated.h"

UCLASS()
class ARCHETEXVIS_API AInEditorTickableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInEditorTickableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Allows Tick To happen in the editor viewport*/
	virtual bool ShouldTickIfViewportsOnly() const override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool UseEditorTick = false;

	/** Tick that runs ONLY in the editor viewport.*/
	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "Events")
		void BlueprintEditorTick(float DeltaTime);

};
