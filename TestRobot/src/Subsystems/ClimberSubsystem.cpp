#include "ClimberSubsystem.h"
#include "../RobotMap.h"

ClimberSubsystem::ClimberSubsystem() : Subsystem("ClimberSubsystem")
{
	climbTalonRight = RobotMap::climberSubsystemclimbTalonRight;
	climbTalonLeft = RobotMap::climberSubsystemclimbTalonLeft;
	climbSolenoid = RobotMap::climberSubsystemclimbSolenoid;
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

void ClimberSubsystem::SetSolenoidForward() {
	climbSolenoid->Set(DoubleSolenoid::kForward);
}

void ClimberSubsystem::SetSolenoidReverse() {
	climbSolenoid->Set(DoubleSolenoid::kReverse);
}

bool ClimberSubsystem::GetForwardLimit() {
	return climbTalonLeft->IsFwdLimitSwitchClosed();
}

bool ClimberSubsystem::GetReverseLimit() {
	return climbTalonLeft->IsRevLimitSwitchClosed();
}
