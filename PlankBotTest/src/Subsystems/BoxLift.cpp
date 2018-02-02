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

	//Sets Threshold
	if(fabs(r) < threshold) {
			r = 0;
	}

	//Grabs Encoder Values as Integer "count"
	int count = liftMotor.get()->GetSelectedSensorPosition(0);

	//Divides Speed by Two
	r /= 2;

	//Restricts Movement Between Encoder Values
	if (count > -3500 && count < 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Allows Up Movement Into Range
	} else if (count < -3500 && r < 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Allows Down Movement Into Range
	} else if (count >= -50 && r > 0) {

		//Sets Motor Speed
		liftMotor.get()->Set(r);

	//Sets Speed to Zero If Outside Range
	} else {

		//Sets Motor Speed
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

