#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() : Subsystem("Intake Subsystem")
{
	intakeTalon = RobotMap::intakeSubsystemintakeTalon;
	intakeSolenoid = RobotMap::intakeSubsystemintakeSolenoid;
}

void IntakeSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
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
