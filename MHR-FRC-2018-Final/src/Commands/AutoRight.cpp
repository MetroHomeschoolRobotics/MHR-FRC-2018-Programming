#include "AutoRight.h"

AutoRight::AutoRight() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get())
	Requires(Robot::autonomousSys.get());
}

// Called just before this Command runs the first time
void AutoRight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoRight::Execute() {
	Robot::autonomousSys.get()->AutoLeft();

}

// Make this return true when this Command no longer needs to run execute()
bool AutoRight::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoRight::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRight::Interrupted() {

}
