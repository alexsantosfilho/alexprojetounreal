// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "MyActorp.h"


// Sets default values
AMyActorp::AMyActorp()
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
void AMyActorp::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyActorp::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	FVector LocalizacaoAtual = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	LocalizacaoAtual.Z += DeltaHeight * 100.0f;
	RunningTime += DeltaTime;
	SetActorLocation(LocalizacaoAtual);


}

//else if (LocalizacaoAtual.X != LocalizacaoAtual.Y) {
//float DeltaHeight = (FMath::Sin(RunningTime - DeltaTime) - FMath::Sin(RunningTime));
//LocalizacaoAtual.X += DeltaHeight * 150.0f;
//RunningTime += DeltaTime;
//SetActorLocation(LocalizacaoAtual);
//}

//}





void AMyActorp::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	//if (OtherActor && (OtherActor != this) && OtherComp)
	//{
	//OtherComp->AddImpulseAtLocation(AMyActor->Velocity * 100.0f, Hit.ImpactPoint);
	//}
}



