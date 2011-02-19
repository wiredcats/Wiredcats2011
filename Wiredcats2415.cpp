#include "Wiredcats2415.h"
#include <math.h>

Task2415 *Task2415::TaskList[TASK2415_MAX_TASKS + 1] = {NULL};
int Task2415::TasksListed = 0;
int Task2415::TasksSwapped = 0;

Global global;

#include "Tasks.h"

double RampSpeed(double x, double delta, double multi);
const double PI = 3.14159;

Wiredcats2415::Wiredcats2415(void) {
/*	
	liftJagA = new CANJaguar(3);
	liftJagB = new CANJaguar(22);
	liftJagC = new CANJaguar(8);

	gripJag = new CANJaguar(29);
	
	elbowJag = new CANJaguar(4);
	
	stickR = new Joystick(1);
	stickL = new Joystick(2);

	encoder = new Encoder(1, 4);
	pot = new AnalogChannel(1, 1);
	
	solA = new Solenoid(8, 1);
	solB = new Solenoid(8, 8);
*/
	
	comp = new Compressor(5, 1);
}

void Wiredcats2415::Autonomous(void) {
	
}

void Wiredcats2415::OperatorControl(void) {
	Task2415::SetTaskStatuses(STATUS_TELEOP);
//	encoder->Start();
	comp->Start();
/*	double liftSpeed = 0;
	bool runRamp = false;
	bool firstTime = true;

	int initEncoderValue = 0;
	int encoderGoal = 0;
	int liftSign = 0;

	bool moveElbow = false;
	bool elbowDown = true;

	while (IsOperatorControl()) {
		if (!liftJagA->GetForwardLimitOK()) {
			encoder->Reset();
		}

		if (stickR->GetRawButton(4)) {
			runRamp = true;
			initEncoderValue = encoder->Get();
			encoderGoal = 0;
			if (encoderGoal > initEncoderValue) liftSign = -1;
			else				    liftSign = 1;
		} else if (stickR->GetRawButton(3)) {
			runRamp = true;
			initEncoderValue = encoder->Get();
			encoderGoal = 1200;
			if (encoderGoal > initEncoderValue) liftSign = -1;
			else				    liftSign = 1;
		} else if (stickR->GetRawButton(5)) {
			runRamp = true;
			initEncoderValue = encoder->Get();
			encoderGoal = 2800;
			if (encoderGoal > initEncoderValue) liftSign = -1;
			else				    liftSign = 1;
		}

		if (runRamp) {
			if ((encoder->Get() >= encoderGoal && liftSign < 0) || (encoder->Get() <= encoderGoal && liftSign > 0)) {
				printf("done with ramp\n");
				runRamp = false;
				liftJagA->Set(0.0);
				liftJagB->Set(0.0);
				liftJagC->Set(0.0);
			} else {
				liftSpeed = RampSpeed(abs(initEncoderValue - encoder->Get()), abs(encoderGoal - initEncoderValue), 2.0);
				if (liftSpeed >= 1.0) liftSpeed = 1.0;
				else if (liftSpeed <= 0.2) liftSpeed = 0.2;

				liftJagA->Set(liftSign * liftSpeed);
				liftJagB->Set(liftSign * liftSpeed);
				liftJagC->Set(liftSign * liftSpeed);
				printf("lift [%3.2f]\tenc [%d]", liftSign * liftSpeed, encoder->Get());
			}
		} else if (firstTime) {
			if (!liftJagA->GetForwardLimitOK()) {
				firstTime = false;
				liftJagA->Set(0.0);
				liftJagB->Set(0.0);
				liftJagC->Set(0.0);
				encoder->Reset();
			} else {
				liftJagA->Set(0.3);
				liftJagB->Set(0.3);
				liftJagC->Set(0.3);
			}
		} else {
			if (stickR->GetRawButton(5)) {
				runRamp = true;
			}

			if (stickR->GetTrigger()) {
				liftJagA->Set(0.4);
				liftJagB->Set(0.4);
				liftJagC->Set(0.4);
			} else if (stickL->GetTrigger()) {
				liftJagA->Set(-0.4);
				liftJagB->Set(-0.4);
				liftJagC->Set(-0.4);
			} else {
				liftJagA->Set(0.0);
				liftJagB->Set(0.0);
				liftJagC->Set(0.0);
			}
		}
		
		if (stickL->GetRawButton(3)) {
			moveElbow = true;
		}
		
		if (moveElbow) {
			printf("speed [%3.2f]", RampSpeed((2.35 - pot->GetVoltage()), 1.20, 0.3));

			if (elbowDown) {
				if (pot->GetVoltage() <= 1.2) {
					elbowDown = false;
					moveElbow = false;
				} else {
					elbowJag->Set(-RampSpeed((2.35 - pot->GetVoltage()), 1.15, 0.25));
				}
			} else {
				if (pot->GetVoltage() >= 2.28) {
					elbowDown = true;
					moveElbow = false;
				} else {
					elbowJag->Set(RampSpeed((2.35 - pot->GetVoltage()), 1.15, 0.25));
				}
			}
		} else {
			if (stickL->GetRawButton(11)) {
				elbowJag->Set(0.5);
			} else if (stickL->GetRawButton(10)) {
				elbowJag->Set(-0.5);
			} else {
				elbowJag->Set(0.0);
			}
		}

		if (stickR->GetRawButton(2)) {
			gripJag->Set(0.5);
		} else if (stickL->GetRawButton(2)) {
			gripJag->Set(-0.5);
		} else {
			gripJag->Set(0.0);
		}

		Wait(0.05);
	}
*/}

double RampSpeed(double x, double delta, double multi) {
/*	double speed = multi * sin((PI * x) / delta) + 0.35;
	if (speed >= 1.0) return 1.0;
	if (speed <= 0.2) return 0.2;
	return speed;
*/
	return 0;
}

START_ROBOT_CLASS(Wiredcats2415);

