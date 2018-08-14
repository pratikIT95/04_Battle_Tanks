// Property of Pineapple Softworks

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

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
