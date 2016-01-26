#include "ShooterControl.h"

ShooterControl::ShooterControl(float speed, float target)
{
	Requires(Robot::shooterSubsystem.get());
	printf("ShooterControl!\n");
	timer.reset(new Timer());
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;
	buttonAPressed = false;
	buttonBPressed = false;
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
}

// Called repeatedly when this Command is scheduled to run
void ShooterControl::Execute()
{
	printf("ShooterControl Execute!\n");
	buttonAPressed = Robot::oi->getgunnerJoystick()->GetRawButton(1);
	buttonBPressed = Robot::oi->getgunnerJoystick()->GetRawButton(2);
	printf("timerCurrent before!\n");
	timeCurrent = timer->Get();
	printf("timerCurrent after!\n");
	if(timeTarget == 0) {
		printf("i am here!");
		if(buttonAPressed) {
			printf("buttonAPressed!\n");
			Robot::shooterSubsystem->Shoot(1);
		}
		else {
			Robot::shooterSubsystem->Shoot(0);
		}

		if(buttonBPressed) {
			Robot::shooterSubsystem->Shoot(-1);
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
