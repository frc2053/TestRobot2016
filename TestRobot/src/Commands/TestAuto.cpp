#include "TestAuto.h"
#include "DriveCommandAuto.h"
#include "ShootHigh.h"
#include "DoNothing.h"
#include "ShooterControl.h"
#include "ShooterSolenoidControl.h"
#include "GoalAlign.h"
#include "AlignVerticalAndHorizontal.h"

TestAuto::TestAuto()
{
	printf("constructor for test auto!\n");
	AddSequential(new DriveCommandAuto(0, 0, 0, 1, 0));
	AddSequential(new AlignVerticalAndHorizontal());
	AddSequential(new DriveCommandAuto(0, 0, 0, .5, 0));
	AddSequential(new ShooterControl(6000, 2));
	AddSequential(new ShooterSolenoidControl());
	printf("after sequential for test auto!\n");
}
