// Property of Pineapple Softworks

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
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
void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!GetPlayerTank()) { return; }
	//Move towards player

	//Aim towards player
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	//Fire if ready
	
}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


