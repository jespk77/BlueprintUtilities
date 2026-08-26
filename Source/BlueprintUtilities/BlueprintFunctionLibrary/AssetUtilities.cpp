#include "AssetUtilities.h"
#include "AssetRegistry/AssetRegistryModule.h"

IAssetRegistry& UAssetUtilities::GetAssetRegistry() {
	FAssetRegistryModule& module = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	return module.Get();
}

bool UAssetUtilities::FindAssetsByPath(FName path, TArray<FAssetData>& assets, bool recursive, bool includeOnlyOnDiskAssets) {
	return GetAssetRegistry().GetAssetsByPath(path, assets, recursive, includeOnlyOnDiskAssets);
}

bool UAssetUtilities::FindAssetsByPaths(TArray<FName> paths, TArray<FAssetData>& assets, bool recursive, bool includeOnlyOnDiskAssets) {
	return GetAssetRegistry().GetAssetsByPaths(paths, assets, recursive, includeOnlyOnDiskAssets);
}
