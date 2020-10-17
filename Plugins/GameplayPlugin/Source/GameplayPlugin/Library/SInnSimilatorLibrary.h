// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SInnSimilatorLibrary.generated.h"

/**
 * 
 */
class  ASInnGameMode;
UCLASS()
class USInnSimilatorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable,meta=(WorldContext="WorldContextObject"))
    static void AddGoldToPlayer(UObject*WorldContextObject, int32 Amount);

    UFUNCTION(BlueprintCallable,meta=(WorldContext="WorldContextObject"))
    static void RemoveGoldFromPlayer(UObject*WorldContextObject,int32 Amount);

    UFUNCTION(BlueprintCallable,BlueprintPure,meta=(UObject=WorldContextObject,WorldContext="WorldContextObject"))
    static int32 GetPlayerGold(UObject*WorldContextObject);

    UFUNCTION(BlueprintCallable,BlueprintPure,meta=(UObject=WorldContextObject,WorldContext="WorldContextObject"))
    static ASInnGameMode* GetInnGameMode(UObject*WorldContextObject);

};

