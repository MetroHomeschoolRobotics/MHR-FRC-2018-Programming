#ifndef Positioning_H
#define Positioning_H

#include <Commands/Subsystem.h>
#include "../LidarV3.h"
#include "WPILib.h"

class Positioning : public frc::Subsystem {
private:
	std::shared_ptr<LidarV3> distanceSensor;
	std::shared_ptr<ADXRS450_Gyro> gyro;
public:
	Positioning();
	void InitDefaultCommand();
	double GetDistance();
	double GetAngle();
	void ResetGyro();
};

#endif  // Positioning_H
