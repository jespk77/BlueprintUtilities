#include "ObjectUtilities.h"

void UObjectUtilities::GetObjectsOfType(TSet<UObject*>& objects, TSubclassOf<UObject> objectClass) {
	objects.Empty();
	for (TObjectIterator<UObject> it; it; ++it) {
		UObject* object = *it;
		if (object->IsA(objectClass)) objects.Add(object);
	}
}
