#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

class AutonomousSystem : public frc::Subsystem {

private:

	int direction = 1;
	int startingPos = 0;

public:

	AutonomousSystem();
	void InitDefaultCommand();
	void ChooseDirection();
	void AutoLeft();
	void AutoRight();
	void AutoCenter();

	int FindDirection();
	void DriveH(int direction);
	void DriveI(int direction);
	void DriveV(int direction);

};

#endif
