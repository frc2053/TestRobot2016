#ifndef GoalAlign_H
#define GoalAlign_H

#include "Commands/Subsystem.h"
#include "../vision/vision.h"
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
	bool inTolerance;
	const int tolerance = 5;
	const int centerX = 160;
	float calrot = 0;
	float adjyaw = 0;
	int distance = 0;
	float speed = 0;
};

#endif
