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

void IntakeSubsystem::SetIntakeSolenoidForward() {
	intakeSolenoid->Set(DoubleSolenoid::kForward);
}

void IntakeSubsystem::SetIntakeSolenoidReverse() {
	intakeSolenoid->Set(DoubleSolenoid::kReverse);
}
