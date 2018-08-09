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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;//Out parameter
	if (GetSightRayHitLocation(HitLocation))//See if line tracing(AKA RayCasting) hits any place in the landscape
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction :%s"), *HitLocation.ToString());
	}
	 //Then make the tank aim at that point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation)
{
	/// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	//Get the size of the viewport
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ViewportSize = FVector2D(ViewportSizeX, ViewportSizeY);
	UE_LOG(LogTemp, Warning, TEXT("ViewPortSize: %s"), *ViewportSize.ToString());
	//Compute the location from screen ratio positions
	auto ScreenLocation = FVector2D(float(ViewportSizeX)*CrosshairLocationX, float(ViewportSizeY)*CrosshairLocationY);
	// "De-project" the position of the crosshair into world coordinates
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line trace in the direction the crosshair is looking and return true if it hits something(up to certain range)
		GetLookVectorHitLocation(LookDirection,OutHitLocation);
		UE_LOG(LogTemp, Warning, TEXT("Hitting at: %s"), *OutHitLocation.ToString());
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;
	bool bHasHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		);
	if (bHasHit)
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}
