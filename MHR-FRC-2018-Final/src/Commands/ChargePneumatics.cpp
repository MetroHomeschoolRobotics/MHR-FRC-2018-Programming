/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ChargePneumatics.h"
#include "../Robot.h"

ChargePneumatics::ChargePneumatics() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::pneumatics.get());
}

// Called just before this Command runs the first time
void ChargePneumatics::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ChargePneumatics::Execute() {
	Robot::pneumatics.get()->Charge();
}

// Make this return true when this Command no longer needs to run execute()
bool ChargePneumatics::IsFinished() {
	return Robot::pneumatics.get()->ChargeComplete();
}

// Called once after isFinished returns true
void ChargePneumatics::End() {
	Robot::pneumatics.get()->StopCharging();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChargePneumatics::Interrupted() {

}
