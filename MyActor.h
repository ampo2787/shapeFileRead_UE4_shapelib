// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "shapefil.h"
#include "Engine/Engine.h"
#include "ProceduralMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"


UCLASS()
class SHP_CODING_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	TArray<SHPObject *> shapeObjects; //shp파일에서 가져온 object이 저장되는 배열.

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostLoad() override;
	virtual void PostActorCreated() override;
	void CreateRoadMap();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float RunningTime;
	int pnEntities = 0;
	int pnShapeType = 0;
	double padfMinBound[4];
	double padfMaxBound[4];

	int Iteration = 10;
	int TimeToSpawn = 1;

private:
	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent  *  mesh;
	
};
