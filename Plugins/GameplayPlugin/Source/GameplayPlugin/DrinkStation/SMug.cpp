#include "SMug.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/Engine.h"
#include "Engine/EngineTypes.h"

ASMug::ASMug()
{
    Mug=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mug"));
    Mug->SetupAttachment(RootComponent);
    Mug->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Mug->SetSimulatePhysics(true);
    
    
    Scene=CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    Scene->SetupAttachment(Mug);

    CylinderForFill=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CylinderForFill"));
    CylinderForFill->SetupAttachment(Scene);
    CylinderForFill->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    DrinkStationInteraction=CreateDefaultSubobject<UBoxComponent>(TEXT("DrinkStationInteraction"));
    DrinkStationInteraction->SetupAttachment(Mug);
}

void ASMug::FillMug()
{
    FVector NextScale=Scene->GetRelativeScale3D()+ 0.005f;
    NextScale.X=FMath::Clamp(NextScale.X,0.0f,0.115f);
    NextScale.Y=FMath::Clamp(NextScale.Y,0.0f,0.115f);
    NextScale.Z=FMath::Clamp(NextScale.Z,0.0f,0.15f);
    Scene->SetRelativeScale3D(NextScale);
}

void ASMug::RequestHold(AActor* RequestOwner)
{
    Mug->SetSimulatePhysics(false);
    Mug->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    ACharacter* LocalPlayer = Cast<ACharacter>(RequestOwner);
    if (!LocalPlayer) { return; }
    USceneComponent* LocalSceneComp=Cast<USceneComponent>(LocalPlayer->GetMesh());
    if (!LocalSceneComp)  { return; }
    const FAttachmentTransformRules AttachmentRoules(EAttachmentRule::SnapToTarget,EAttachmentRule::SnapToTarget,EAttachmentRule::KeepRelative,true);
    Mug->AttachToComponent(LocalSceneComp,AttachmentRoules,HoldSocketName);
    Mug->SetRelativeLocationAndRotation(HoldRelativeLocation,HoldRelativeRotation);
}



void ASMug::RequestDetach(AActor* RequestOwner)
{
    Mug->SetSimulatePhysics(true);
    Mug->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Mug->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld,EDetachmentRule::KeepWorld,EDetachmentRule::KeepWorld,true));
}
