//Include Headers
#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Auto.h"
#include "Commands/Drive.h"
#include "Commands/Lift.h"
#include "Commands/SwitchDrive.h"
#include "Commands/Grab.h"

OI::OI() {

	//Instantiate the Joystick
    driveJoystick.reset(new frc::Joystick(0));
    
    //SwitchDrive Button
    switchDriveButton.reset(new frc::JoystickButton(driveJoystick.get(), 1));
    switchDriveButton->ToggleWhenPressed(new SwitchDrive());

    //Grab Button
    grabButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    grabButton->ToggleWhenPressed(new Grab());

    //SmartDashboard Buttons
    frc::SmartDashboard::PutData("Auto", new Auto());
    frc::SmartDashboard::PutData("Drive", new Drive());
    frc::SmartDashboard::PutData("SwitchDrive", new SwitchDrive());
    frc::SmartDashboard::PutData("Lift", new Lift());
    frc::SmartDashboard::PutData("Grab", new Grab());

}

std::shared_ptr<frc::Joystick>

OI::getDriveJoystick() {

	return driveJoystick;

}
