#ifndef OverrideLiftRotate_H
#define OverrideLiftRotate_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class OverrideLiftRotate : public frc::Command {

public:

	OverrideLiftRotate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

};

#endif  // OverrideLiftRotate_H
