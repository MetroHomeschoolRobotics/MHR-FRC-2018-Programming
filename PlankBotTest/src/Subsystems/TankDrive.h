#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class TankDrive: public frc::Subsystem {

private:

	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;

	double threshold = 0.1;

public:

	TankDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y);

};

#endif
