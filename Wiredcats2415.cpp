#include "Wiredcats2415.h"
#include "Tasks.h"

Wiredcats2415::Wiredcats2415(void) {
	armJagA = new CANJaguar(7);
	armJagB = new CANJaguar(3);
	armJagC = new CANJaguar(8);
	
	stick = new Joystick(1);
}

void Wiredcats2415::Autonomous(void) {
	
}

void Wiredcats2415::OperatorControl(void) {
	int ticks = 0;
	/*
	while (IsOperatorControl()) {
		armJagA->Set(stick->GetY());
		armJagB->Set(stick->GetY());
		armJagC->Set(stick->GetY());
		
		if (ticks % 10 == 0) printf("joystick: [%f]", stick->GetY());
		ticks++;

		Wait(0.05);
	}
	*/	
}

START_ROBOT_CLASS(Wiredcats2415);

