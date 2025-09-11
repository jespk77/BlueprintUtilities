#pragma once

#include "ObjectUtilities.generated.h"

UCLASS()
class BLUEPRINTUTILITIES_API UObjectUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	template<class BaseType>
	static void GetObjectsOfType(TSet<BaseType*>& objects) {
		objects.Empty();
		for (TObjectIterator<BaseType> it; it; ++it) objects.Add(*it);
	}

	UFUNCTION(Category = "Object Utilities", BlueprintCallable)
	static void GetObjectsOfType(TSet<UObject*>& objects, TSubclassOf<UObject> objectClass);

	template<class ActorType>
	static void GetActorsOfType(UWorld* world, TSet<ActorType*>& actors) {
		actors.Empty();
		for (TActorIterator<ActorType> it(world); it; ++it) actors.Add(*it);
	}
};
