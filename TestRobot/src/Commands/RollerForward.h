#ifndef RollerForward_H
#define RollerForward_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class RollerForward: public Command
{
public:
	RollerForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
