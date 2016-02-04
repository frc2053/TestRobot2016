#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem")
{
	climbTalonRight = RobotMap::climberSubsystemclimbTalonRight;
	climbTalonLeft = RobotMap::climberSubsystemclimbTalonLeft;
}

void ClimberSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void ClimberSubsystem::ClimbMotor(float speed)
{
	climbTalonRight->Set(speed);
	climbTalonLeft->Set(speed);
}

void ClimberSubsystem::ClimbMotorLeft(float speed)
{
	climbTalonLeft->Set(speed);
}

void ClimberSubsystem::ClimbMotorRight(float speed)
{
	climbTalonRight->Set(speed);
}
