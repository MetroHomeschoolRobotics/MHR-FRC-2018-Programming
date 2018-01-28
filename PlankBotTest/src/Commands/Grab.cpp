#include "Grab.h"

Grab::Grab(): frc::Command() {
}

void Grab::Initialize() {
}

void Grab::Execute() {

	Robot::boxLift.get()->Grab();

}

bool Grab::IsFinished() {

	return true;

}

void Grab::End() {
}

void Grab::Interrupted() {
}
