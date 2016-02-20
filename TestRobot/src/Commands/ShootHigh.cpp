#include "ShootHigh.h"
#include "ShooterControl.h"
#include "RollerControl.h"
#include "GoalAlign.h"
#include "ShooterSolenoidControl.h"

ShootHigh::ShootHigh()
{
	AddSequential(new ShooterControl(9, 1));
	if(Robot::shooterSubsystem->GetEncoderVelocityLeft() > 22700 && Robot::shooterSubsystem->GetEncoderVelocityRight() < -22700) {
		AddSequential(new ShooterSolenoidControl());
		AddSequential(new ShooterControl(0, 0));
	}
}
