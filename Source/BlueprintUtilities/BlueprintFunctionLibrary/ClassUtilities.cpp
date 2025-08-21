#include "ClassUtilities.h"

template<typename Iterable>
UClass* UClassUtilities::GetCommonClassForItems(const Iterable& objects) {
	TArray<UClass*> objectClasses;
	objectClasses.Reserve(objects.Num());
	for (UObject* obj : objects) objectClasses.Add(obj->GetClass());
	return UClass::FindCommonBase(objectClasses);
}

void UClassUtilities::GetAllClassesOfType(TSet<UClass*>& set, const UClass* baseClass) {
	set.Reset();
	for (TObjectIterator<UClass> it; it; ++it) {
		UClass* classType = *it;
		if (!classType->HasAnyClassFlags(CLASS_Abstract) && classType->IsChildOf(baseClass)) set.Emplace(classType);
	}
}

void UClassUtilities::GetAllPropertiesForObject(TSet<FProperty*>& properties, const UObject* object) {
	properties.Reset();
	if (!object) return;

	for (TFieldIterator<FProperty> it(object->GetClass()); it; ++it) {
		FProperty* property = *it;
		properties.Add(property);
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
