#ifndef Positioning_H
#define Positioning_H

#include <Commands/Subsystem.h>
#include "../LidarV3.h"

class Positioning : public frc::Subsystem {
private:
	std::shared_ptr<LidarV3> distanceSensor;
public:
	Positioning();
	void InitDefaultCommand();
	double GetDistance();
};

#endif  // Positioning_H
