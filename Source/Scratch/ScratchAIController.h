#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "ScratchAIController.generated.h"

class UStateTree;

UCLASS()
class SCRATCH_API AScratchAIController : public AAIController
{
    GENERATED_BODY()

protected:
    virtual void OnPossess(APawn *InPawn) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStateTree> StateTree;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStateTree> OverrideStateTree;
};