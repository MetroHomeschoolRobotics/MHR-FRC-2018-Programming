#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "../Subsystems/OctaDrive.h"
#include "../Subsystems/BoxLift.h"
#include "../Subsystems/Positioning.h"
//#include "../Robot.h"

class AutonomousSystem : public frc::Subsystem {

private:

	int direction = 1;
	int startingPos = 0;
	OctaDrive *drive;
	BoxLift *lift;
	Positioning *pos;

public:

	AutonomousSystem(OctaDrive *octaDrive, BoxLift *boxLift, Positioning *positioning);
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
