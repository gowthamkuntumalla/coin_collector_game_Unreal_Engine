// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "coinman_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class COIN_COLLECTOR_API Acoinman_GameMode : public AGameMode
{
	GENERATED_BODY()
    
    Acoinman_GameMode();
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    
    UPROPERTY (EditAnywhere)
    TSubclassOf<APawn> PlayerRecharge;
    
    
    float spawn_Z = 500.0f;
    
    UPROPERTY(EditAnywhere)
    float spawn_X_min ;
    UPROPERTY(EditAnywhere)
    float spawn_X_max ;
    UPROPERTY(EditAnywhere)
    float spawn_Y_min ;
    UPROPERTY(EditAnywhere)
    float spawn_Y_max ;
    void SpawnPlayerRecharge();
    
    
    
	
};
