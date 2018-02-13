#include "AutoCenter.h"

AutoCenter::AutoCenter() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::autonomousSys.get());
}

// Called just before this Command runs the first time
void AutoCenter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoCenter::Execute() {
	Robot::autonomousSys.get()->AutoCenter();
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenter::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoCenter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenter::Interrupted() {

}
