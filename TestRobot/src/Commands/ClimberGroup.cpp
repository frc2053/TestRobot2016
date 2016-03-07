#include "ClimberGroup.h"
#include "ClimberSolenoidControl.h"
#include "ClimbCommand.h"

ClimberGroup::ClimberGroup()
{
	AddSequential(new ClimberSolenoidControl(true));
	AddSequential(new ClimbCommand(.3, 5));
	//AddParallel(new ClimberSolenoidControl(false));
	//AddSequential(new ClimbCommand(-.3, 2.5));
}
