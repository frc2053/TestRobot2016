#include "ShootHigh.h"
#include "ShooterControl.h"
#include "RollerControl.h"
#include "GoalAlign.h"
#include "ServoControl.h"

ShootHigh::ShootHigh()
{
	AddSequential(new ShooterControl(9, 1));
	Wait(.5);
	AddSequential(new ServoControl(1));
}
