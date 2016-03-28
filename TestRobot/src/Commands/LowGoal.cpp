#include "LowGoal.h"
#include "SlowShooterControl.h"
#include "ShooterSolenoidControl.h"

LowGoal::LowGoal()
{
	AddParallel(new ShooterSolenoidControl());
	AddSequential(new SlowShooterControl(2000, .4));
}
