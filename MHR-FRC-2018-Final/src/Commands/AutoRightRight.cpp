/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoRightRight.h"

AutoRightRight::AutoRightRight() {
	AddSequential(new AutoDriveRotation(22000, 0,-0.5,0,FrontLeft));
	AddSequential(new ArmPreset(8000));
	AddSequential(new Drool());
}
