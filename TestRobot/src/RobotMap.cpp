#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackRightTalon;
std::shared_ptr<RobotDrive> RobotMap::driveBaseSubsystemrobotDrive;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalon;
std::shared_ptr<CANTalon> RobotMap::intakeSubsystemintakeTalon;
std::shared_ptr<DoubleSolenoid> RobotMap::intakeSubsystemintakeSolenoid;

void RobotMap::init() {
    driveBaseSubsystemfrontLeftTalon.reset(new CANTalon(1));
    driveBaseSubsystemfrontRightTalon.reset(new CANTalon(2));
    driveBaseSubsystembackLeftTalon.reset(new CANTalon(3));
    driveBaseSubsystembackRightTalon.reset(new CANTalon(4));
    
    driveBaseSubsystemrobotDrive.reset(new RobotDrive(driveBaseSubsystemfrontLeftTalon, driveBaseSubsystembackLeftTalon,
              driveBaseSubsystemfrontRightTalon, driveBaseSubsystembackRightTalon));
    
    driveBaseSubsystemrobotDrive->SetSafetyEnabled(false);
        driveBaseSubsystemrobotDrive->SetExpiration(0.1);
        driveBaseSubsystemrobotDrive->SetSensitivity(0.5);
        driveBaseSubsystemrobotDrive->SetMaxOutput(1.0);

    shooterSubsystemshooterTalon.reset(new CANTalon(5));
    intakeSubsystemintakeTalon.reset(new CANTalon(6));
    intakeSubsystemintakeSolenoid.reset(new DoubleSolenoid(0, 1));
}
