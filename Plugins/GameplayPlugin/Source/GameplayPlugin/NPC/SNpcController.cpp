// Fill out your copyright notice in the Description page of Project Settings.


#include "SNpcController.h"

void ASNpcController::BeginPlay()
{
    Super::BeginPlay();

    RunBehaviorTree(NpcBehaviorTree);
}
