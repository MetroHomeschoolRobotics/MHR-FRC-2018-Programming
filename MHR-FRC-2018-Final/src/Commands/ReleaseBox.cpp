#include "ReleaseBox.h"

ReleaseBox::ReleaseBox() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::boxLift.get());
}

// Called just before this Command runs the first time
void ReleaseBox::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ReleaseBox::Execute() {
	Robot::boxLift.get()->PukeBox(true);
}

// Make this return true when this Command no longer needs to run execute()
bool ReleaseBox::IsFinished() {
	return !Robot::oi.get()->getManipulatorJoystick()->GetRawButton(1) && !Robot::oi.get()->getDriveJoystick()->GetRawButton(3);
}

// Called once after isFinished returns true
void ReleaseBox::End() {
	Robot::boxLift.get()->PukeBox(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseBox::Interrupted() {

}
