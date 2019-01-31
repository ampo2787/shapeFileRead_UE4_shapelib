// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SHPHandle shpHandle = SHPOpen("C:/Users/kbsungNormal/Documents/Unreal Projects/shp_coding/Source/shp_coding/map/K-CITY_20181130/1_LANE_LINK", "rb");

	SHPGetInfo(shpHandle, &pnEntities, &pnShapeType, padfMinBound, padfMaxBound);
	//shp 파일 정보 가져와 변수들에 저장.

	for (int i = 0; i < pnEntities; i++) {
		SHPObject *shapeObject = SHPReadObject(shpHandle, i);
		shapeObjects.Emplace(shapeObject);
		//TArray 배열 shapeObjects 뒤에다가 계속 추가.
	}

	mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	RootComponent = mesh;
	// New in UE 4.17, multi-threaded PhysX cooking.
	mesh->bUseAsyncCooking = true;
}
void AMyActor::PostActorCreated()
{
	Super::PostActorCreated();
	CreateRoadMap();
}

void AMyActor::PostLoad()
{
	Super::PostLoad();
	CreateRoadMap();
}

void AMyActor::CreateRoadMap()
{
	//while (shapeObjects.Num() != 0) {
		SHPObject *thisObject = shapeObjects.Pop();
		
		TArray<FVector> vertices;
		vertices.Add(FVector(0, 0, 0));
		vertices.Add(FVector(0, 100, 0));
		vertices.Add(FVector(0, 0, 100));

		TArray<int32> Triangles;
		Triangles.Add(0);
		Triangles.Add(1);
		Triangles.Add(2);

		TArray<FVector> normals;
		normals.Add(FVector(1, 0, 0));
		normals.Add(FVector(1, 0, 0));
		normals.Add(FVector(1, 0, 0));

		TArray<FVector2D> UV0;
		UV0.Add(FVector2D(0, 0));
		UV0.Add(FVector2D(10, 0));
		UV0.Add(FVector2D(0, 10));

		TArray<FProcMeshTangent> tangents;
		tangents.Add(FProcMeshTangent(0, 1, 0));
		tangents.Add(FProcMeshTangent(0, 1, 0));
		tangents.Add(FProcMeshTangent(0, 1, 0));

		TArray<FLinearColor> vertexColors;
		vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
		vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));
		vertexColors.Add(FLinearColor(0.75, 0.75, 0.75, 1.0));

		mesh->CreateMeshSection_LinearColor(0, vertices, Triangles, normals, UV0, vertexColors, tangents, true);

		// Enable collision data
		mesh->ContainsPhysicsTriMeshData(true);
	//}
}
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (Iteration > 0)
	{
		TimeToSpawn -= DeltaTime;
		if (TimeToSpawn < 0.f)
		{
			// Make a location for the new actor to spawn at (300 units above this actor)  
			FVector NewLocation = GetActorLocation() + FVector(0.f, 0.f, 300.f);

			// Spawn the new actor (Using GetClass() instead of AMySpawner so that if someone derives a new class  
			// from AMySpawner we spawn an instance of that class instead)  
			AMyActor* NewActor = GetWorld()->SpawnActor<AMyActor>(GetClass(), NewLocation, FRotator::ZeroRotator);
			NewActor->Iteration = Iteration - 1;
			// Housekeeping so that we dont spawn new actors forever  
			
			Iteration = 0; // stop ourselves spawning any more  
		}
	}
	*/
	
}
