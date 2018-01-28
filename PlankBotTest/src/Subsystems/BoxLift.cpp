#include "BoxLift.h"
#include "../RobotMap.h"
#include <cmath>

BoxLift::BoxLift() : frc::Subsystem("BoxLift") {

	liftMotor = RobotMap::liftMotor;
	grabSol1 = RobotMap::liftGrabSol1;

}

void BoxLift::InitDefaultCommand() {
}

void BoxLift::Rotate(double r){

	if(fabs(r) < threshold) {
			r = 0;
	}

	r = pow(r,3);
	liftMotor->Set(r);
}

void BoxLift::Grab(){

	isHold = !isHold;

	if (isHold){
		grabSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
	} else {
		grabSol1.get()->Set(frc::DoubleSolenoid::Value::kForward);
	}

}

