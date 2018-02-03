#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "LidarV3.h"

class RobotMap {

public:
	static std::shared_ptr<RobotDrive> mainDrive;
	static std::shared_ptr<WPI_TalonSRX> tankDriveFrontLeft;
	static std::shared_ptr<WPI_TalonSRX> tankDriveFrontRight;
	static std::shared_ptr<WPI_TalonSRX> tankDriveRearRight;
	static std::shared_ptr<WPI_TalonSRX> tankDriveRearLeft;

	static std::shared_ptr<WPI_TalonSRX> liftMotor;

	static std::shared_ptr<frc::DoubleSolenoid> octoDriveSwitchSol1;
	static std::shared_ptr<frc::DoubleSolenoid> liftGrabSol1;

	static std::shared_ptr<frc::Encoder> liftMotorEncoder;

	static std::shared_ptr<LidarV3> lidarDistanceSensor;
	static std::shared_ptr<AnalogGyro> gyro;

	static void init();
};

#endif
