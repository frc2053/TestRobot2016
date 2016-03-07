#include "ClimbGroupRetract.h"
#include "ClimberSolenoidControl.h"
#include "ClimbCommand.h"

ClimbGroupRetract::ClimbGroupRetract()
{
	AddSequential(new ClimbCommand(-.7, 10));
}
