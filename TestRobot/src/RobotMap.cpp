// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackRightTalon;
std::shared_ptr<RobotDrive> RobotMap::driveBaseSubsystemrobotDrive;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalon;
std::shared_ptr<CANTalon> RobotMap::intakeSubsystemintakeTalon;

std::shared_ptr<DoubleSolenoid> RobotMap::intakeSubsystemintakeSolenoid;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    //LiveWindow *lw = LiveWindow::GetInstance();

    driveBaseSubsystemfrontLeftTalon.reset(new CANTalon(1));
    //lw->AddActuator("DriveBaseSub", "frontLeftTalon", driveBaseSubfrontLeftTalon);
    
    driveBaseSubsystemfrontRightTalon.reset(new CANTalon(2));
    //lw->AddActuator("DriveBaseSub", "frontRightTalon", driveBaseSubfrontRightTalon);
    
    driveBaseSubsystembackLeftTalon.reset(new CANTalon(3));
    //lw->AddActuator("DriveBaseSub", "backLeftTalon", driveBaseSubbackLeftTalon);
    
    driveBaseSubsystembackRightTalon.reset(new CANTalon(4));
    //lw->AddActuator("DriveBaseSub", "backRightTalon", driveBaseSubbackRightTalon);
    
    driveBaseSubsystemrobotDrive.reset(new RobotDrive(driveBaseSubsystemfrontLeftTalon, driveBaseSubsystembackLeftTalon,
              driveBaseSubsystemfrontRightTalon, driveBaseSubsystembackRightTalon));
    
    driveBaseSubsystemrobotDrive->SetSafetyEnabled(false);
        driveBaseSubsystemrobotDrive->SetExpiration(0.1);
        driveBaseSubsystemrobotDrive->SetSensitivity(0.5);
        driveBaseSubsystemrobotDrive->SetMaxOutput(1.0);

    shooterSubsystemshooterTalon.reset(new CANTalon(5));
    //lw->AddActuator("ShooterSubsystem", "shooterTalon", shooterSubsystemshooterTalon);
    
    intakeSubsystemintakeTalon.reset(new CANTalon(6));

    intakeSubsystemintakeSolenoid.reset(new DoubleSolenoid(0, 1));
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
