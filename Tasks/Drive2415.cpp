#include "Drive2415.h"

Drive2415::Drive2415(void) {
	global = Global::GetInstance();

	jagLeft = new Jaguar(2);
	jagRight = new Jaguar(1);

	solA = new Solenoid(8, 1);
	solB = new Solenoid(8, 3);

	lightsA = new Relay(2);

	stickL = global->GetLeftJoystick();
	stickR = global->GetRightJoystick();

	taskState = 100;

	Start("drive2415");
}

int Drive2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	printf("entering %s main\n", taskName);
	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP) {
			lightsA->Set(Relay::kForward);

			jagLeft->Set(-stickL->GetY());
			jagRight->Set(stickR->GetY());

			if (!stickL->GetTrigger()) {
				solA->Set(false);
				solB->Set(true);
			} else {
				solA->Set(true);
				solB->Set(false);
			}
		} else if (taskStatus == STATUS_AUTO) {
			solA->Set(false);
			solB->Set(true);

			switch (taskState) {
				case GO_STRAIGHT:
					jagLeft->Set(AUTO_STRAIGHT_SPEED);
					jagRight->Set(-AUTO_STRAIGHT_SPEED);

					break;
				
				case MOVE_BACK:
					jagLeft->Set(-AUTO_STRAIGHT_SPEED);
					jagRight->Set(AUTO_STRAIGHT_SPEED);

					break;
					

				case TURN_SOFT_RIGHT_TO_LINE:
					jagLeft->Set(AUTO_TURN_SPEED);
					jagRight->Set(-AUTO_TURN_SPEED - 0.15);

					break;

				case TURN_SOFT_LEFT_TO_LINE:
					jagLeft->Set(AUTO_TURN_SPEED + 0.15);
					jagRight->Set(-AUTO_TURN_SPEED);

					break;
				
				case TURN_HARD_LEFT_TO_LINE:
					jagLeft->Set(AUTO_TURN_SPEED);
					jagRight->Set(AUTO_TURN_SPEED);

					break;

				case TURN_HARD_RIGHT_TO_LINE:
					jagLeft->Set(-AUTO_TURN_SPEED);
					jagRight->Set(-AUTO_TURN_SPEED);

					break;
				default:
					jagLeft->Set(0.0);
					jagRight->Set(0.0);

					break;
			}
		}

		SwapAndWait();
	}

	return 0;
}

