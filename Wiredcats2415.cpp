#include "Wiredcats2415.h"

Task2415 *Task2415::TaskList[TASK2415_MAX_TASKS + 1] = {NULL};

#include "Tasks.h"

Wiredcats2415::Wiredcats2415(void) {
	driveJagA = new CANJaguar(2);
	driveJagB = new CANJaguar(6);
	driveJagC = new CANJaguar(5);
	driveJagD = new CANJaguar(9);
	
	liftJagA = new CANJaguar(3);
	liftJagB = new CANJaguar(7);
	liftJagC = new CANJaguar(8);

	gripJag = new CANJaguar(29);
	
	elbowJag = new CANJaguar(4);
	
	stickR = new Joystick(1);
	stickL = new Joystick(2);
}

void Wiredcats2415::Autonomous(void) {
	
}

void Wiredcats2415::OperatorControl(void) {
	encoder->Start();

	while (IsOperatorControl()) {
		driveJagA->Set(stickR->GetY());
		driveJagB->Set(stickR->GetY());
		driveJagC->Set(-stickL->GetY());
		driveJagD->Set(-stickL->GetY());

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

		if (stickR->GetRawButton(3)) {
			elbowJag->Set(0.5);
		} else if (stickR->GetRawButton(3)) {
			elbowJag->Set(-0.5);
		} else {
			elbowJag->Set(0.0);
		}

		if (stickR->GetRawButton(2)) {
			gripJag->Set(0.5);
		} else if (stickL->GetRawButton(2)) {
			gripJag->Set(-0.5);
		} else {
			gripJag->Set(0.0);
		}
	}
}

START_ROBOT_CLASS(Wiredcats2415);

