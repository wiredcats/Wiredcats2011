#include "Drive2415.h"

Drive2415::Drive2415(void) {
	global = Global::GetInstance();

	jagUL = new CANJaguar(3);
	jagDL = new CANJaguar(9);
	jagUR = new CANJaguar(22);
	jagDR = new CANJaguar(8);

	solA = new Solenoid(8, 1);
	solB = new Solenoid(8, 3);

	stickL = global->GetLeftJoystick();
	stickR = global->GetRightJoystick();

	Start("drive2415");
}

int Drive2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	printf("entering %s main", taskName);
	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP) {
			jagUL->Set(-stickL->GetY());
			jagDL->Set(-stickL->GetY());
			jagUR->Set(stickR->GetY());
			jagDR->Set(stickR->GetY());

			if (stickL->GetTrigger()) {
				solA->Set(false);
				solB->Set(true);
			} else {
				solA->Set(true);
				solB->Set(false);
			}
		}
		SwapAndWait();
	}

	return 0;
}

