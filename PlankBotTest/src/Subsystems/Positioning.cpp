#include "Positioning.h"
#include "../RobotMap.h"

Positioning::Positioning() : frc::Subsystem("PositioningSubsystem") {
	distanceSensor = RobotMap::lidarDistanceSensor;
	gyro = RobotMap::gyro;
	gyro.get()->Reset();
}

void Positioning::InitDefaultCommand() {
}

double Positioning::GetDistance() {
	return distanceSensor.get()->GetDistance();
}

double Positioning::GetAngle() {
	return gyro.get()->GetAngle();
}

void Positioning::ResetGyro() {
	gyro.get()->Reset();
}
