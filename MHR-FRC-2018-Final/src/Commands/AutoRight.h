#ifndef AutoRight_H
#define AutoRight_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "AutoRightLeft.h"
#include "AutoRightRight.h"

class AutoRight : public frc::Command {
public:
	AutoRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoRight_H
