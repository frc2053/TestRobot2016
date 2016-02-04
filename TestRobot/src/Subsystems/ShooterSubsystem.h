#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class ShooterSubsystem: public Subsystem {
private:
	std::shared_ptr<CANTalon> shooterTalonLeft;
	std::shared_ptr<CANTalon> shooterTalonRight;
	std::shared_ptr<Servo> shooterServo;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void Shoot(float speed);
	void ShootLeftMotor(float speed);
	void ShootRightMotor(float speed);
	void SetServo(float pwm);
	void SetServoAngle(float angle);
	double GetEncoderVelocityLeft();
	double GetEncoderVelocityRight();
};

#endif
