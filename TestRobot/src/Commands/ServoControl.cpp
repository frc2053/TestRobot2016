#include "ServoControl.h"

ServoControl::ServoControl(float pwm)
{
	Requires(Robot::shooterSubsystem.get());
	inputPWM = pwm;
}

// Called just before this Command runs the first time
void ServoControl::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ServoControl::Execute()
{
	Robot::shooterSubsystem->SetServo(inputPWM);
}

// Make this return true when this Command no longer needs to run execute()
bool ServoControl::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ServoControl::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ServoControl::Interrupted()
{

}
