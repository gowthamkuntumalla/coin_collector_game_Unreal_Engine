// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "coin_collectorGameMode.h"
#include "coin_collectorCharacter.h"
#include "UObject/ConstructorHelpers.h"

Acoin_collectorGameMode::Acoin_collectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
