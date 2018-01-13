/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/Phoenix.h>

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
constexpr int kLeftFrontMotor = 1;
constexpr int kLeftRearMotor = 2;
constexpr int kRightFrontMotor = 3;
constexpr int kRightRearMotor = 4;
constexpr int kExtraTalonSRX = 5;

constexpr int pwmTalon1 = 1;
constexpr int pwmTalon2 = 2;
constexpr int pwmSpark1 = 3;
constexpr int pwmSpark2 = 4;

constexpr int pcmDoubleSolenoidIn = 1;
constexpr int pcmDoubleSolenoidOut = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;


WPI_TalonSRX *frontLeftDriveMotor = new WPI_TalonSRX(kLeftFrontMotor);
WPI_TalonSRX *rearLeftDriveMotor = new WPI_TalonSRX(kLeftRearMotor);
WPI_TalonSRX *frontRightDriveMotor = new WPI_TalonSRX(kRightFrontMotor);
WPI_TalonSRX *rearRightDriveMotor = new WPI_TalonSRX(kRightRearMotor);
