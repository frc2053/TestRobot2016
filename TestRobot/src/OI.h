#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<Joystick> gunnerJoystick;
	std::shared_ptr<Joystick> driverJoystick;

	std::shared_ptr<JoystickButton> button2X;
	std::shared_ptr<JoystickButton> button2Y;
	std::shared_ptr<JoystickButton> button1LeftBumper;
public:
	OI();
	std::shared_ptr<Joystick> getdriverJoystick();
	std::shared_ptr<Joystick> getgunnerJoystick();
};

#endif
