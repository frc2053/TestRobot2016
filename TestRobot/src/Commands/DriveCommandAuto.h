#ifndef DriveCommandAuto_H
#define DriveCommandAuto_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveCommandAuto: public Command
{
public:
	DriveCommandAuto(float side, float fow, float rot, float time, float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float inputSide;
	float inputFow;
	float inputRot;
	float inputAngle;
	std::shared_ptr<Timer> timer;
	float timeCurrent;
	float timeTarget;
	bool isDone;
	float finalAutoRot; //number passed into mec drive cartesian
	float adjustedYaw; //number passed into yaw param of mec drive cartesian (fixes auto modes)
	bool isRotDone;
};

#endif
