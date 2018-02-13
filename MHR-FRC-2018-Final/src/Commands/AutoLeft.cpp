#include "AutoLeft.h"

AutoLeft::AutoLeft(): frc::Command() {
	Requires(Robot::autonomousSys.get());
}

void AutoLeft::Initialize() {
}

void AutoLeft::Execute() {
	Robot::autonomousSys.get()->AutoLeft();
}

bool AutoLeft::IsFinished() {

	return false;

}

void AutoLeft::End() {
}

void AutoLeft::Interrupted() {
}
