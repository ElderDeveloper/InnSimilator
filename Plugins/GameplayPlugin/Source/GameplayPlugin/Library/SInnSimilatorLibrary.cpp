// Fill out your copyright notice in the Description page of Project Settings.


#include "SInnSimilatorLibrary.h"
#include "Engine.h"
#include "GameplayPlugin/Core/SInnGameMode.h"



void USInnSimilatorLibrary::AddGoldToPlayer(UObject* WorldContextObject, int32 Amount)
{
    ASInnGameMode* GM= GetInnGameMode(WorldContextObject);
    if (GM)
    {
        GM->PlayerGold=GM->PlayerGold+Amount;
        GM->PlayerGoldDelegate.Broadcast();
    }
}


void USInnSimilatorLibrary::RemoveGoldFromPlayer(UObject* WorldContextObject, int32 Amount)
{
    ASInnGameMode* GM= GetInnGameMode(WorldContextObject);
    if (GM)
    {
        GM->PlayerGold=GM->PlayerGold-Amount;
        GM->PlayerGoldDelegate.Broadcast();
    }
}


int32 USInnSimilatorLibrary::GetPlayerGold(UObject* WorldContextObject)
{
    ASInnGameMode* GM= GetInnGameMode(WorldContextObject);
    if (GM)
    {
        return GM->PlayerGold;
    }
    return 0;
}


ASInnGameMode* USInnSimilatorLibrary::GetInnGameMode(UObject* WorldContextObject)
{
    UWorld * World = GEngine->GetWorldFromContextObject(WorldContextObject,EGetWorldErrorMode::ReturnNull);
    if (World)
    {
        ASInnGameMode*GM=Cast<ASInnGameMode>(UGameplayStatics::GetGameMode(World));
        if (GM)
        {
            return GM;
        }
    }
    return NULL;
}