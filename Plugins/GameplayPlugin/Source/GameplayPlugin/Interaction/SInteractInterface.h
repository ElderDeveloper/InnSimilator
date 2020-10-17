// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SInteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class USInteractInterface : public UInterface
{
	GENERATED_BODY()
    public:
  
    
};


class GAMEPLAYPLUGIN_API ISInteractInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    virtual void RequestInteract(AActor* RequestOwner)=0;
    virtual void RequestHold(AActor* RequestOwner)=0;
    virtual void RequestDetach(AActor* RequestOwner)=0;
    virtual void RequestTrigger(AActor* RequestOwner)=0;
};
