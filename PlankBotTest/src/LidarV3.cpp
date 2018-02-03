/*
 * LidarV3.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: justi
 */

#include "LidarV3.h"
#include "WPILib.h"

LidarV3::LidarV3(frc::DigitalSource *source) {
	counter = new Counter(source);
	counter->SetMaxPeriod(1.0);
	// Configure for measuring rising to falling pulses
	counter->SetSemiPeriodMode(true);
	counter->Reset();
}

LidarV3::~LidarV3() {
}


/**
 * Take a measurement and return the distance in cm
 *
 * @return Distance in cm
 */
double LidarV3::GetDistance() {
	double cm;
	/* If we haven't seen the first rising to falling pulse, then we have no measurement.
	 * This happens when there is no LIDAR-Lite plugged in, btw.
	 */
	if (counter->Get() < 1) {
		if (printedWarningCount-- > 0) {
			SmartDashboard::PutString("Warnings", "LidarLitePWM: waiting for distance measurement");
		}
		return 0;
	}
	/* getPeriod returns time in seconds. The hardware resolution is microseconds.
	 * The LIDAR-Lite unit sends a high signal for 10 microseconds per cm of distance.
	 */
	cm = (counter->GetPeriod() * 1000000.0 / 10.0) + CALIBRATION_OFFSET;
	return cm;
}

