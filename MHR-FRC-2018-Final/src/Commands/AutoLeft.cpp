#include "AutoLeft.h"

AutoLeft::AutoLeft(): frc::Command() {
	//Requires(Robot::autonomousSys.get());
}

void AutoLeft::Initialize() {
}

void AutoLeft::Execute() {
	//Robot::autonomousSys.get()->AutoLeft();
	int direction = Robot::autonomousSys.get()->FindDirection();
	if (direction == 0) {
		Scheduler::GetInstance()->AddCommand(new AutoLeftLeft());
	} else if (direction == 1) {
		Scheduler::GetInstance()->AddCommand(new AutoLeftRight());
	}
}

bool AutoLeft::IsFinished() {

	return true;

}

void AutoLeft::End() {
}

void AutoLeft::Interrupted() {
}
