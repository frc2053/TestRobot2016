#ifndef ShootForward_H
#define ShootForward_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShootForward: public Command
{
public:
	ShootForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
