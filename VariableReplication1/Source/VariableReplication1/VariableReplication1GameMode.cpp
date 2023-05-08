// Copyright Epic Games, Inc. All Rights Reserved.

#include "VariableReplication1GameMode.h"
#include "VariableReplication1Character.h"
#include "UObject/ConstructorHelpers.h"

AVariableReplication1GameMode::AVariableReplication1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
