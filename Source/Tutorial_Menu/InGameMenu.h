// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class TUTORIAL_MENU_API UInGameMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ReturnGameBtn;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* QuitGameBtn;

	UFUNCTION()
		void OpenUI();

	UFUNCTION()
		void CloseUI();

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void SetGameAndUI();

	UFUNCTION()
		void SetGameOnly();

	UFUNCTION()
		void ReturnGame();

	UFUNCTION()
		void QuitGame();
};
