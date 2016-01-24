#include "RetractIntake.h"

RetractIntake::RetractIntake()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::intakeSubsystem.get());
}

// Called just before this Command runs the first time
void RetractIntake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RetractIntake::Execute()
{
	Robot::intakeSubsystem->SolenoidBackwards();
}

// Make this return true when this Command no longer needs to run execute()
bool RetractIntake::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void RetractIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RetractIntake::Interrupted()
{

}
