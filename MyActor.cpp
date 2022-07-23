// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	startlocation=GetActorLocation();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovingPlatform(DeltaTime);
	RotatingPlatform(DeltaTime);
}

void AMyActor::MovingPlatform(float DeltaTime)
{
		if(ShouldPlatformReturn())
		{
			FVector MoveDirection=PlatformVelocity.GetSafeNormal();
			startlocation=startlocation+MoveDirection*dist;
			SetActorLocation(startlocation);
			PlatformVelocity=-PlatformVelocity;
		}
		else
		{
			FVector currentlocation=GetActorLocation();
			currentlocation=currentlocation+PlatformVelocity*DeltaTime;
			SetActorLocation(currentlocation);
		}
}

void AMyActor::RotatingPlatform(float DeltaTime)
{
	FRotator CurrentRoation=GetActorRotation();
	CurrentRoation=CurrentRoation+(RotationVelocity*DeltaTime);
	SetActorRotation(CurrentRoation);

}
bool AMyActor::ShouldPlatformReturn() const
{
	double distance=FVector::Dist(startlocation,GetActorLocation());
	return distance> dist;
}
