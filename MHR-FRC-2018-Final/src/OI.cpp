//Include Headers
#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"

#include "Commands/AutoLeft.h"
#include "Commands/Drive.h"
#include "Commands/Lift.h"
#include "Commands/SwitchDrive.h"
#include "Commands/Grab.h"
#include "Commands/OverrideLiftRotate.h"
#include "Commands/IntakeBox.h"
#include "Commands/ReleaseBox.h"
#include "Commands/CloseClamp.h"
#include "Commands/OpenClamp.h"

OI::OI() {

	//Instantiate the Joystick
    driveJoystick.reset(new frc::Joystick(0));
    manipulatorJoystick.reset(new frc::Joystick(1));
    
    //SwitchDrive Button
    switchDriveButton.reset(new frc::JoystickButton(driveJoystick.get(), 1));
    switchDriveButton->ToggleWhenPressed(new SwitchDrive());

    //Grab Button
    grabButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    grabButton->ToggleWhenPressed(new Grab());

    clampInButton.reset(new frc::JoystickButton(driveJoystick.get(), 8));
    clampInButton->WhenPressed(new CloseClamp());

    clampOutButton.reset(new frc::JoystickButton(driveJoystick.get(), 7));
    clampOutButton->WhenPressed(new OpenClamp());

    //Override Button
    overrideButton.reset(new frc::JoystickButton(driveJoystick.get(), 5));
    overrideButton->ToggleWhenPressed(new OverrideLiftRotate());

    driveEatButton.reset(new frc::JoystickButton(driveJoystick.get(), 10));
    driveEatButton->WhenPressed(new IntakeBox());

    drivePukeButton.reset(new frc::JoystickButton(driveJoystick.get(), 9));
    drivePukeButton->WhenPressed(new ReleaseBox());

    intakeBoxButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 4));
    intakeBoxButton->WhenPressed(new IntakeBox());

    releaseBoxButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 1));
    releaseBoxButton->WhenPressed(new ReleaseBox());
    /*
	autoChooser.AddObject("Start Left", new AutoLeft());
	autoChooser.AddDefault("Start Center", new AutoCenter());
	autoChooser.AddObject("Start Right", new AutoRight());

	frc::SmartDashboard::PutData("Auto Modes", &autoChooser);
*/

    //SmartDashboard Buttons
    frc::SmartDashboard::PutData("Drive", new Drive());
    frc::SmartDashboard::PutData("SwitchDrive", new SwitchDrive());
    frc::SmartDashboard::PutData("Lift", new Lift());
    frc::SmartDashboard::PutData("Grab", new Grab());
    frc::SmartDashboard::PutData("OverrideLiftRotate", new OverrideLiftRotate());
}

std::shared_ptr<frc::Joystick> OI::getDriveJoystick() {

	return driveJoystick;

}

std::shared_ptr<frc::Joystick> OI::getManipulatorJoystick() {
	return manipulatorJoystick;
}

std::shared_ptr<frc::JoystickButton> OI::getOverrideButton() {

	return overrideButton;

}

std::shared_ptr<frc::JoystickButton> OI::getClampInButton() {
	return clampInButton;
}

std::shared_ptr<frc::JoystickButton> OI::getClampOutButton() {
	return clampOutButton;
}
