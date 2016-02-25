#include "TestAuto.h"
#include "DriveCommandAuto.h"

TestAuto::TestAuto()
{
	AddSequential(new DriveCommandAuto(.3, 0, 0, .5, 0));
}
