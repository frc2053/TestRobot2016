#include "LeftGoalAuto.h"
#include "DriveCommandAuto.h"
#include "GoalAlignVertical.h"
#include "GoalAlign.h"
#include "ShootHigh.h"

LeftGoalAuto::LeftGoalAuto()
{
	AddSequential(new DriveCommandAuto(0, 1, 0, 2, 0)); //drive in rough direction of goal
	AddSequential(new DriveCommandAuto(1, 0, 0, 0.75, 45)); //slide to the left (one hop this time) a little and rotate to 45
	AddSequential(new GoalAlignVertical(120)); //align 120 inches away from the goal
	AddSequential(new GoalAlign()); //align horizontally with goal
	AddSequential(new ShootHigh()); //shoot the ball
	AddSequential(new DriveCommandAuto(0, 0, 0, 2, 180)); //turn around to go through defence
}
