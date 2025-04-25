#include "InputUtilities.h"
#include "EnhancedInputComponent.h"

UInputAction* UInputUtilities::FindAction(const FString typeName, const FString actionName) {
	const FString path = FString::Format(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/{0}/{1}.{1}'"), { typeName, actionName });
	return LoadObject<UInputAction>(nullptr, *path);
}

UEnhancedInputComponent* UInputUtilities::CheckInputComponent(UInputComponent* component) {
	if (UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(component)) return input;
	else if (component) { UE_LOG(LogInput, Error, TEXT("Unsupported input component type '%s'"), *component->GetClass()->GetFName().ToString()); }
	else { UE_LOG(LogInput, Error, TEXT("No input component")); }
	return nullptr;
}