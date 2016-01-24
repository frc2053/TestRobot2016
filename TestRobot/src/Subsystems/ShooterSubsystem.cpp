#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem") {
    shooterTalon = RobotMap::shooterSubsystemshooterTalon;
}

void ShooterSubsystem::InitDefaultCommand() {
    // SetDefaultCommand(new MySpecialCommand());
}

void ShooterSubsystem::Shoot(float speed)
{
	shooterTalon->Set(speed);
}
