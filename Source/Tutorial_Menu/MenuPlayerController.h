// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIAL_MENU_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMenuPlayerController();

	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UInGameMenu> MenuWidgetClass;

	UPROPERTY(EditAnywhere)
		class UInGameMenu* MenuCurrentWidget;

	UFUNCTION()
		void MenuToggle();
};
