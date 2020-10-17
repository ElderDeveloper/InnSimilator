#include "ISBTT_SelectMoveLocation.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "NavigationSystem.h"

EBTNodeResult::Type UISBTT_SelectMoveLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    BlackboardComp=OwnerComp.GetBlackboardComponent();
    TaskController=OwnerComp.GetAIOwner();
    ControlledCharacter = Cast<ACharacter>(TaskController->GetPawn());

    FNavLocation FoundLocation;
    UNavigationSystemV1* NavSys= UNavigationSystemV1::GetCurrent(GetWorld());
    NavSys->GetRandomPointInNavigableRadius(ControlledCharacter->GetActorLocation(),RoamDistance,FoundLocation);
    BlackboardComp->SetValueAsVector(LocationKey.SelectedKeyName,FoundLocation);
    
    return EBTNodeResult::Succeeded;
}

