#include "ShooterControl.h"

ShooterControl::ShooterControl(float speed, float target)
{
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;
	buttonAPressed = false;
	buttonBPressed = false;
	axis = 0;
}

// Called just before this Command runs the first time
void ShooterControl::Initialize()
{
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	isDone = false;
	buttonAPressed = false;
	buttonBPressed = false;
	axis = 0;
}

// Called repeatedly when this Command is scheduled to run
void ShooterControl::Execute()
{
	std::cout << "Velocity: " << Robot::shooterSubsystem->GetEncoderVelocityRight() << std::endl;
	buttonAPressed = Robot::oi->getgunnerJoystick()->GetRawButton(1);
	buttonBPressed = Robot::oi->getgunnerJoystick()->GetRawButton(2);
	axis = Robot::oi->getgunnerJoystick()->GetRawAxis(1);
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		if(!buttonAPressed) {
			//Robot::shooterSubsystem->Shoot(axis);
		}
		else if(buttonBPressed) {
			//Robot::shooterSubsystem->Shoot(.5);
		}
		else {
			Robot::shooterSubsystem->Shoot(0);
		}
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
	timer.reset();
	Robot::shooterSubsystem->Shoot(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterControl::Interrupted()
{
	Robot::shooterSubsystem->Shoot(0);
}
