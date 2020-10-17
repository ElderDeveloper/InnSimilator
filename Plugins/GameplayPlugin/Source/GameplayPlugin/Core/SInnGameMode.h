// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SInnGameMode.generated.h"

/**
 * 
*/

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerGoldChanged);

UCLASS()
class GAMEPLAYPLUGIN_API ASInnGameMode : public AGameModeBase
{
	GENERATED_BODY()


	public:

	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FOnPlayerGoldChanged PlayerGoldDelegate;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	int32 PlayerGold=0;
};
