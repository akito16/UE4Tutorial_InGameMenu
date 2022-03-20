// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "InGameMenu.h"

AMenuPlayerController::AMenuPlayerController()
{
	bShowMouseCursor = false;

	static ConstructorHelpers::FClassFinder<UInGameMenu> MenuWidgetObj(TEXT("/Game/Blueprints/UI/UI_InGameMenu"));
	MenuWidgetClass = MenuWidgetObj.Class;
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Menu", IE_Pressed, this, &AMenuPlayerController::MenuToggle);
}

void AMenuPlayerController::MenuToggle()
{
	if (IsValid(MenuCurrentWidget))
	{
		MenuCurrentWidget->CloseUI();
		MenuCurrentWidget = nullptr;
	}
	else
	{
		MenuCurrentWidget = CreateWidget<UInGameMenu>(GetWorld(), MenuWidgetClass);
		if (IsValid(MenuCurrentWidget))
		{
			MenuCurrentWidget->OpenUI();
		}
	}
}