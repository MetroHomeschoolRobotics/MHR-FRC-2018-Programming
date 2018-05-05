#include "Positioning.h"
#include "../RobotMap.h"

Positioning::Positioning() : frc::Subsystem("PositioningSubsystem") {
	distanceSensor = RobotMap::lidarDistanceSensor;
	ultrasonicAnalogSensor = RobotMap::ultrasonicAnalogDistanceSensor;
	ultrasonicSensor = RobotMap::ultrasonicDistanceSensor;
	gyro = RobotMap::gyro;
	gyro.get()->Reset();
	frontLeft = RobotMap::tankDriveFrontLeft;
	frontRight = RobotMap::tankDriveFrontRight;
	rearLeft = RobotMap::tankDriveRearLeft;
	rearRight = RobotMap::tankDriveRearRight;
}

void Positioning::InitDefaultCommand() {
}

double Positioning::GetDistance() {
	//return ultrasonicSensor.get()->GetRangeInches();
	return ultrasonicAnalogSensor.get()->GetVoltage();// / 512;
	//return distanceSensor.get()->GetDistance();
}

double Positioning::GetAngle() {
	return gyro.get()->GetAngle();
}

double Positioning::GetFrontLeftDistance() {
	return frontLeft.get()->GetSelectedSensorPosition(0);
}

double Positioning::GetFrontRightDistance() {
	return frontRight.get()->GetSelectedSensorPosition(0);
}

double Positioning::GetRearLeftDistance() {
	return rearLeft.get()->GetSelectedSensorPosition(0);
}

double Positioning::GetRearRightDistance() {
	return rearRight.get()->GetSelectedSensorPosition(0);
}


