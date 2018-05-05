#ifndef AutoCenter_H
#define AutoCenter_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "AutoCenterLeft.h"
#include "AutoCenterRight.h"

class AutoCenter : public frc::Command {
public:
	AutoCenter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoCenter_H
