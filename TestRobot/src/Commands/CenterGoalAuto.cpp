#include "CenterGoalAuto.h"
#include "DriveCommandAuto.h"
#include "ShootHigh.h"
#include "DoNothing.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "GoalAlign.h"
#include "AlignVerticalAndHorizontal.h"
#include "AlignParallel.h"
#include "AlignCenter.h"
#include "RotateToAngleAuto.h"

CenterGoalAuto::CenterGoalAuto()
{
	AddSequential(new AlignParallel(0, 110));
	AddSequential(new AlignCenter());
	AddSequential(new RotateToAngleAuto(0));
}
