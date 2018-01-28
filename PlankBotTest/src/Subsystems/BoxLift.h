#ifndef BoxLift_H
#define BoxLift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BoxLift : public frc::Subsystem {

private:

	std::shared_ptr<frc::Spark> liftMotor;
	std::shared_ptr<frc::DoubleSolenoid> grabSol1;

	double threshold = 0.1;
	bool isHold = false;

public:

	BoxLift();
	void InitDefaultCommand();
	void Rotate(double r);
	void Grab();

};

#endif
