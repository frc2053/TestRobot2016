#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ShooterControl.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	printf("Shooter Subsystem!\n");
    shooterTalonLeft = RobotMap::shooterSubsystemshooterTalonLeft;
    shooterTalonRight = RobotMap::shooterSubsystemshooterTalonRight;
    shooterServo = RobotMap::shooterSubsystemshooterServo;
    shooterEncoderLeft = RobotMap::shooterSubsystemshooterLeftEncoder;
    shooterEncoderRight = RobotMap::shooterSubsystemshooterRightEncoder;
}

void ShooterSubsystem::InitDefaultCommand() {
    SetDefaultCommand(new ShooterControl());
}

void ShooterSubsystem::Shoot(float speed)
{
	//shooterTalonLeft->Set(speed);
	shooterTalonRight->Set(speed);
}

void ShooterSubsystem::SetServo(float pwm) {
	shooterServo->Set(pwm);
}

void ShooterSubsystem::SetServoAngle(float angle) {
	shooterServo->SetAngle(angle);
}

double ShooterSubsystem::GetEncoderRateLeft() {
	return shooterEncoderLeft->GetRate();
}

double ShooterSubsystem::GetEncoderRateRight() {
	return shooterEncoderRight->GetRate();
}
