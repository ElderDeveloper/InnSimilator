
#include "InteractActorCore.h"

#include "Engine/Engine.h"
#include "GameplayPlugin/Player/SPlayer.h"
#include "GameplayPlugin/Player/SPlayerInterface.h"


void AInteractActorCore::RequestInteract(AActor* RequestOwner)
{
    
    
    switch (ActorInteractType)
    {
        case Hold:
            {
            HoldEvents(RequestOwner);
              break;
            }

        case Trigger:
            {
                ActorInteractTrigger(RequestOwner);
                ActorInteractTrigger_Implementation(RequestOwner);
                break;
            }

        case NPC:
            {
                break;
            }
        case Use:
        {
            HoldEvents(RequestOwner);
            break;
        }
         default: ;
    }
 
   
}

void AInteractActorCore::HoldEvents(AActor* RequestOwner)
{
    ASPlayer*LocalPlayer=Cast<ASPlayer>(RequestOwner);
    
    if (LocalPlayer->ItemInHand==nullptr)
    {
        LocalPlayer->ItemInHand=this;
        RequestHold(RequestOwner);
    }
    else
    {
        AInteractActorCore* PlayerHoldingItem=Cast<AInteractActorCore>(LocalPlayer->ItemInHand);
        PlayerHoldingItem->RequestDetach(RequestOwner);
        
        LocalPlayer->ItemInHand=this;
        RequestHold(RequestOwner);
    }
}

void AInteractActorCore::RequestDetach(AActor* RequestOwner)
{
    ActorInteractDetach(RequestOwner);
    ActorInteractDetach_Implementation(RequestOwner);
}

void AInteractActorCore::RequestHold(AActor* RequestOwner)
{
    
    ActorInteractHold(RequestOwner);
    ActorInteractHold_Implementation(RequestOwner);
}








void AInteractActorCore::RequestTrigger(AActor* RequestOwner){}

void AInteractActorCore::ActorInteractDetach_Implementation(AActor* ActorToHold){}

void AInteractActorCore::ActorInteractHold_Implementation(AActor* ActorToHold){}

void AInteractActorCore::ActorInteractTrigger_Implementation(AActor* RequestOwner){}
