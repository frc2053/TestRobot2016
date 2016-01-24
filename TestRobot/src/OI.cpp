#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/DriveCommand.h"
#include "Commands/IntakePneumaticsControl.h"
#include "Commands/ShooterControl.h"
#include "Commands/RollerControl.h"

OI::OI() {
    gunnerJoystick.reset(new Joystick(1));
    
    driverJoystick.reset(new Joystick(0));

    buttonA.reset(new JoystickButton(gunnerJoystick.get(), 0));
    buttonB.reset(new JoystickButton(gunnerJoystick.get(), 1));
    buttonX.reset(new JoystickButton(gunnerJoystick.get(), 2));
    buttonY.reset(new JoystickButton(gunnerJoystick.get(), 3));
    buttonBack.reset(new JoystickButton(gunnerJoystick.get(), 6));
    buttonStart.reset(new JoystickButton(gunnerJoystick.get(), 7));

    buttonA->WhileHeld(new ShooterControl(1, 0)); //forwards
    buttonB->WhileHeld(new ShooterControl(-1, 0)); //backwards
    buttonX->WhenPressed(new IntakePneumaticsControl(true)); //true = extend
    buttonY->WhenPressed(new IntakePneumaticsControl(false)); //false = retract
    buttonStart->WhileHeld(new RollerControl(1, 0)); //suck in
    buttonBack->WhileHeld(new RollerControl(-1, 0)); //suck out
}

std::shared_ptr<Joystick> OI::getdriverJoystick() {
   return driverJoystick;
}

std::shared_ptr<Joystick> OI::getgunnerJoystick() {
   return gunnerJoystick;
}
