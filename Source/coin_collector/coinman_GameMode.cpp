// Fill out your copyright notice in the Description page of Project Settings.


#include "coinman_GameMode.h"
#include "GameFramework/Actor.h"

 Acoinman_GameMode::Acoinman_GameMode(){
    PrimaryActorTick.bCanEverTick = true;
    
}
void Acoinman_GameMode::BeginPlay(){
    Super::BeginPlay();
    FTimerHandle UnusedHandle;
              
    GetWorldTimerManager().SetTimer(UnusedHandle,this,&Acoinman_GameMode::SpawnPlayerRecharge,FMath::RandRange(2,5),true);
    
}


void Acoinman_GameMode::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
}

void Acoinman_GameMode::SpawnPlayerRecharge(){
    float RandX = FMath::RandRange(spawn_X_min, spawn_X_max);
    float RandY = FMath::RandRange(spawn_Y_min, spawn_Y_max);
    
    FVector SpawnPosition = FVector(RandX, RandY, spawn_Z);
    FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
    
    GetWorld()->SpawnActor(PlayerRecharge,&SpawnPosition,&SpawnRotation);
    
}
