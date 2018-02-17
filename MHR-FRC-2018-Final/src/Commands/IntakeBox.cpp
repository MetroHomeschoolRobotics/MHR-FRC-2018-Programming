#include "IntakeBox.h"

IntakeBox::IntakeBox() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::boxLift.get());
}

// Called just before this Command runs the first time
void IntakeBox::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void IntakeBox::Execute() {
Robot::boxLift.get()->EatBox(true);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeBox::IsFinished() {
	return !Robot::oi.get()->getManipulatorJoystick()->GetRawButton(4) && !Robot::oi.get()->getDriveJoystick()->GetRawButton(3);
}

// Called once after isFinished returns true
void IntakeBox::End() {
Robot::boxLift.get()->EatBox(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeBox::Interrupted() {

}
