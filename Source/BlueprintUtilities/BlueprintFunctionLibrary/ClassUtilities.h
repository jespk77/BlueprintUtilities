#pragma once

#include "ClassUtilities.generated.h"

UCLASS()
class BLUEPRINTUTILITIES_API UClassUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static void GetAllClassesOfType(TArray<UClass*>& classes, const UClass* baseClass);
	template<class BaseType>
	static void GetAllClassesOfType(TArray<UClass*>& classes) { GetAllClassesOfType(classes, BaseType::StaticClass()); }

	template<typename PropertyType = FProperty>
	static void GetAllPropertiesForObject(TArray<FProperty*>& properties, const UObject* object) { if (object) GetAllPropertiesForType<PropertyType>(properties, object->GetClass()); }
	template<typename PropertyType = FProperty>
	static void GetAllPropertyNamesForObject(TArray<FString>& names, const UObject* object) { if (object) GetAllPropertiesForType<PropertyType>(names, object->GetClass()); }
	template<typename PropertyType = FProperty>
	static void GetAllPropertiesForType(TArray<FProperty*>& properties, const UStruct* type) {
		properties.Reset();
		if (!type) return;

		for (TFieldIterator<FProperty> it(type); it; ++it) {
			FProperty* property = *it;
			if (property->IsA<PropertyType>()) properties.Add(property);
		}
	}

	template<typename PropertyType = FProperty>
	static void GetAllPropertyNamesForType(TArray<FString>& names, const UStruct* type) {
		TArray<FProperty*> properties;
		GetAllPropertiesForType<PropertyType>(properties, type);

		names.Reset(properties.Num());
		for (const FProperty* property : properties) names.Add(property->GetName());
	}

	template<typename Iterable>
	static UClass* GetCommonClassForItems(const Iterable& objects);
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
