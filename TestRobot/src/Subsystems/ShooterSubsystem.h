#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class ShooterSubsystem: public Subsystem {
private:
	std::shared_ptr<CANTalon> shooterTalonLeft;
	std::shared_ptr<CANTalon> shooterTalonRight;
	std::shared_ptr<DoubleSolenoid> shooterSolenoid;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void Shoot(float speed);
	void ShootLeftMotor(float speed);
	void ShootRightMotor(float speed);
	void SetSolenoidForward();
	void SetSolenoidReverse();
	double GetEncoderVelocityLeft();
	double GetEncoderVelocityRight();
};

#endif
