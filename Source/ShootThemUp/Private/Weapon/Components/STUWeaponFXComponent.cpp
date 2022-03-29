// Shoot Them Up Game, by Pheniex


#include "Weapon/Components/STUWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"


USTUWeaponFXComponent::USTUWeaponFXComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USTUWeaponFXComponent::PlayImpactFX(const FHitResult& Hit) 
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
}