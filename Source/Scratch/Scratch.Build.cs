// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Scratch : ModuleRules
{
	public Scratch(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange([
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
		]);

		PrivateDependencyModuleNames.AddRange([
			"GameplayTags",
		]);
	}
}
