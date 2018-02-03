#include "OverrideLiftRotate.h"

OverrideLiftRotate::OverrideLiftRotate(): frc::Command() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void OverrideLiftRotate::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OverrideLiftRotate::Execute() {
	Robot::boxLift.get()->SetOverride(true);
}

// Make this return true when this Command no longer needs to run execute()
bool OverrideLiftRotate::IsFinished() {
	return !Robot::oi.get()->getOverrideButton().get()->Get();
}

// Called once after isFinished returns true
void OverrideLiftRotate::End() {
	Robot::boxLift.get()->SetOverride(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OverrideLiftRotate::Interrupted() {

}
