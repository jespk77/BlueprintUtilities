using UnrealBuildTool;

public class BlueprintUtilities : ModuleRules {
    public BlueprintUtilities(ReadOnlyTargetRules target) : base(target) {
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
			});
			
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"CoreUObject", "Engine",
				"InputCore", "EnhancedInput",
            });
    }
}
