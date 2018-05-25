//Define
#ifndef OI_H
#define OI_H

//Include Headers
#include "WPILib.h"

class OI {

private:

	//Create Private Objects
	std::shared_ptr<frc::Joystick> driveJoystick;
	std::shared_ptr<frc::Joystick> manipulatorJoystick;
	std::shared_ptr<frc::JoystickButton> switchDriveButton;
	std::shared_ptr<frc::JoystickButton> grabButton;
	std::shared_ptr<frc::JoystickButton> overrideButton;
	std::shared_ptr<frc::JoystickButton> releaseBoxButton;
	std::shared_ptr<frc::JoystickButton> intakeBoxButton;
	std::shared_ptr<frc::JoystickButton> clampInButton;
	std::shared_ptr<frc::JoystickButton> clampOutButton;
	std::shared_ptr<frc::JoystickButton> driveEatButton;
	std::shared_ptr<frc::JoystickButton> drivePukeButton;
	frc::SendableChooser<frc::Command*> *autoChooser;
	std::shared_ptr<frc::JoystickButton> ejectButton;
	std::shared_ptr<frc::JoystickButton> droolButton;

	std::shared_ptr<frc::JoystickButton> manipSwitchDriveButton;
	std::shared_ptr<frc::JoystickButton> manipGrabButton;
	std::shared_ptr<frc::JoystickButton> manipOverrideButton;
	std::shared_ptr<frc::JoystickButton> manipReleaseBoxButton;
	std::shared_ptr<frc::JoystickButton> manipIntakeBoxButton;
	std::shared_ptr<frc::JoystickButton> manipEatButton;
	std::shared_ptr<frc::JoystickButton> manipPukeButton;
	std::shared_ptr<frc::JoystickButton> manipDroolButton;

public:

	OI();

	void SetupDashboard();

	//Create Private Inputs
	std::shared_ptr<frc::Joystick> getDriveJoystick();
	std::shared_ptr<frc::Joystick> getManipulatorJoystick();
	std::shared_ptr<frc::JoystickButton> getSwitchDriveButton();
	std::shared_ptr<frc::JoystickButton> getOverrideButton();
	std::shared_ptr<frc::JoystickButton> getManipOverrideButton();
	frc::SendableChooser<frc::Command*> *getAutoChooser();
	std::shared_ptr<frc::JoystickButton> getClampInButton();
	std::shared_ptr<frc::JoystickButton> getClampOutButton();
};

#endif
