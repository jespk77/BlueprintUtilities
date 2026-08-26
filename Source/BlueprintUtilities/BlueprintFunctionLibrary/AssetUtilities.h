#pragma once

#include "AssetUtilities.generated.h"

UCLASS()
class BLUEPRINTUTILITIES_API UAssetUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

private:
	static class IAssetRegistry& GetAssetRegistry();

public:
	UFUNCTION(Category = "Asset Utilities", BlueprintCallable)
	static bool FindAssetsByPath(FName path, TArray<FAssetData>& assets, bool recursive = false, bool includeOnlyOnDiskAssets = false);

	UFUNCTION(Category = "Asset Utilities", BlueprintCallable)
	static bool FindAssetsByPaths(TArray<FName> paths, TArray<FAssetData>& assets, bool recursive = false, bool includeOnlyOnDiskAssets = false);
};
