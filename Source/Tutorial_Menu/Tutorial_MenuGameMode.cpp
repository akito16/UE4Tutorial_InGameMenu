// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tutorial_MenuGameMode.h"
#include "Tutorial_MenuCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATutorial_MenuGameMode::ATutorial_MenuGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
