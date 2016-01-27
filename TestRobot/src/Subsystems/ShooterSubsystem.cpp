#include "ShooterSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ShooterControl.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
	printf("Shooter Subsystem!\n");
    shooterTalonLeft = RobotMap::shooterSubsystemshooterTalonLeft;
    shooterTalonRight = RobotMap::shooterSubsystemshooterTalonRight;
    shooterServo = RobotMap::shooterSubsystemshooterServo;
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

double ShooterSubsystem::GetEncoderVelocityLeft() {
	return (shooterTalonLeft->GetEncVel() * -1) / 2;
}

double ShooterSubsystem::GetEncoderVelocityRight() {
	return (shooterTalonRight->GetEncVel() * -1) / 2;
}
