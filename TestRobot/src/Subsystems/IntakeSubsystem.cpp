#include "IntakeSubsystem.h"
#include "../RobotMap.h"

IntakeSubsystem::IntakeSubsystem() : Subsystem("Intake Subsystem")
{
	intakeTalon = RobotMap::intakeSubsystemintakeTalon;
	intakeServo = RobotMap::intakeSubsystemintakeServo;
}

void IntakeSubsystem::InitDefaultCommand()
{
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeSubsystem::Intake(float speed)
{
	intakeTalon->Set(speed);
}

void IntakeSubsystem::SetServo(float pwm) {
	intakeServo->Set(pwm);
}

void IntakeSubsystem::SetServoAngle(float angle) {
	intakeServo->SetAngle(angle);
}
