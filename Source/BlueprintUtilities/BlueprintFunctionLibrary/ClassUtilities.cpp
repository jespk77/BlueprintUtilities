#include "ClassUtilities.h"

void UClassUtilities::GetAllClassesOfType(TSet<UClass*>& set, const UClass* baseClass) {
	set.Reset();
	for (TObjectIterator<UClass> it; it; ++it) {
		UClass* classType = *it;
		if (!classType->HasAnyClassFlags(CLASS_Abstract) && classType->IsChildOf(baseClass)) set.Emplace(classType);
	}
}

template<class BaseType>
inline BaseType* UClassUtilities::FindObjectWithName(FString typeName) {
	for (TObjectIterator<BaseType> it; it; ++it) {
		BaseType* classType = *it;
		if (classType->GetName().Equals(typeName, ESearchCase::IgnoreCase))
			return classType;
	}
	return nullptr;
}

UClass* UClassUtilities::FindClassWithName(FString typeName) {
	return FindObjectWithName<UClass>(typeName);
}

UEnum* UClassUtilities::FindEnumWithName(FString typeName) {
	return FindObjectWithName<UEnum>(typeName);
}

void UClassUtilities::GetAllPropertiesForObject(TSet<FProperty*>& properties, const UObject* object) {
	properties.Reset();
	if (!object) return;

	for (TFieldIterator<FProperty> it(object->GetClass()); it; ++it) {
		FProperty* property = *it;
		properties.Add(property);
	}
}
