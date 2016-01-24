#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() : Subsystem("Intake Subsystem")
{
	intakeTalon = RobotMap::intakeSubsystemintakeTalon;
	intakeSolenoid = RobotMap::intakeSubsystemintakeSolenoid;
}

void IntakeSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeSubsystem::Intake(float speed)
{
	intakeTalon->Set(speed);
}

void IntakeSubsystem::SolenoidForward()
{
	intakeSolenoid->Set(intakeSolenoid->kForward);
}

void IntakeSubsystem::SolenoidBackwards()
{
	intakeSolenoid->Set(intakeSolenoid->kReverse);
}
