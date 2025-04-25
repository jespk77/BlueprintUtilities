#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "InputUtilities.generated.h"

class UEnhancedInputComponent;

typedef TDelegate<void(const FInputActionValue&)> ActionBinding;

UCLASS()
class BLUEPRINTUTILITIES_API UInputUtilities : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	// Makes sure the input component has the right type and log a message if it isn't
	UFUNCTION(Category = "Input", BlueprintCallable)
	static UEnhancedInputComponent* CheckInputComponent(UInputComponent* component);

	// Find an input action from the standard location
	UFUNCTION(Category = "Input", BlueprintCallable)
	static UInputAction* FindAction(const FString typeName, const FString actionName);
};