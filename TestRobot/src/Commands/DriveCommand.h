#ifndef DRIVECOMMAND_H
#define DRIVECOMMAND_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveCommand: public Command {
public:
	DriveCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:
	float XAxis; //joystick value
	float YAxis; //joystick value
	float RotAxis; //joystick value
	float SetAngle; //angle passed into rotation
	float SetSpeed; //speed passed into rotation
	float FinalAutoRot; //number passed into mec drive cartesian
	float AdjustedYaw; //number passed into yaw param of mec drive cartesian (fixes auto modes)
	bool ButtonYPressed; //buttons for rotating
	bool ButtonXPressed;
	bool ButtonAPressed;
	bool ButtonBPressed;
	bool isRotDone;
};

#endif
