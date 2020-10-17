#pragma once

#include "EngineMinimal.h"
#include "SInteractInterface.h"
#include "GameplayPlugin/DataHolder.h"
#include "InteractActorCore.generated.h"

UCLASS()
class AInteractActorCore : public AActor , public ISInteractInterface
{
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite,EditDefaultsOnly,Category="Interaction")
    TEnumAsByte<InteractType> ActorInteractType;
    UPROPERTY(BlueprintReadWrite,EditDefaultsOnly,Category="Interaction|Hold")
    FName HoldSocketName="ItemHoldSocket";
    UPROPERTY(BlueprintReadWrite,EditDefaultsOnly,Category="Interaction|Hold")
    FVector HoldRelativeLocation;
    UPROPERTY(BlueprintReadWrite,EditDefaultsOnly,Category="Interaction|Hold")
    FRotator HoldRelativeRotation;
 
    
    
public:
    virtual void RequestInteract(AActor* RequestOwner) override;
    virtual void RequestDetach(AActor* RequestOwner) override;
    virtual void RequestHold(AActor* RequestOwner) override;
    virtual void RequestTrigger(AActor* RequestOwner) override;

    void HoldEvents(AActor* RequestOwner);
    UFUNCTION(BlueprintNativeEvent)
    void ActorInteractHold(AActor* ActorToHold);

    UFUNCTION(BlueprintNativeEvent)
    void ActorInteractDetach(AActor* ActorToHold);
    
    UFUNCTION(BlueprintNativeEvent)
    void ActorInteractTrigger(AActor* RequestOwner);
};

