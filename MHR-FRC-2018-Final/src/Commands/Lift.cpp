#include "Lift.h"

Lift::Lift(): frc::Command() {

	Requires(Robot::boxLift.get());

}

void Lift::Initialize() {
}

void Lift::Execute() {

	Joystick *joy = Robot::oi.get()->getDriveJoystick().get();
	Joystick *manip = Robot::oi.get()->getManipulatorJoystick().get();

	if (abs(joy->GetRawAxis(5)) > 0.10) {
		Robot::boxLift.get()->Rotate(joy->GetRawAxis(5));
	} else {
		Robot::boxLift.get()->Rotate(manip->GetRawAxis(5));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Lift::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Lift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lift::Interrupted() {

}
