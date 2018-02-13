#ifndef BoxLift_H
#define BoxLift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

class BoxLift : public frc::Subsystem {

private:

	std::shared_ptr<WPI_TalonSRX> liftMotor;
	std::shared_ptr<frc::DoubleSolenoid> grabSol1;
	std::shared_ptr<frc::Encoder> liftEncoder;

	double threshold = 0.1;
	bool isHold = false;
	bool inRangeOverride = false;

public:

	BoxLift();
	void InitDefaultCommand();
	void Rotate(double r);
	void Grab();
	void SetOverride(bool active);
    void EatBox(bool start);
    void PukeBox(bool start);

};

#endif
