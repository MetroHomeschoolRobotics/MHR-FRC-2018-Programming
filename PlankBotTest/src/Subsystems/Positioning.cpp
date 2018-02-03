#include "Positioning.h"
#include "../RobotMap.h"

Positioning::Positioning() : frc::Subsystem("PositioningSubsystem") {
	distanceSensor = RobotMap::lidarDistanceSensor;
}

void Positioning::InitDefaultCommand() {
}

double Positioning::GetDistance() {
	return distanceSensor.get()->GetDistance();
}

