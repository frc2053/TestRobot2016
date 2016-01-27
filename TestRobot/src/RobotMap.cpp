#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystemfrontRightTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackLeftTalon;
std::shared_ptr<CANTalon> RobotMap::driveBaseSubsystembackRightTalon;
std::shared_ptr<RobotDrive> RobotMap::driveBaseSubsystemrobotDrive;

std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalonLeft;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemshooterTalonRight;
std::shared_ptr<Servo> RobotMap::shooterSubsystemshooterServo;

std::shared_ptr<CANTalon> RobotMap::intakeSubsystemintakeTalon;
std::shared_ptr<Servo> RobotMap::intakeSubsystemintakeServo;

void RobotMap::init() {
    driveBaseSubsystemfrontLeftTalon.reset(new CANTalon(8));
    driveBaseSubsystemfrontRightTalon.reset(new CANTalon(6));
    driveBaseSubsystembackLeftTalon.reset(new CANTalon(9));
    driveBaseSubsystembackRightTalon.reset(new CANTalon(2));
    
    driveBaseSubsystemrobotDrive.reset(new RobotDrive(driveBaseSubsystemfrontLeftTalon, driveBaseSubsystembackLeftTalon,
              driveBaseSubsystemfrontRightTalon, driveBaseSubsystembackRightTalon));
    
    driveBaseSubsystemrobotDrive->SetSafetyEnabled(false);
        driveBaseSubsystemrobotDrive->SetExpiration(0.1);
        driveBaseSubsystemrobotDrive->SetSensitivity(0.5);
        driveBaseSubsystemrobotDrive->SetMaxOutput(1.0);

    driveBaseSubsystemrobotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
    driveBaseSubsystemrobotDrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);

    shooterSubsystemshooterTalonLeft.reset(new CANTalon(1));
    shooterSubsystemshooterTalonRight.reset(new CANTalon(3));
    shooterSubsystemshooterTalonRight->SetFeedbackDevice(CANTalon::QuadEncoder);
    shooterSubsystemshooterTalonRight->SetControlMode(CANTalon::ControlMode::kSpeed);
    shooterSubsystemshooterTalonRight->ConfigEncoderCodesPerRev(256);
    shooterSubsystemshooterTalonRight->Set(300);
    shooterSubsystemshooterTalonRight->SetP(2);
	shooterSubsystemshooterTalonRight->SetI(0);
	shooterSubsystemshooterTalonRight->SetD(20);

    shooterSubsystemshooterServo.reset(new Servo(0));

    intakeSubsystemintakeTalon.reset(new CANTalon(4));
    intakeSubsystemintakeServo.reset(new Servo(1));
}
