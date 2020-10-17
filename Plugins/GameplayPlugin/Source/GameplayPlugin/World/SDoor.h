// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameplayPlugin/Interaction/InteractActorCore.h"
#include "SDoor.generated.h"


/**
 * 
 */
UCLASS()
class ASDoor : public AInteractActorCore
{
	GENERATED_BODY()
	
public:
	
	ASDoor();

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
	class USceneComponent* SceneRoot;
	
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadWrite)
	class UStaticMeshComponent* Mesh;

	virtual void RequestInteract(AActor* RequestOwner) override;
	
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool Closed;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float DoorOpenAngle=110;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TEnumAsByte<EEasingFunc::Type> EaseType=EEasingFunc::EaseInOut;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool Locked;
	

	//Sound Variables
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Door Sound")
	class USoundBase* LockSound;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Door Sound")
	class USoundBase* UnlockSound;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Door Sound")
	class USoundBase* OpenSound;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Door Sound")
	class USoundBase* CloseSound;
	
public:



	UFUNCTION()
	void OnFinished();

	UFUNCTION()
	void InterpReturn(float value);

	FOnTimelineFloat InterpFunction;
	FOnTimelineEvent TimeLineFinish;

	UPROPERTY()
	UTimelineComponent*DoorTimeline;

	UPROPERTY(EditAnywhere)
	UCurveFloat*CurveFloat;
};
