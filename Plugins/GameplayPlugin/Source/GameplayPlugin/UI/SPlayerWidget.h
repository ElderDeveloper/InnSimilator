// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ObjectMacros.h"

#include "SPlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYPLUGIN_API USPlayerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	int32 PlayerGold;
};
