#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

class Autonomous : public frc::Subsystem {

private:

	int direction = 1;
	int startingPos = 0;

public:

	Autonomous();
	void InitDefaultCommand();
	void ChooseDirection();
	void AutoLeft(int direction);
	void AutoRight(int direction);
	void AutoCenter(int direction);
	void DriveH(int direction);
	void DriveI(int direction);
	void DriveV(int direction);

};

#endif
