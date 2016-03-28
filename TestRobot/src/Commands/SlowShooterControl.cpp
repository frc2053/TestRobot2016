#include "SlowShooterControl.h"

SlowShooterControl::SlowShooterControl(float speed, float target)
{
	Requires(Robot::shooterSubsystem.get());
	timer.reset(new Timer());
	timeCurrent = 0;
	timeTarget = target;
	inputSpeed = speed;
	isDone = false;
	rightBumper2 = false;
	leftBumper2 = false;
	timer->Reset();
	timer->Start();
	printf("in shooter slow control constructor!\n");
	runOnce = false;
}

// Called just before this Command runs the first time
void SlowShooterControl::Initialize()
{
	timer->Reset();
	timer->Start();
	timeCurrent = 0;
	isDone = false;
	rightBumper2 = false;
	leftBumper2 = false;
	runOnce = false;
}

// Called repeatedly when this Command is scheduled to run
void SlowShooterControl::Execute()
{
	printf("in shooter control execute!\n");
	SmartDashboard::PutNumber("Velocity Right", Robot::shooterSubsystem->GetEncoderVelocityRight());
	SmartDashboard::PutNumber("Velocity Left", Robot::shooterSubsystem->GetEncoderVelocityLeft());
	timeCurrent = timer->Get();
	std::cout << "Timer: " << timeCurrent << std::endl;
	if(timeTarget == 0) {
		Robot::shooterSubsystem->Shoot(inputSpeed);
		Robot::intakeSubsystem->Intake(-inputSpeed);
		Robot::shooterSubsystem->SetAngleLeftServo(0);
		Robot::shooterSubsystem->SetAngleRightServo(200);
		isDone = true;
	}
	else {
		if(timeCurrent >= timeTarget) {
			Robot::shooterSubsystem->Shoot(0);
			Robot::shooterSubsystem->SetAngleLeftServo(70);
			Robot::shooterSubsystem->SetAngleRightServo(110);
			Robot::intakeSubsystem->Intake(0);
			isDone = true;
		}
		else {
			Robot::shooterSubsystem->Shoot(inputSpeed);
			Robot::intakeSubsystem->Intake(-inputSpeed);
			Robot::shooterSubsystem->SetAngleLeftServo(0);
			Robot::shooterSubsystem->SetAngleRightServo(200);
			isDone = false;
		}

		if(timeCurrent >= timeTarget - .20 && !runOnce) {
			runOnce = true;
			Robot::shooterSubsystem->SetAngleLeftServo(0);
			Robot::shooterSubsystem->SetAngleRightServo(200);
			Robot::shooterSubsystem->SetSolenoidForward();
			Wait(1);
			Robot::shooterSubsystem->SetSolenoidReverse();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SlowShooterControl::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void SlowShooterControl::End()
{
	timer->Stop();
	//Robot::shooterSubsystem->Shoot(0);
	//Robot::intakeSubsystem->Intake(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlowShooterControl::Interrupted()
{
}
