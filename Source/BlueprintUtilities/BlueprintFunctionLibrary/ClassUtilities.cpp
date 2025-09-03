#include "ClassUtilities.h"

void UClassUtilities::GetAllClassesOfType(TArray<UClass*>& classes, const UClass* baseClass) {
	classes.Reset();
	for (TObjectIterator<UClass> it; it; ++it) {
		UClass* classType = *it;
		if (!classType->HasAnyClassFlags(CLASS_Abstract) && classType->IsChildOf(baseClass)) classes.Add(classType);
	}
}

template<typename Iterable>
UClass* UClassUtilities::GetCommonClassForItems(const Iterable& objects) {
	TArray<UClass*> objectClasses;
	objectClasses.Reserve(objects.Num());
	for (UObject* obj : objects) objectClasses.Add(obj->GetClass());
	return UClass::FindCommonBase(objectClasses);
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
