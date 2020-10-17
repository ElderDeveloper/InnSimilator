// Fill out your copyright notice in the Description page of Project Settings.


#include "ISBTT_MoveToLocation.h"
#include "GameFramework/Character.h"
#include "AIController.h"

EBTNodeResult::Type UISBTT_MoveToLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    BlackboardComp=OwnerComp.GetBlackboardComponent();
    TaskController=OwnerComp.GetAIOwner();
    ControlledCharacter = Cast<ACharacter>(TaskController->GetPawn());

    
    TaskController->MoveToLocation(BlackboardComp->GetValueAsVector(LocationKey.SelectedKeyName));
    
    return EBTNodeResult::InProgress;
}

void UISBTT_MoveToLocation::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    if (ControlledCharacter)
    {
        if (FVector(ControlledCharacter->GetActorLocation()-BlackboardComp->GetValueAsVector(LocationKey.SelectedKeyName)).Size()<=AcceptRadius)
        {
            FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
        }
    }
  
}
