#include "ExtendIntake.h"

ExtendIntake::ExtendIntake()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intakeSubsystem.get());
}

// Called just before this Command runs the first time
void ExtendIntake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ExtendIntake::Execute()
{
	Robot::intakeSubsystem->SolenoidForward();
}

// Make this return true when this Command no longer needs to run execute()
bool ExtendIntake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ExtendIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExtendIntake::Interrupted()
{

}
