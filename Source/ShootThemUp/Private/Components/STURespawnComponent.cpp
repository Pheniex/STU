// Shoot Them Up Game, by Pheniex

#include "Components/STURespawnComponent.h"
#include "STUGameModeBase.h"

USTURespawnComponent::USTURespawnComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USTURespawnComponent::Respawn(int32 RespawnTime) 
{
    if (!GetWorld())
    {
        return;
    }

    RespawnCountDown = RespawnTime;
    GetWorld()->GetTimerManager().SetTimer(RespawnTimerHendle, this, &USTURespawnComponent::RespawnTimerUpdate, 1.0f, true);
}

void USTURespawnComponent::RespawnTimerUpdate() 
{
    if (--RespawnCountDown == 0)
    {
        if (!GetWorld())
        {
            return;
        }
        GetWorld()->GetTimerManager().ClearTimer(RespawnTimerHendle);

        const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
        if (!GameMode)
        {
            return;
        }

        GameMode->RespawnRequest(Cast<AController>(GetOwner()));
    }
}

bool USTURespawnComponent::IsRespawnInProgress() const 
{
    return GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(RespawnTimerHendle);
}