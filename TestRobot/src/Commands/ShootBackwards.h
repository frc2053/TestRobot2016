#ifndef ShootBackwards_H
#define ShootBackwards_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShootBackwards: public Command
{
public:
	ShootBackwards();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
