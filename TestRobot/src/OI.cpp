#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ShootHigh.h"
#include "Commands/DriveCommand.h"
#include "Commands/ShooterControl.h"
#include "Commands/RollerControl.h"
#include "Commands/ClimbCommand.h"
#include "Commands/AlignVerticalAndHorizontal.h"
#include "Commands/GoalAlign.h"
#include "Commands/ZeroYaw.h"
#include "Commands/ShooterSolenoidControl.h"
#include "Commands/FlipIntake.h"
#include "Commands/ClimberGroup.h"
#include "Commands/ClimberSolenoidControl.h"
#include "Commands/ClimbGroupRetract.h"

OI::OI() {
	driverJoystick.reset(new Joystick(0));
    gunnerJoystick.reset(new Joystick(1));
    
    button2X.reset(new JoystickButton(gunnerJoystick.get(), 3));
    button2B.reset(new JoystickButton(gunnerJoystick.get(), 2));
    button2A.reset(new JoystickButton(gunnerJoystick.get(), 1));
    button2Y.reset(new JoystickButton(gunnerJoystick.get(), 4));
    button2Start.reset(new JoystickButton(gunnerJoystick.get(), 8));
    button2Select.reset(new JoystickButton(gunnerJoystick.get(), 7));
    button2LeftBumper.reset(new JoystickButton(gunnerJoystick.get(), 5));

    button1LeftBumper.reset(new JoystickButton(driverJoystick.get(), 5));

    button2A->WhenPressed(new ShooterSolenoidControl());
    button2X->WhenPressed(new ClimberGroup());
    button2B->WhenPressed(new ClimberSolenoidControl(false));
    button2Y->WhenPressed(new ClimberSolenoidControl(true));
    button2LeftBumper->WhenPressed(new ClimbGroupRetract());

    button2Start->WhenPressed(new ClimbCommand(.7, 0));
    button2Start->WhenReleased(new ClimbCommand(0, 0));

    button2Select->WhenPressed(new ClimbCommand(-.7, 0));
    button2Select->WhenReleased(new ClimbCommand(0, 0));

    button1LeftBumper->WhenPressed(new AlignVerticalAndHorizontal());

    SmartDashboard::PutData("ZeroYaw", new ZeroYaw());
}

std::shared_ptr<Joystick> OI::getdriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::getgunnerJoystick() {
   return gunnerJoystick;
}
