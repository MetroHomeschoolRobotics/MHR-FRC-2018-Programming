/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoCenterRight.h"

AutoCenterRight::AutoCenterRight() {
	AddSequential(new SwitchDrive());
	AddSequential(new AutoDriveDistance(50, 0,-0.5,0));
	AddSequential(new ArmPreset(5500));
	AddSequential(new ArmPreset(5500));
	AddSequential(new Drool());
}
