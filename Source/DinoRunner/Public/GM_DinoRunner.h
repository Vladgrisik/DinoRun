// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GM_DinoRunner.generated.h"

/**
 * 
 */
UCLASS()
class DINORUNNER_API AGM_DinoRunner : public AGameMode
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	class AMyBaseTile* BaseTileRef;

	UPROPERTY()
	FVector NextSpawnPoint;

	UFUNCTION()
	void Spawn_Tiles(int32 Amount);

	// Player
	UPROPERTY()
	class AMyDinoCharacter* MyPlayer_Ref;

	// Game state
	UPROPERTY()
	bool Game_Started = false;
	
	

};
