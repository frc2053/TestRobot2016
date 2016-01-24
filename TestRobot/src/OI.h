#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<Joystick> gunnerJoystick;
	std::shared_ptr<Joystick> driverJoystick;
	std::shared_ptr<JoystickButton> buttonA;
	std::shared_ptr<JoystickButton> buttonB;
	std::shared_ptr<JoystickButton> buttonX;
	std::shared_ptr<JoystickButton> buttonY;
	std::shared_ptr<JoystickButton> buttonBack;
	std::shared_ptr<JoystickButton> buttonStart;
public:
	OI();
	std::shared_ptr<Joystick> getdriverJoystick();
	std::shared_ptr<Joystick> getgunnerJoystick();
};

#endif
