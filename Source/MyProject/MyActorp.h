// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActorp.generated.h"

UCLASS()
class MYPROJECT_API AMyActorp :public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActorp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

private:

	UPROPERTY(EditAnywhere)
		UShapeComponent* Root;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime = 1;
	UPROPERTY(VisibleAnywhere, Category = Tick)
		float RunningTime2 = 2;


	UFUNCTION()
		void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult& Hit);


};
