#include "DefenseSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/DefenseManipulator.h"

DefenseSubsystem::DefenseSubsystem() : Subsystem("DefenseSubsystem")
{
	defenseTalon = RobotMap::defenseSubsystemTalon;
}

void DefenseSubsystem::InitDefaultCommand()
{
}

void DefenseSubsystem::DefenseMotor(float speed) {
	defenseTalon->Set(speed);
}
