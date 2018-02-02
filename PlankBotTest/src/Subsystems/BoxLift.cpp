#include "BoxLift.h"
#include "../RobotMap.h"
#include <cmath>

BoxLift::BoxLift() : frc::Subsystem("BoxLift") {

	liftMotor = RobotMap::liftMotor;
	grabSol1 = RobotMap::liftGrabSol1;
	liftEncoder = RobotMap::liftMotorEncoder;

}

void BoxLift::InitDefaultCommand() {
}

void BoxLift::Rotate(double r){

	if(fabs(r) < threshold) {
			r = 0;
	}

	int count = liftMotor.get()->GetSelectedSensorPosition(0);

	//r = pow(r,3);
	r /= 2;
	if (count > -480 && count < 2500) {

		liftMotor.get()->Set(r);

	} else if (count < -480 && r < 0) {

		liftMotor.get()->Set(r);

	} else if (count > 2500 && r > 0) {

		liftMotor.get()->Set(r);

	} else {

		liftMotor.get()->Set(0.0);

	}







	SmartDashboard::PutNumber("Rotation Count", count);

}

void BoxLift::Grab(){

	isHold = !isHold;

	if (isHold){
		grabSol1.get()->Set(frc::DoubleSolenoid::Value::kReverse);
	} else {
		grabSol1.get()->Set(frc::DoubleSolenoid::Value::kForward);
	}

}

