#include "ShootHigh.h"
#include "ShooterControl.h"
#include "RollerControl.h"
#include "GoalAlign.h"
#include "ShooterSolenoidControl.h"

ShootHigh::ShootHigh()
{
	AddSequential(new ShooterControl(9, 1));
	Wait(.5);
	AddSequential(new ShooterSolenoidControl(1));
	AddSequential(new ShooterSolenoidControl(0));
	AddSequential(new ShooterControl(0, 0));
}
