/*
 * LidarV3.h
 *
 *  Created on: Feb 3, 2018
 *      Author: justi
 */

#ifndef SRC_LIDARV3_H_
#define SRC_LIDARV3_H_

#include "WPILib.h"

class LidarV3 {

private:
	/*
	 * Adjust the Calibration Offset to compensate for differences in each unit.
	 * We've found this is a reasonably constant value for readings in the 25 cm to 600 cm range.
	 * You can also use the offset to zero out the distance between the sensor and edge of the robot.
	 */
	int CALIBRATION_OFFSET = -18;

	Counter *counter;
	int printedWarningCount = 5;

public:
	LidarV3(frc::DigitalSource *source);
	double GetDistance();
	virtual ~LidarV3();
};

#endif /* SRC_LIDARV3_H_ */
