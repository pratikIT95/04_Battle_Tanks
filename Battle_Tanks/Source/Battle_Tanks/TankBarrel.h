// Property of Pineapple Softworks

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLE_TANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
};