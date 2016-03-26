#include "TestAuto.h"
#include "DriveCommandAuto.h"
#include "ShootHigh.h"
#include "DoNothing.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "GoalAlign.h"
#include "AlignVerticalAndHorizontal.h"
#include "AlignCenter.h"
#include "AlignParallel.h"
#include "RotateToAngleAuto.h"

TestAuto::TestAuto()
{
	//printf("constructor for test auto!\n");
	AddSequential(new AlignParallel(0, 145));
	AddSequential(new AlignCenter());
	AddSequential(new RotateToAngleAuto(4));
	AddSequential(new ShooterControl(6000, 1.3));
	AddSequential(new ShooterSolenoidControl());
	//printf("after sequential for test auto!\n");
}
