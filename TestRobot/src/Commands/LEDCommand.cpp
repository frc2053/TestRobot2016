#include "LEDCommand.h"

LEDCommand::LEDCommand()
{
	Requires(Robot::ledSubsystem.get());
}

// Called just before this Command runs the first time
void LEDCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LEDCommand::Execute()
{
	/*if(Robot::driveBaseSubsystem->isAlignedX && Robot::driveBaseSubsystem->isAlignedY) {
		Robot::ledSubsystem->SetBlueLED(1);
		Robot::ledSubsystem->SetRedLED(0);
		Robot::ledSubsystem->SetGreenLED(0);
	}
	else {
		Robot::ledSubsystem->SetRedLED(1);
		Robot::ledSubsystem->SetBlueLED(0);
		Robot::ledSubsystem->SetGreenLED(0);
	}*/
	Robot::ledSubsystem->SetRedLED(1);
	Robot::ledSubsystem->SetBlueLED(1);
	Robot::ledSubsystem->SetGreenLED(0);
}

// Make this return true when this Command no longer needs to run execute()
bool LEDCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LEDCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LEDCommand::Interrupted()
{

}
