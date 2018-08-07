// Property of Pineapple Softworks

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
		ATank* GetControlledTank() const;
		virtual void BeginPlay() override;
};
