#include "ClimberGoup.h"
#include "ClimberSolenoidControl.h"
#include "ClimbCommand.h"

ClimberGoup::ClimberGoup()
{
	AddParallel(new ClimberSolenoidControl(true));
	AddSequential(new ClimbCommand(1, 3));
	AddParallel(new ClimberSolenoidControl(false));
	AddSequential(new ClimbCommand(-1, 3));
}
