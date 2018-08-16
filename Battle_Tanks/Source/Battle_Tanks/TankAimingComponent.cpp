// Property of Pineapple Softworks

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHasAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHasAimSolution)
	{
		auto TankName = GetOwner()->GetName();
		FVector LaunchDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%f Aim has solution"), GetWorld()->GetTimeSeconds());
		MoveBarrelTowards(LaunchDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f Aim has no solution"), GetWorld()->GetTimeSeconds());
	}
}
void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{

	Barrel = BarrelToSet;
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Calculate the difference between current rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(5.0);
}