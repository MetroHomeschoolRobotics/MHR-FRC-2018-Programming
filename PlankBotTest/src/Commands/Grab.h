#ifndef Grab_H
#define Grab_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Grab: public frc::Command {

public:

	Grab();
 	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:

};

#endif
