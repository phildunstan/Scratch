# Scratch

This project is used to house small tests for different features of Unreal.

This project is not supported. It has been created with Unreal 5.6, but may require additional engine fixes and plugins. It has been made public for informational purposes only.

## LinkedStateTree - State Tree Linked Asset Overrides with Parameters

This test demonstrates how to pass parameters to a state tree linked asset override.

In the ScratchLinkedStateTree map there is placed a BP_ScratchLinkedStateTreeAICharacter, that uses the AIC_ScratchLinkedStateTree controller (parented from AScratchAIController). 

The controller contains a state tree AI component linked to the ST_HasLinkedAsset state tree.

ST_HasLinkedAsset contains the state tree linked asset that will be overridden. Currently, the linked state tree node is bound to the ST_DefaultLinkedAsset state tree and specifies the Scratch.LinkedStateTree gameplay tag.

Within the AScratchAIController OnPossess an override is set to replace the linked state tree for that gameplay tag with the ST_OverrideLinkedAsset state tree. At the same time a "Text" parameter is set.

The code to set the state tree override:
```cpp
FStateTreeReference StateTreeReference;
StateTreeReference.SetStateTree(OverrideStateTree);

FInstancedPropertyBag& Parameters = StateTreeReference.GetMutableParameters();
const FName TextPropertyName("Text");
Parameters.SetValueString(TextPropertyName, TEXT("Override"));
StateTreeReference.SetPropertyOverridden(Parameters.FindPropertyDescByName(TextPropertyName)->ID, true);

StateTreeComponent->AddLinkedStateTreeOverrides(ScratchGameplayTags::SCRATCH_LINKEDSTATETREE, StateTreeReference);
```

When the level is run, the character will execute the overridden state tree, showing the text "Override".

If the override is unsuccessful, either the word "Default" will be shown if the original ST_DefaultLinkedAsset state tree is executed, or "Unset" if the override state tree is executed, but the parameter is not set.


## Chase - AI moving across a navlink


## InvisibleWall - Player pawn moving through an invisible wall actor

