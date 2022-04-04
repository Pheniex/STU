// Shoot Them Up Game, by Pheniex

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STUHealthPercentDecorator.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUHealthPercentDecorator : public UBTDecorator
{
    GENERATED_BODY()

public:
    USTUHealthPercentDecorator();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float HeathPercent = 0.6f;

    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
