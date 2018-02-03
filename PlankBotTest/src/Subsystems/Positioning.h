#ifndef Positioning_H
#define Positioning_H

#include <Commands/Subsystem.h>
#include "../LidarV3.h"
#include "WPILib.h"

class Positioning : public frc::Subsystem {
private:
	std::shared_ptr<LidarV3> distanceSensor;
	std::shared_ptr<AnalogGyro> gyro;
public:
	Positioning();
	void InitDefaultCommand();
	double GetDistance();
	float GetAngle();
};

#endif  // Positioning_H
