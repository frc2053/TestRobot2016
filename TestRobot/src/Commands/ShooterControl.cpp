#include "ShooterControl.h"

ShooterControl::ShooterControl(float speed, float target)
{
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;
	rightTrigger2 = 0;
	leftTrigger2 = 0;
}

// Called just before this Command runs the first time
void ShooterControl::Initialize()
{
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	isDone = false;
	rightTrigger2 = 0;
	leftTrigger2 = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterControl::Execute()
{
	rightTrigger2 = Robot::oi->getgunnerJoystick()->GetRawAxis(3);
	//std::cout << "rightTrigger: " << rightTrigger2 << std::endl;
	leftTrigger2 = Robot::oi->getgunnerJoystick()->GetRawAxis(2);
	//std::cout << "Velocity: " << Robot::shooterSubsystem->GetEncoderVelocityRight() << std::endl;
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		if(rightTrigger2 > 0.2) {
			Robot::shooterSubsystem->Shoot(6.3);
		}
		else if(leftTrigger2 > 0.2) {
			Robot::shooterSubsystem->Shoot(-3);
		}
		else {
			Robot::shooterSubsystem->Shoot(0);
		}
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::shooterSubsystem->Shoot(0);
			isDone = true;
		}
		else {
			Robot::shooterSubsystem->Shoot(inputSpeed);
			isDone = false;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterControl::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void ShooterControl::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterControl::Interrupted()
{
}
