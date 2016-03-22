#include "ShooterSolenoidControl.h"

ShooterSolenoidControl::ShooterSolenoidControl()
{
	std::cout << "shooterControl constructor!" << std::endl;
	isDone = false;
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called just before this Command runs the first time
void ShooterSolenoidControl::Initialize()
{
	std::cout << "Init function!" << std::endl;
	isDone = false;
	timer->Reset();
	timer->Start();
	timeTarget = pnuematicDelay;
	timeCurrent = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterSolenoidControl::Execute()
{
	isDone = false;
	timeCurrent = timer->Get();
	std::cout << "timeCurrent: " << timeCurrent << std::endl;
	if(timeCurrent >= timeTarget) {
		Robot::shooterSubsystem->SetSolenoidReverse();
		//printf("isDone!\n");
		isDone = true;
	}
	else {
		if(Robot::shooterSubsystem->GetEncoderVelocityRight() < -32000) {
			Robot::shooterSubsystem->SetAngleLeftServo(0);
			Robot::shooterSubsystem->SetAngleRightServo(200);
			Wait(.25);
			Robot::shooterSubsystem->SetSolenoidForward();
		}
		isDone = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterSolenoidControl::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void ShooterSolenoidControl::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterSolenoidControl::Interrupted()
{

}
