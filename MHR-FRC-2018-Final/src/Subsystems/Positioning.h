#ifndef Positioning_H
#define Positioning_H

#include <Commands/Subsystem.h>
#include "../LidarV3.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

#include <iostream>
#include <fstream>
using namespace std;


class Positioning : public frc::Subsystem {

private:

	std::shared_ptr<LidarV3> distanceSensor;
	std::shared_ptr<AnalogInput> ultrasonicAnalogSensor;
	std::shared_ptr<Ultrasonic> ultrasonicSensor;

	std::shared_ptr<ADXRS450_Gyro> gyro;

	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;
	std::shared_ptr<WPI_TalonSRX> rearRight;

public:
	Positioning();
	void InitDefaultCommand();
	double GetDistance();
	double GetAngle();
	double GetFrontLeftDistance();
	double GetFrontRightDistance();
	double GetRearLeftDistance();
	double GetRearRightDistance();
};

#endif  // Positioning_H
