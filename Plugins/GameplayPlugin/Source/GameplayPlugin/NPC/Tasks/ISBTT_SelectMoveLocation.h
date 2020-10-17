#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ISBTT_SelectMoveLocation.generated.h"

UCLASS()
class UISBTT_SelectMoveLocation : public UBTTaskNode
{
    GENERATED_BODY()
    
public:

    UPROPERTY()
    UBlackboardComponent* BlackboardComp;
    UPROPERTY()
    AAIController* TaskController;
    class ACharacter* ControlledCharacter;

    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector LocationKey;

    UPROPERTY(EditAnywhere)
    float RoamDistance=2000.f;

	
    // Virtual Events
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    virtual void OnGameplayTaskActivated(UGameplayTask& Task) override {}
    
};
