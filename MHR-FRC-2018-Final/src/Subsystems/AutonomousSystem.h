#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include <DriverStation.h>

class AutonomousSystem : public frc::Subsystem {
public:

	AutonomousSystem();
	void InitDefaultCommand();
	int FindDirection();
};

#endif
