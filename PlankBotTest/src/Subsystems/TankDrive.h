#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Subsystems/Positioning.h"

class TankDrive: public frc::Subsystem {

private:

	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;
	std::shared_ptr<Positioning> positioning;
	double threshold = 0.1;

public:

	TankDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y);

};

#endif
