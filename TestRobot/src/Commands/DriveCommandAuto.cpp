#include "DriveCommandAuto.h"

DriveCommandAuto::DriveCommandAuto(float side, float fow, float rot, float time, float angle)
{
	Requires(Robot::driveBaseSubsystem.get());
	inputSide = side;
	inputFow = fow;
	inputRot = rot;
	timeTarget = time;
	inputAngle = angle;
	timeCurrent = 0;
	isDone = false;
	timer.reset(new Timer());
	adjustedYaw = 0;
	finalAutoRot = 0;
	isRotDone = false;
	timer->Reset();
	timer->Start();

}

// Called just before this Command runs the first time
void DriveCommandAuto::Initialize()
{
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveCommandAuto::Execute()
{
	timeCurrent = timer->Get();
	adjustedYaw = Robot::driveBaseSubsystem->getAdjYaw();
	finalAutoRot = Robot::driveBaseSubsystem->CalculateRotValue(inputAngle, 1);
	Robot::driveBaseSubsystem->MecanumDrive(inputSide, inputFow, finalAutoRot, adjustedYaw);
	if(timeCurrent >= timeTarget) {
		Robot::driveBaseSubsystem->MecanumDrive(0,0,0,0);
		isDone = true;
	}
	else {
		isDone = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommandAuto::IsFinished()
{
	return isDone;
}

// Called once after isFinished returns true
void DriveCommandAuto::End()
{
	timer.reset(new Timer());
	Robot::driveBaseSubsystem->MecanumDrive(0,0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommandAuto::Interrupted()
{
	Robot::driveBaseSubsystem->MecanumDrive(0,0,0,0);
}
