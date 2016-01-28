#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveCommand.h"
#include "Commands/ShooterControl.h"
#include "Commands/RollerControl.h"

OI::OI() {
	driverJoystick.reset(new Joystick(0));
    gunnerJoystick.reset(new Joystick(1));
    
    buttonA.reset(new JoystickButton(gunnerJoystick.get(), 1));
    buttonB.reset(new JoystickButton(gunnerJoystick.get(), 2));

    buttonA->WhenPressed(new ShooterControl(300, 0));
    buttonA->WhenReleased(new ShooterControl(0,0));
    buttonB->WhenPressed(new ShooterControl(-300, 0));
    buttonB->WhenReleased(new ShooterControl(0,0));
}

std::shared_ptr<Joystick> OI::getdriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::getgunnerJoystick() {
   return gunnerJoystick;
}
