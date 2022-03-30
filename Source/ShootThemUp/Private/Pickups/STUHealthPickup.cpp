// Shoot Them Up Game, by Pheniex


#include "Pickups/STUHealthPickup.h"
#include "Components/STUHealthComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);

bool ASTUHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
    const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
    if (!HealthComponent)
    {
        return false;
    }
    
    //UE_LOG(LogHealthPickup, Display, TEXT("Health was taken"));
    return HealthComponent->TryToAddHealth(HealthAmount);
}