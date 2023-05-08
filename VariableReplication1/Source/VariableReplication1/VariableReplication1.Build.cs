// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VariableReplication1 : ModuleRules
{
	public VariableReplication1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
