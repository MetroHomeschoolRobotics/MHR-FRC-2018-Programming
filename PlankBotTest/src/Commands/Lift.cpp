#include "Lift.h"

Lift::Lift(): frc::Command() {

	Requires(Robot::boxLift.get());

}

void Lift::Initialize() {
}

void Lift::Execute() {

	Joystick *joy = Robot::oi.get()->getDriveJoystick().get();

	Robot::boxLift.get()->Rotate(joy->GetRawAxis(4));

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
