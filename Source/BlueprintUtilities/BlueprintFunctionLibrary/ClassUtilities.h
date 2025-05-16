#pragma once

#include "CoreMinimal.h"
#include "ClassUtilities.generated.h"

UCLASS()
class BLUEPRINTUTILITIES_API UClassUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	template<class BaseType>
	static void GetAllClassesOfType(TSet<UClass*>& set) { GetAllClassesOfType(set, BaseType::StaticClass()); }

	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static void GetAllClassesOfType(TSet<UClass*>& set, const UClass* baseClass);

	template<class BaseType>
	static BaseType* FindObjectWithName(FString typeName);

	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static UClass* FindClassWithName(FString typeName);

	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static UEnum* FindEnumWithName(FString typeName);

	static void GetAllPropertiesForObject(TSet<FProperty*>& properties, const UObject* object);
};
