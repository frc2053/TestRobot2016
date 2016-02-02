#include "ShootHighAuto.h"
#include "GoalAlign.h"
#include "ShootHigh.h"

ShootHighAuto::ShootHighAuto()
{
	AddSequential(new GoalAlign());
	AddSequential(new ShootHigh());
}
