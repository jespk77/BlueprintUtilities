using UnrealBuildTool;

public class BlueprintUtilities : ModuleRules {
    public BlueprintUtilities(ReadOnlyTargetRules target) : base(target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        CppCompileWarningSettings.UnreachableCodeWarningLevel = WarningLevel.Warning;
        CppCompileWarningSettings.ImplicitIntConversionWarningLevel = WarningLevel.Warning;

        PublicDependencyModuleNames.AddRange([
                "Core",
            ]);

        PrivateDependencyModuleNames.AddRange([
                "CoreUObject", "Engine",
                "InputCore", "EnhancedInput",
            ]);
    }
}
