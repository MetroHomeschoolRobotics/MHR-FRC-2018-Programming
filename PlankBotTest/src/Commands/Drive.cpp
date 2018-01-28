#include "Drive.h"

Drive::Drive(): frc::Command() {

	Requires(Robot::octaDrive.get());

}

void Drive::Initialize() {
}

void Drive::Execute() {

	Joystick *joy = Robot::oi.get()->getDriveJoystick().get();

	Robot::octaDrive.get()->Move(
			joy->GetRawAxis(0),
			joy->GetRawAxis(1),
			joy->GetRawAxis(2) - joy->GetRawAxis(3));

}

bool Drive::IsFinished() {

	return false;

}

void Drive::End() {
}

void Drive::Interrupted() {
}
