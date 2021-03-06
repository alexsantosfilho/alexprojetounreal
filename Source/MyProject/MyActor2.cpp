// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyActor2.h"


// Sets default values
AMyActor2::AMyActor2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;
	//CollisionComp->OnComponentHit.AddDynamic(this, &AMyActor::OnHit);
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{


	Super::Tick(DeltaTime);

	FVector LocalizacaoAtual = GetActorLocation();

	if (LocalizacaoAtual.X != LocalizacaoAtual.Y) {
		float DeltaWidth = (FMath::Sin(RunningTime + DeltaTime + Cont) - FMath::Sin(RunningTime));
		LocalizacaoAtual.X += DeltaWidth ;
		RunningTime += DeltaTime += Cont = 1;
		SetActorLocation(LocalizacaoAtual);
	}

	if (LocalizacaoAtual.Y != LocalizacaoAtual.X) {
		float DeltaWidth = (FMath::Sin(RunningTime + DeltaTime +) - FMath::Sin(RunningTime));
		LocalizacaoAtual.Y += DeltaWidth;
		RunningTime += DeltaTime += Cont2 = 1000;
		SetActorLocation(LocalizacaoAtual);
	}



}

//else if (LocalizacaoAtual.X != LocalizacaoAtual.Y) {
//float DeltaHeight = (FMath::Sin(RunningTime - DeltaTime) - FMath::Sin(RunningTime));
//LocalizacaoAtual.X += DeltaHeight * 150.0f;
//RunningTime += DeltaTime;
//SetActorLocation(LocalizacaoAtual);
//}

//}





void AMyActor2::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	//if (OtherActor && (OtherActor != this) && OtherComp)
	//{
	//OtherComp->AddImpulseAtLocation(AMyActor->Velocity * 100.0f, Hit.ImpactPoint);
	//}
}



