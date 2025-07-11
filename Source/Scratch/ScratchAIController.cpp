#include "ScratchAIController.h"

#include "ScratchGameplayTags.h"
#include "StateTreeReference.h"
#include "Components/StateTreeComponent.h"
#include "StructUtils/PropertyBag.h"

void AScratchAIController::BeginPlay()
{
	Super::BeginPlay();
  
	if (UStateTreeComponent* StateTreeComponent = FindComponentByClass<UStateTreeComponent>())
	{
		FStateTreeReference StateTreeReference;
		check(OverrideStateTree);
		StateTreeReference.SetStateTree(OverrideStateTree);
		FInstancedPropertyBag& Parameters = StateTreeReference.GetMutableParameters();
		const FName TextPropertyName("Text");
		Parameters.SetValueString(TextPropertyName, TEXT("Override"));
		StateTreeReference.SetPropertyOverridden(Parameters.FindPropertyDescByName(TextPropertyName)->ID, true);
		StateTreeComponent->AddLinkedStateTreeOverrides(ScratchGameplayTags::SCRATCH_LINKEDSTATETREE, StateTreeReference);
	}
}
