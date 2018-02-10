#include "SwitchDrive.h"

SwitchDrive::SwitchDrive(): frc::Command() {
}

void SwitchDrive::Initialize() {
}

void SwitchDrive::Execute() {

	Robot::octaDrive.get()->SwitchMode();

}

bool SwitchDrive::IsFinished() {

	return true;

}

void SwitchDrive::End() {
}

void SwitchDrive::Interrupted() {
}
