// Property of Pineapple Softworks

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("The controlled tank is:%s"), *(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("The controlled tank is not found"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
