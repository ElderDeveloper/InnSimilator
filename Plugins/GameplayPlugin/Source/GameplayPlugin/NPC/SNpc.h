#pragma once
#include "GameFramework/Character.h"
#include "GameplayPlugin/Interaction/InteractActorCore.h"
#include "SNpc.generated.h"

UENUM(BlueprintType)
enum ENpcSex
{
    MALE UMETA(DisplayName="Male"),
    FEMALE UMETA(DisplayName="Female"),
    UNDEFINED UMETA(DisplayName = "Undefined")
};

UENUM(BlueprintType)
enum ENpcMotivation
{
    HAPPY UMETA(DisplayName="Happy"),
    SAD UMETA(DisplayName="Sad"),
    BROKE UMETA(DisplayName = "Broke"),
    ANGRY UMETA(DisplayName="Angry")
};


UCLASS()
class ASNpc : public ACharacter , public ISInteractInterface
{
    GENERATED_BODY()
public:
    
 
    ASNpc();

    //Variables Stats
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Stats")
    TEnumAsByte<ENpcSex> NpcSex;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Stats")
    float NpcWalkSpeed=200;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Stats")
    float NpcRunSpeed=600;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Stats")
    float NpcMotivation=100;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Stats")
    float NpcMaxMotivation=100;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Stats")
    float NpcPositiveReaction=1;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Stats")
    float NpcNegativeReaction=1;

    //Variables AI
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|AI")
    TSubclassOf<class ASNpcController> NpcController;

    //Variables Animations
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Animations")
    class UBlendSpaceBase* WalkBlendSpace;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Animations")
    class UBlendSpaceBase* RunBlendSpace;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Animations")
    class UAnimSequenceBase*DrinkAnimation;
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NPC|Animations")
    class UAnimMontage* DrinkMontage;
    

    //Functions
    UFUNCTION(BlueprintCallable)
    void RequestMotivationChange(float Amount);
    
    // Virtual Events From Interact Interface
    virtual void RequestInteract(AActor* RequestOwner) override;
    virtual void RequestHold(AActor* RequestOwner) override;
    virtual void RequestDetach(AActor* RequestOwner) override;
    virtual void RequestTrigger(AActor* RequestOwner) override;


    //Virtual Events Actor
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
};
