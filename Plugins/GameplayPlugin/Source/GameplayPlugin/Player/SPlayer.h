#pragma once

#include "EngineMinimal.h"
#include "SPlayerInterface.h"

#include "Splayer.generated.h"

UCLASS()
class ASPlayer : public ACharacter , public ISPlayerInterface
{
    GENERATED_BODY()
    
    ASPlayer();
    
public:
    
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Player|Camera")
    float CameraSpeed=0.8f;

    UPROPERTY(BlueprintReadOnly,Category="Player|Interact")
    AActor*SeenActor;
    
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Player|Interact")
    float InteractDistance=200.f;

    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Player|Interact")
    float InteractRadius=30.f;

    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Player|Interact")
    TEnumAsByte<ETraceTypeQuery>  InteractTraceType;

    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Player|Interact")
    TEnumAsByte<EDrawDebugTrace::Type>  InteractDrawType;

    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Player|Interact|Hold")
    FName HoldSocketName="ItemHoldSocket";

    FAttachmentTransformRules* HoldTransformRoules;

    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Player")
    AActor*ItemInHand;
    
#pragma region Input
    UPROPERTY(EditDefaultsOnly,Category="Input")
    FName InteractBindName="Interact";
    
    UPROPERTY(EditDefaultsOnly,Category="Input")
    FName MoveForwardAxisName="MoveForward";

    UPROPERTY(EditDefaultsOnly,Category="Input")
    FName MoveRightAxisName="MoveRight";

    UPROPERTY(EditDefaultsOnly,Category="Input")
    FName TurnAxisName="Turn";

    UPROPERTY(EditDefaultsOnly,Category="Input")
    FName LookUpAxisName="LookUp";
#pragma endregion 


    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    USpringArmComponent* ArmComponent;
    UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
    class UCameraComponent* PlayerCameracomp;

    

protected:
    // Virtual Functions
    virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


    UFUNCTION(BlueprintCallable)
    void DetachItemInHand();
    
    
    //Movement Functions
    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);

    
    //No Blueprint Functions
    void TraceForInteract();
    UFUNCTION(BlueprintCallable)
    void Interact();

    
};
