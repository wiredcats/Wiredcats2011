// test
#include "WPILib.h"
#include "Task2415.h"

class Wiredcats2415 : public SimpleRobot {
private:
	CANJaguar *liftJagA, *liftJagB, *liftJagC, *driveJagA, *driveJagB, *driveJagC, *driveJagD, *gripJag, *elbowJag;
	Joystick *stickL, *stickR;
	Encoder *encoder;

public:
	Wiredcats2415(void);
	
	void Autonomous();
	void OperatorControl();
};
