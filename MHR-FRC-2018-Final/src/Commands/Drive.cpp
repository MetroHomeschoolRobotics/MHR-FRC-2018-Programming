#include "Drive.h"

Drive::Drive(): frc::Command() {

	//Requires(Robot::octaDrive.get());

}

void Drive::Initialize() {
}

void Drive::Execute() {

	Joystick *joy = Robot::oi.get()->getDriveJoystick().get();
	Joystick *manip = Robot::oi.get()->getManipulatorJoystick().get();

	double total = abs(joy->GetRawAxis(0)) +abs(joy->GetRawAxis(1)) +abs(joy->GetRawAxis(2)) +abs(joy->GetRawAxis(3));
	if (total > Robot::tankDrive.get()->threshold*2) {
		Robot::octaDrive.get()->Move(
				joy->GetRawAxis(0),
				joy->GetRawAxis(1),
				joy->GetRawAxis(2) - joy->GetRawAxis(3));
	} else {
		Robot::octaDrive.get()->Move(
				manip->GetRawAxis(0),
				manip->GetRawAxis(1),
				manip->GetRawAxis(2) - manip->GetRawAxis(3));

	}
}

bool Drive::IsFinished() {

	return false;

}

void Drive::End() {
}

void Drive::Interrupted() {
}
