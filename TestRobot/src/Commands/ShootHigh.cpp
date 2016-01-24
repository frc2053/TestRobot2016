#include "ShootHigh.h"
#include "ShooterControl.h"
#include "RollerControl.h"

ShootHigh::ShootHigh()
{
	//FIND GOAL
	//AUTO CORRECT TO IT
	AddParallel(new ShooterControl(1, 1));
	Wait(.5);
	AddParallel(new RollerControl(1, 0.25));
}
