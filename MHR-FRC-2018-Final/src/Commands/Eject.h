#pragma once

#include "Commands/Subsystem.h"
#include "../Robot.h"

class Eject : public frc::Command {

public:

	Eject();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

};
