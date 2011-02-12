// test
#include "WPILib.h"

class Wiredcats2415 : public SimpleRobot {
private:
	CANJaguar *armJagA, *armJagB, *armJagC;
	Joystick *stick;

public:
	Wiredcats2415(void);
	
	void Autonomous();
	void OperatorControl();
};
