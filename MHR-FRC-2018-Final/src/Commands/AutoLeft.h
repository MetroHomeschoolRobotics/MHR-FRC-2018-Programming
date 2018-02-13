#ifndef AUTO_H
#define AUTO_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoLeft: public frc::Command {

public:

	AutoLeft();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

};

#endif
