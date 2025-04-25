#include "ClassUtilities.h"

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
