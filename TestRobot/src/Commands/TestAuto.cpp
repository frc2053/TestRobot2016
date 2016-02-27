#include "TestAuto.h"
#include "DriveCommandAuto.h"
#include "ShootHigh.h"
#include "DoNothing.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "GoalAlign.h"

TestAuto::TestAuto()
{
	printf("constructor for test auto!\n");
	AddSequential(new DriveCommandAuto(0, 0, 0, 1, 0));
	AddSequential(new GoalAlign());
	AddSequential(new DriveCommandAuto(0, 0, 0, 1, 0));
	AddSequential(new ShooterControl(3200, 2));
	AddSequential(new ShooterSolenoidControl());
	printf("after sequential for test auto!\n");
}
