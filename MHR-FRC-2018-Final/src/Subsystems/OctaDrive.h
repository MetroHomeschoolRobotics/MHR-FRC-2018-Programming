#ifndef OCTADRIVE_H
#define OCTADRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class OctaDrive: public frc::Subsystem {

private:

	std::shared_ptr<frc::DoubleSolenoid> switchSol1;

	bool isTank = true;

public:

	OctaDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z);
	void SwitchMode();
	bool IsTankDrive();
	void UpdateStatFile();
};

#endif
