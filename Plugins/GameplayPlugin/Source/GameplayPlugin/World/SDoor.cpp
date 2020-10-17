// Fill out your copyright notice in the Description page of Project Settings.


#include "SDoor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SceneComponent.h"
#include "Engine/Engine.h"


ASDoor::ASDoor()
{
    DoorTimeline=CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimeline"));
    InterpFunction.BindUFunction(this,FName("InterpReturn"));
    TimeLineFinish.BindUFunction(this,FName("OnFinished"));

    SceneRoot=CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SceneRoot->SetupAttachment(RootComponent);

    Mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
    Mesh->SetupAttachment(SceneRoot);

}



void ASDoor::RequestInteract(AActor* RequestOwner)
{
    GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,"Trigger");
    if (!Locked)
    {
        if (!Closed)
        {
            DoorTimeline->Play();
            UGameplayStatics::PlaySoundAtLocation(GetWorld(),OpenSound,GetActorLocation(),GetActorRotation());
        }
        else
        {
            DoorTimeline->Reverse();
            UGameplayStatics::PlaySoundAtLocation(GetWorld(),CloseSound,GetActorLocation(),GetActorRotation());
        }
        Closed=!Closed;
    }
    else { }
}

void ASDoor::BeginPlay()
{ 
    Super::BeginPlay();

    if (CurveFloat)
    {
        DoorTimeline->AddInterpFloat(CurveFloat,InterpFunction,FName("Alpha"));
        DoorTimeline->SetTimelineFinishedFunc(TimeLineFinish);
        DoorTimeline->SetLooping(false);
    }
}

void ASDoor::OnFinished()
{
}

void ASDoor::InterpReturn(float value)
{
    Mesh->SetRelativeRotation(FRotator(0,UKismetMathLibrary::Ease(0,DoorOpenAngle,value,EaseType),0));
}

