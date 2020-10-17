#pragma once
#include "GameplayPlugin/Interaction/InteractActorCore.h"
#include "SUseableCore.generated.h"

UCLASS()
class ASUseableCore : public AInteractActorCore
{
    GENERATED_BODY()

    public:
    
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
    UAnimMontage* UseMontage;
};
