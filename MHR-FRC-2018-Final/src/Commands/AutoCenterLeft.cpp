/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoCenterLeft.h"

AutoCenterLeft::AutoCenterLeft() {
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDriveDistance(-30, 0,-0.4,0));
	AddSequential(new AutoDrive(-0.8,-0.5,0), 1.7);
	AddSequential(new AutoDriveDistance(50, 0,-0.5,0));
	AddSequential(new ArmPreset(5500));
	AddSequential(new Drool());
}
