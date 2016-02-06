#include "CenterGoalAuto.h"
#include "GoalAlignVertical.h"
#include "GoalAlign.h"
#include "ShootHigh.h"
#include "DriveCommandAuto.h"

CenterGoalAuto::CenterGoalAuto()
{
	AddSequential(new GoalAlignVertical(120)); //align vertically with goal
	AddSequential(new GoalAlign()); //align horizontally with goal
	AddSequential(new ShootHigh()); //shoot the ball
	AddSequential(new DriveCommandAuto(0, 0, 0, 2, 180)); //rotate to 180 to drive back through defence
}
