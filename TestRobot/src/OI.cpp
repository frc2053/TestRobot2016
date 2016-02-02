#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveCommand.h"
#include "Commands/ShooterControl.h"
#include "Commands/RollerControl.h"
#include "Commands/GoalAlign.h"
#include "Commands/ZeroYaw.h"

OI::OI() {
	driverJoystick.reset(new Joystick(0));
    gunnerJoystick.reset(new Joystick(1));
    
    button2A.reset(new JoystickButton(gunnerJoystick.get(), 1));
    button2B.reset(new JoystickButton(gunnerJoystick.get(), 2));
    button2X.reset(new JoystickButton(gunnerJoystick.get(), 3));
    button2Y.reset(new JoystickButton(gunnerJoystick.get(), 4));
    button2LeftBumper.reset(new JoystickButton(gunnerJoystick.get(), 5));
    button2RightBumper.reset(new JoystickButton(gunnerJoystick.get(), 6));
    button2Back.reset(new JoystickButton(gunnerJoystick.get(), 7));
    button2Start.reset(new JoystickButton(gunnerJoystick.get(), 8));
    button2JoyLeft.reset(new JoystickButton(gunnerJoystick.get(), 9));
    button2JoyRight.reset(new JoystickButton(gunnerJoystick.get(), 10));
    button1LeftBumper.reset(new JoystickButton(driverJoystick.get(), 5));

    button2A->WhenPressed(new ShooterControl(12, 0));
    button2A->WhenReleased(new ShooterControl(0,0));

    button2B->WhenPressed(new ShooterControl(11, 0));
    button2B->WhenReleased(new ShooterControl(0,0));

    button2X->WhenPressed(new ShooterControl(10, 0));
    button2X->WhenReleased(new ShooterControl(0, 0));

    button2Y->WhenPressed(new ShooterControl(9, 0));
    button2Y->WhenReleased(new ShooterControl(0, 0));

    button2LeftBumper->WhenPressed(new ShooterControl(8, 0));
    button2LeftBumper->WhenReleased(new ShooterControl(0, 0));

    button2RightBumper->WhenPressed(new ShooterControl(7, 0));
    button2RightBumper->WhenReleased(new ShooterControl(0, 0));

    button2Back->WhenPressed(new ShooterControl(6, 0));
    button2Back->WhenReleased(new ShooterControl(0, 0));

    button2Start->WhenPressed(new ShooterControl(5, 0));
    button2Start->WhenReleased(new ShooterControl(0, 0));

    button2JoyLeft->WhenPressed(new ShooterControl(4, 0));
    button2JoyLeft->WhenReleased(new ShooterControl(0, 0));

    button2JoyRight->WhenPressed(new ShooterControl(3, 0));
    button2JoyRight->WhenReleased(new ShooterControl(0, 0));

    button1LeftBumper->WhenPressed(new GoalAlign());

    SmartDashboard::PutData("ZeroYaw", new ZeroYaw());
}

std::shared_ptr<Joystick> OI::getdriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::getgunnerJoystick() {
   return gunnerJoystick;
}
