#ifndef SHOOTERSUBSYSTEM_H
#define SHOOTERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class ShooterSubsystem: public Subsystem {
private:
	std::shared_ptr<CANTalon> shooterTalon;
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void Shoot(float speed);
};

#endif
