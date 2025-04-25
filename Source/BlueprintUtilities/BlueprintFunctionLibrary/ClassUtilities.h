#pragma once

#include "CoreMinimal.h"
#include "ClassUtilities.generated.h"

UCLASS()
class BLUEPRINTUTILITIES_API UClassUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	public:
		template<class BaseType>
		static void GetAllClassesOfType(TSet<UClass*>& set) { GetAllClassesOfType(set, BaseType::StaticClass()); }

		UFUNCTION(Category="Class Utilities", BlueprintCallable)
		static void GetAllClassesOfType(TSet<UClass*>& set, const UClass* baseClass);

		static void GetAllPropertiesForObject(TSet<FProperty*>& properties, const UObject* object);
};