// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenerateMaze.generated.h"



USTRUCT(BlueprintType)
struct FCell
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly)
		TArray<bool> sides;

	UPROPERTY()
		int32 index;

	UPROPERTY()
		bool visited;

	FCell()
	{
		sides.SetNum(4, true);
		sides[0] = true;
		sides[1] = true;
		sides[2] = true;
		sides[3] = true;
		visited = false;
		index = -1;
	}
};

/**
 * 
 */
UCLASS()
class UE4JAMFEB2016_API UGenerateMaze : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
	UFUNCTION(BlueprintCallable, Category = "Generate")
		static TArray<FCell> GenerateMaze(int32 mazeWidth, int32 mazeLength, int32 seed);
	
	
};