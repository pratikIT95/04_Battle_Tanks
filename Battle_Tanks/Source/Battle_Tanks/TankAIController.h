// Property of Pineapple Softworks

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

//Forward declarations
class ATank;
/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATank * GetControlledTank() const;
	ATank * GetPlayerTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
};
