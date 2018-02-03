#ifndef MECHDRIVE_H
#define MECHDRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Subsystems/Positioning.h"

class MechDrive: public frc::Subsystem {

private:

	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;
	std::shared_ptr<RobotDrive> driveTrain;
	std::shared_ptr<Positioning> positioning;

	double threshold = 0.1;

public:

	MechDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z);

};

#endif
