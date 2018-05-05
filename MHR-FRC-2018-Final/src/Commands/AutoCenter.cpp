#include "AutoCenter.h"

AutoCenter::AutoCenter() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoCenter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoCenter::Execute() {
	int direction = Robot::autonomousSys.get()->FindDirection();
	if (direction == 0) {
		Scheduler::GetInstance()->AddCommand(new AutoCenterLeft());
	} else if (direction == 1) {
		Scheduler::GetInstance()->AddCommand(new AutoCenterRight());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCenter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoCenter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCenter::Interrupted() {

}
