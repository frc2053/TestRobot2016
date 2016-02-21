#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveCommand.h"
#include "Commands/ShooterControl.h"
#include "Commands/RollerControl.h"
#include "Commands/AlignVerticalAndHorizontal.h"
#include "Commands/ZeroYaw.h"
#include "Commands/ShooterSolenoidControl.h"

OI::OI() {
	driverJoystick.reset(new Joystick(0));
    gunnerJoystick.reset(new Joystick(1));
    
    button2X.reset(new JoystickButton(gunnerJoystick.get(), 3));
    button2A.reset(new JoystickButton(gunnerJoystick.get(), 1));
    button2Y.reset(new JoystickButton(gunnerJoystick.get(), 4));

    button1LeftBumper.reset(new JoystickButton(driverJoystick.get(), 5));

    button2A->WhenPressed(new ShooterSolenoidControl());

    button2X->WhenPressed(new RollerControl(.4, 0));
    button2X->WhenReleased(new RollerControl(0, 0));

    button2Y->WhenPressed(new RollerControl(-.4, 0));
    button2Y->WhenReleased(new RollerControl(0, 0));


    button1LeftBumper->WhenPressed(new AlignVerticalAndHorizontal());

    SmartDashboard::PutData("ZeroYaw", new ZeroYaw());
}

std::shared_ptr<Joystick> OI::getdriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::getgunnerJoystick() {
   return gunnerJoystick;
}
