// Shoot Them Up Game, by Pheniex


#include "AI/STUAICharacter.h"
#include "AI/STUAIController.h"



ASTUAICharacter::ASTUAICharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = ASTUAIController::StaticClass();
}