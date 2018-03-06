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
#include "Commands/Eject.h"
#include "Commands/ChargePneumatics.h"
#include "Commands/Drool.h"

OI::OI() {

	//Instantiate the Joystick
    driveJoystick.reset(new frc::Joystick(0));
    manipulatorJoystick.reset(new frc::Joystick(1));
    
    //SwitchDrive Button
    switchDriveButton.reset(new frc::JoystickButton(driveJoystick.get(), 1));
    switchDriveButton->ToggleWhenPressed(new SwitchDrive());

    manipSwitchDriveButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 1));
    manipSwitchDriveButton->ToggleWhenPressed(new SwitchDrive());

    //Grab Button
    grabButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    grabButton->ToggleWhenPressed(new Grab());

    manipGrabButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 4));
    manipGrabButton->ToggleWhenPressed(new Grab());

    //Override Button
    overrideButton.reset(new frc::JoystickButton(driveJoystick.get(), 5));
    overrideButton->ToggleWhenPressed(new OverrideLiftRotate());

    manipOverrideButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 5));
    manipOverrideButton->ToggleWhenPressed(new OverrideLiftRotate());

    driveEatButton.reset(new frc::JoystickButton(driveJoystick.get(), 3));
    driveEatButton->WhenPressed(new IntakeBox());

    manipEatButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 3));
    manipEatButton->WhenPressed(new IntakeBox());

    drivePukeButton.reset(new frc::JoystickButton(driveJoystick.get(), 2));
    drivePukeButton->WhenPressed(new ReleaseBox());

    manipPukeButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 2));
    manipPukeButton->WhenPressed(new ReleaseBox());

    droolButton.reset(new frc::JoystickButton(driveJoystick.get(), 6));
    droolButton->WhenPressed(new Drool());

    manipDroolButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 6));
    manipDroolButton->WhenPressed(new Drool());


    //SmartDashboard Buttons
    frc::SmartDashboard::PutData("Charge Pneumatics", new ChargePneumatics());
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

std::shared_ptr<frc::JoystickButton> OI::getManipOverrideButton(){
	return manipOverrideButton;
}

std::shared_ptr<frc::JoystickButton> OI::getClampInButton() {
	return clampInButton;
}

std::shared_ptr<frc::JoystickButton> OI::getClampOutButton() {
	return clampOutButton;
}
