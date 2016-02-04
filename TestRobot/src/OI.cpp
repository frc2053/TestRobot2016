#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveCommand.h"
#include "Commands/ShooterControl.h"
#include "Commands/RollerControl.h"
#include "Commands/GoalAlign.h"
#include "Commands/ZeroYaw.h"
#include "Commands/ServoControl.h"

OI::OI() {
	driverJoystick.reset(new Joystick(0));
    gunnerJoystick.reset(new Joystick(1));
    
    button2B.reset(new JoystickButton(gunnerJoystick.get(), 2));
    button2X.reset(new JoystickButton(gunnerJoystick.get(), 3));
    button2Y.reset(new JoystickButton(gunnerJoystick.get(), 4));

    button1LeftBumper.reset(new JoystickButton(driverJoystick.get(), 5));

    button2Y->WhenPressed(new ShooterControl(7.8, 0));
    button2Y->WhenReleased(new ShooterControl(0, 0));

    button2B->WhenPressed(new ShooterControl(-5, 0));
    button2B->WhenReleased(new ShooterControl(0, 0));

    button2X->WhenPressed(new ServoControl(0));
    button2X->WhenReleased(new ServoControl(1));


    button1LeftBumper->WhenPressed(new GoalAlign());

    SmartDashboard::PutData("ZeroYaw", new ZeroYaw());
}

std::shared_ptr<Joystick> OI::getdriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::getgunnerJoystick() {
   return gunnerJoystick;
}
