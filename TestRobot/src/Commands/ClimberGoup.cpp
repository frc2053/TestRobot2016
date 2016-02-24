#include "ClimberGoup.h"
#include "ClimberSolenoidControl.h"
#include "ClimbCommand.h"

ClimberGoup::ClimberGoup()
{
	AddSequential(new ClimberSolenoidControl(true));
	AddSequential(new ClimberSolenoidControl(false));
	AddSequential(new ClimbCommand(1, 2));
}
