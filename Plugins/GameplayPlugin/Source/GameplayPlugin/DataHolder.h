#pragma once

#include "DataHolder.generated.h"

UENUM(BlueprintType)
enum InteractType
{
    Hold  UMETA(DisplayName="Hold"),
    Trigger UMETA(DisplayName="Trigger"),
    NPC UMETA(DisplayName="NPC"),
    Use UMETA(DisplayName="Use")
    
};
