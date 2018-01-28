#ifndef MECHDRIVE_H
#define MECHDRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class MechDrive: public frc::Subsystem {

private:

	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;

	double threshold = 0.1;

public:

	MechDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z);

};

#endif
