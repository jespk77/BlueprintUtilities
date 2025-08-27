#pragma once

#include "CoreMinimal.h"
#include "ClassUtilities.generated.h"

UCLASS()
class BLUEPRINTUTILITIES_API UClassUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(Category = "Class Utilities", BlueprintCallable)
	static void GetAllClassesOfType(TArray<UClass*>& classes, const UClass* baseClass);
	template<class BaseType>
	static void GetAllClassesOfType(TArray<UClass*>& classes) { GetAllClassesOfType(classes, BaseType::StaticClass()); }

	static void GetAllPropertiesForObject(TArray<FProperty*>& properties, const UObject* object) { if (object) GetAllPropertiesForClass(properties, object->GetClass()); }
	static void GetAllPropertyNamesForObject(TArray<FString>& names, const UObject* object) { if (object) GetAllPropertyNamesForClass(names, object->GetClass()); }
	static void GetAllPropertiesForClass(TArray<FProperty*>& properties, const UClass* class_, TFunctionRef<bool(FProperty*)>* propertyTestFunction = nullptr);
	static void GetAllPropertyNamesForClass(TArray<FString>& names, const UClass* class_, TFunctionRef<bool(FProperty*)>* propertyTestFunction = nullptr);

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
