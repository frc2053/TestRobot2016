#ifndef GoalAlign_H
#define GoalAlign_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class GoalAlign: public Command
{
public:
	GoalAlign();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool isDone;
	int targetX;
	bool inToleranceX;
	bool inToleranceY;
	const int toleranceX = 5;
	const int centerX = 160; //pixels
	const int toleranceY = 6; //inches
	int distanceTarget = 120;
	float calrot = 0;
	float adjyaw = 0;
	int distanceToCenter = 0;
	float distanceY = 0;
	float speedX = 0;
	float speedY = 0;
};

#endif
