#ifndef LIFT_H
#define LIFT_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Lift: public frc::Command {

public:

	Lift();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:

};

#endif
