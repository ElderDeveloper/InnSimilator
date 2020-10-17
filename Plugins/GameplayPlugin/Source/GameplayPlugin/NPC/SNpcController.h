// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SNpcController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYPLUGIN_API ASNpcController : public AAIController
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree*NpcBehaviorTree;

	
	virtual void BeginPlay() override;
};
