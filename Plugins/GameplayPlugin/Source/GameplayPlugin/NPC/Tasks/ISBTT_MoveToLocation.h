// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ISBTT_MoveToLocation.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYPLUGIN_API UISBTT_MoveToLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
	UPROPERTY()
	UBlackboardComponent* BlackboardComp;
	UPROPERTY()
	AAIController* TaskController;
	class ACharacter* ControlledCharacter;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector LocationKey;

	UPROPERTY(EditAnywhere)
	float AcceptRadius=30;
	
	// Virtual Events
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override {}
};
