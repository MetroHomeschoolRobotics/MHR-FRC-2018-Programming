/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PneumaticCharging.h"

PneumaticCharging::PneumaticCharging() : Subsystem("Pneumatic Charging") {
	pneumoCharger = RobotMap::pneumoCharger;
}

void PneumaticCharging::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void PneumaticCharging::Charge() {
	pneumoCharger.get()->SetClosedLoopControl(true);
}

void PneumaticCharging::StopCharging() {
	pneumoCharger.get()->SetClosedLoopControl(false);
}

bool PneumaticCharging::ChargeComplete() {
	return pneumoCharger.get()->GetPressureSwitchValue();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
