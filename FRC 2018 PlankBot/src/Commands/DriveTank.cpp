#include "DriveTank.h"

DriveTank::DriveTank() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveTank::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveTank::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveTank::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveTank::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTank::Interrupted() {

}
