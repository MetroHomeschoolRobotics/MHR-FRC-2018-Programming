//Define
#ifndef OI_H
#define OI_H

//Include Headers
#include "WPILib.h"

class OI {

private:

	//Create Private Objects
	std::shared_ptr<frc::Joystick> driveJoystick;
	std::shared_ptr<frc::JoystickButton> switchDriveButton;
	std::shared_ptr<frc::JoystickButton> grabButton;
	std::shared_ptr<frc::JoystickButton> overrideButton;

public:

	OI();

	//Create Private Inputs
	std::shared_ptr<frc::Joystick> getDriveJoystick();
	std::shared_ptr<frc::JoystickButton> getSwitchDriveButton();
	std::shared_ptr<frc::JoystickButton> getOverrideButton();

};

#endif
