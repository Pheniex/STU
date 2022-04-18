// Shoot Them Up Game, by Pheniex


#include "Menu/STUMenuPlayerController.h"

void ASTUMenuPlayerController::BeginPlay() 
{
    Super::BeginPlay();

    SetInputMode(FInputModeUIOnly());
    bShowMouseCursor = true;
}