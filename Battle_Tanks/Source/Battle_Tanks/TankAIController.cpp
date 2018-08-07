// Property of Pineapple Softworks

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetAIControlledTank();
	ATank *PlayerPawn = GetPlayerTank();
	if (PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT(" Player controlled tank found:%s"), *(PlayerPawn->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("The Player controlled tank is not found"));
	}
}
ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


