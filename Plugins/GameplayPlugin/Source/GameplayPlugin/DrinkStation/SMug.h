#pragma once
#include "SDrinkStationInterface.h"
#include "GameplayPlugin/Interaction/InteractActorCore.h"
#include "SMug.generated.h"

UCLASS()
class ASMug : public AInteractActorCore , public ISDrinkStationInterface
{
    GENERATED_BODY()

    ASMug();
    
public:


    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UStaticMeshComponent* Mug;

    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class USceneComponent* Scene;
    
    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UStaticMeshComponent* CylinderForFill;

    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UBoxComponent*DrinkStationInteraction;
    
    virtual void FillMug() override;
    virtual void RequestHold(AActor* RequestOwner)override;
    virtual void RequestDetach(AActor* RequestOwner) override;
};
