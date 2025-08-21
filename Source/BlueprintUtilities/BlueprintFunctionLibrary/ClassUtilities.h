#pragma once

#include "CoreMinimal.h"
#include "ClassUtilities.generated.h"

UCLASS()
class BLUEPRINTUTILITIES_API UClassUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

private:
	template<typename Iterable>
	static UClass* GetCommonClassForItems(const Iterable& objects);

public:
	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static void GetAllClassesOfType(TSet<UClass*>& set, const UClass* baseClass);
	template<class BaseType>
	static void GetAllClassesOfType(TSet<UClass*>& set) { GetAllClassesOfType(set, BaseType::StaticClass()); }

	static void GetAllPropertiesForObject(TSet<FProperty*>& properties, const UObject* object);

	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static UClass* GetCommonClassFromArray(const TArray<UObject*>& objects) { return GetCommonClassForItems(objects); }
	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static UClass* GetCommonClassFromSet(const TSet<UObject*>& objects) { return GetCommonClassForItems(objects); }

	template<class BaseType>
	static BaseType* FindObjectWithName(FString typeName);
	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static UClass* FindClassWithName(FString typeName) { return FindObjectWithName<UClass>(typeName); }
	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static UEnum* FindEnumWithName(FString typeName) { return FindObjectWithName<UEnum>(typeName); }
};
