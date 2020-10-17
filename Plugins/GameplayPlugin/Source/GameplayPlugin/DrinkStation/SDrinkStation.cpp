#include "SDrinkStation.h"

#include "SDrinkStationInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Particles/ParticleSystemComponent.h"

ASDrinkStation::ASDrinkStation()
{
    Barrel=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));
    Barrel->SetupAttachment(RootComponent);

    Vana=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Vana"));
    Vana->SetupAttachment(Barrel);

    GlassInteractBox=CreateDefaultSubobject<UBoxComponent>(TEXT("GlassInteractBox"));
    GlassInteractBox->SetupAttachment(Barrel);
    
    OpenParticle=CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OpenParticle"));
    OpenParticle->SetupAttachment(Barrel);
}

void ASDrinkStation::RequestInteract(AActor* RequestOwner)
{
    if (Open)
    {
        OpenParticle->SetActive(false,false);
        Open=false;
        GlassInteractBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        GetWorld()->GetTimerManager().ClearTimer(GlassFillHandle);
    }
    else
    {
        OpenParticle->SetActive(true,false);
        Open=true;
        GlassInteractBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
        GetWorld()->GetTimerManager().SetTimer(GlassFillHandle,this,&ASDrinkStation::FillGlass,GlassFillTimerSpeed,true);
    }
}

void ASDrinkStation::FillGlass()
{
    TArray<AActor*> OverlappingActors;
    TSubclassOf<AActor> Act;
    GlassInteractBox->GetOverlappingActors(OverlappingActors,Act);
    for (auto i : OverlappingActors)
    {
        if (i)
        {
            ISDrinkStationInterface* DrinkStationInterface=Cast<ISDrinkStationInterface>(i);
            if (DrinkStationInterface)
            {
                DrinkStationInterface->FillMug();
            }
        }
    }
}
