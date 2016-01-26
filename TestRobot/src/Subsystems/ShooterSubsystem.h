#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class ShooterSubsystem: public Subsystem {
private:
	std::shared_ptr<CANTalon> shooterTalonLeft;
	std::shared_ptr<CANTalon> shooterTalonRight;
	std::shared_ptr<Servo> shooterServo;
	std::shared_ptr<Encoder> shooterEncoderLeft;
	std::shared_ptr<Encoder> shooterEncoderRight;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void Shoot(float speed);
	void SetServo(float pwm);
	void SetServoAngle(float angle);
	double GetEncoderRateLeft();
	double GetEncoderRateRight();
};

#endif
