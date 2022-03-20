// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UInGameMenu::NativeConstruct()
{
	if (ReturnGameBtn)
	{
		ReturnGameBtn->OnClicked.AddDynamic(this, &UInGameMenu::ReturnGame);
	}
	if (QuitGameBtn)
	{
		QuitGameBtn->OnClicked.AddDynamic(this, &UInGameMenu::QuitGame);
	}
}

void UInGameMenu::OpenUI()
{
	AddToViewport();
	SetGameAndUI();
}

void UInGameMenu::CloseUI()
{
	RemoveFromParent();
	SetGameOnly();
}

void UInGameMenu::ReturnGame()
{
	CloseUI();
}

void UInGameMenu::QuitGame()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->ConsoleCommand("quit");
	}
}

void UInGameMenu::SetGameAndUI()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeGameAndUI());
		Controller->bShowMouseCursor = true;
		Controller->SetIgnoreMoveInput(true);
		Controller->SetIgnoreLookInput(true);
	}
}

void UInGameMenu::SetGameOnly()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeGameOnly());
		Controller->bShowMouseCursor = false;
		Controller->SetIgnoreMoveInput(false);
		Controller->SetIgnoreLookInput(false);
	}
}
