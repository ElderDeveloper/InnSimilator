#include "SPlayer.h"

#include <xkeycheck.h>



#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Engine/Engine.h"
#include "Engine/EngineTypes.h"
#include "GameplayPlugin/Interaction/InteractActorCore.h"
#include "GameplayPlugin/Interaction/SInteractInterface.h"



ASPlayer::ASPlayer()
{
   
   ArmComponent=CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm Component"));
   ArmComponent->SetupAttachment(GetMesh());
   ArmComponent->TargetArmLength=0;
 
   PlayerCameracomp=CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCameraa"));
   PlayerCameracomp->SetupAttachment(ArmComponent);
   
}

void ASPlayer::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    TraceForInteract();
}

void ASPlayer::BeginPlay()
{
    Super::BeginPlay();
}

void ASPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    if (!PlayerInputComponent)
    return;

    PlayerInputComponent->BindAction(InteractBindName,EInputEvent::IE_Pressed,this,&ASPlayer::Interact);
    PlayerInputComponent->BindAxis(MoveForwardAxisName,this,&ASPlayer::MoveForward);
    PlayerInputComponent->BindAxis(MoveRightAxisName,this,&ASPlayer::MoveRight);
    PlayerInputComponent->BindAxis(TurnAxisName,this,&ASPlayer::Turn);
    PlayerInputComponent->BindAxis(LookUpAxisName,this,&ASPlayer::LookUp);
}

void ASPlayer::DetachItemInHand()
{
    if (ItemInHand)
    {
        AInteractActorCore* LocalInteractActor = Cast<AInteractActorCore>(ItemInHand);
        LocalInteractActor->RequestDetach(this);
        ItemInHand=nullptr;
    }
}


void ASPlayer::TraceForInteract()
{
    
    const TArray<AActor*> EmptyArray;
    FHitResult TraceHit;

    if (PlayerCameracomp)
    {
     const FVector CalculateForward=PlayerCameracomp->GetForwardVector()*InteractDistance;
     const FVector EndLoc=CalculateForward+PlayerCameracomp->GetComponentLocation();
        
    const bool TraceSuccess= UKismetSystemLibrary::SphereTraceSingle(this,PlayerCameracomp->GetComponentLocation(),EndLoc,InteractRadius,
    InteractTraceType,false,EmptyArray,InteractDrawType,TraceHit,true);

     if (TraceSuccess && TraceHit.GetActor())
     {
         SeenActor=TraceHit.GetActor();
         return;
     }
        SeenActor=nullptr;
    }
  
   
}


void ASPlayer::Interact()
{
    if (SeenActor && SeenActor->Implements<USInteractInterface>())
    {
       ISInteractInterface* InteractedObject= Cast<ISInteractInterface>(SeenActor);
       if (InteractedObject)
       {
           InteractedObject->RequestInteract(this);
       }
    }
}












void ASPlayer::MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector(),Value);
}

void ASPlayer::MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector(),Value);
}

void ASPlayer::Turn(float Value)
{
    AddControllerYawInput(CameraSpeed*Value);
}

void ASPlayer::LookUp(float Value)
{
    AddControllerPitchInput(CameraSpeed*Value);
}
