#ifndef DoNothing_H
#define DoNothing_H

#include "../CommandBase.h"
#include "WPILib.h"

class DoNothing: public CommandBase
{
public:
	DoNothing();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
