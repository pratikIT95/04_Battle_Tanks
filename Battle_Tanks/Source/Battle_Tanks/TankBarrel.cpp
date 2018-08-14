// Property of Pineapple Softworks

#include "TankBarrel.h"

void UTankBarrel :: Elevate(float DegreesPerScond)
{
	//Move the barrel the right amount this frame
	//Rotate the right amount given elevation speed and frame time
	UE_LOG(LogTemp, Warning, TEXT("TankBarrel->Elevate() called with %f"), DegreesPerScond);
}

