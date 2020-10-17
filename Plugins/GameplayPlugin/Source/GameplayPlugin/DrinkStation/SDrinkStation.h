#pragma once
#include "GameplayPlugin/Interaction/InteractActorCore.h"
#include "SDrinkStation.generated.h"

UCLASS()
class ASDrinkStation : public AInteractActorCore
{
    GENERATED_BODY()

    ASDrinkStation();
public:

    
    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UStaticMeshComponent* Barrel;

    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UStaticMeshComponent* Vana;

    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UBoxComponent*GlassInteractBox;

    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UParticleSystemComponent* OpenParticle;

    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
    bool Open;

    FTimerHandle GlassFillHandle;

    float GlassFillTimerSpeed=0.05;

    virtual void RequestInteract(AActor* RequestOwner) override;

    void FillGlass();
};
