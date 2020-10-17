#include "SNpc.h"
#include "SNpcController.h"


ASNpc::ASNpc()
{
    AIControllerClass=NpcController;
}

void ASNpc::RequestMotivationChange(float Amount)
{
}

void ASNpc::RequestInteract(AActor* RequestOwner)
{
}

void ASNpc::RequestHold(AActor* RequestOwner)
{
}

void ASNpc::RequestDetach(AActor* RequestOwner)
{
}

void ASNpc::RequestTrigger(AActor* RequestOwner)
{
}

void ASNpc::BeginPlay()
{
    Super::BeginPlay();
}

void ASNpc::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}
