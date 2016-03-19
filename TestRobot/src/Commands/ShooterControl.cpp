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
	SmartDashboard::PutNumber("Velocity Right", Robot::shooterSubsystem->GetEncoderVelocityRight());
	SmartDashboard::PutNumber("Velocity Left", Robot::shooterSubsystem->GetEncoderVelocityLeft());
	timeCurrent = timer->Get();
	if(timeTarget == 0) {
		if(rightTrigger2 > 0.2) {
			//Robot::shooterSubsystem->Shoot(12);
			Robot::shooterSubsystem->Shoot(6000);
			Robot::intakeSubsystem->Intake(-1);
		}
		else if(leftTrigger2 > 0.2) {
			Robot::shooterSubsystem->Shoot(-1500);
			Robot::intakeSubsystem->Intake(1);
			Robot::shooterSubsystem->SetAngleLeftServo(0);
			Robot::shooterSubsystem->SetAngleRightServo(200);
		}//ROBOT.RUN
		else {
			Robot::shooterSubsystem->Shoot(0);
			Robot::intakeSubsystem->Intake(0);
			Robot::shooterSubsystem->SetAngleLeftServo(70);
			Robot::shooterSubsystem->SetAngleRightServo(110);
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
