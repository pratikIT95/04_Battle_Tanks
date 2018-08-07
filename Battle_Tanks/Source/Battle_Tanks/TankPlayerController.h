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
		virtual void Tick(float DeltaTime) override;
private:
	void AimAtCrosshair();
	bool GetSightRayHitLocation(FVector &OutHitLocation);
	UPROPERTY(EditAnywhere)
	float CrosshairLocationX = 0.5;
	UPROPERTY(EditAnywhere)
	float CrosshairLocationY = 0.33333333;
};
