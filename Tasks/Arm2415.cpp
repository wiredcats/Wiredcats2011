#include "Arm2415.h"

Arm2415::Arm2415(void) {
	global = Global::GetInstance();

	jagArm = new CANJaguar(10);

	Start("arm2415");
}

int Arm2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	printf("entering %s main", taskName);
	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP) {
			if (global->GetAnalogButton(3)) {
				jagArm->Set(-0.6);
			} else if (global->GetAnalogButton(5)) {
				jagArm->Set(0.6);
			} else {
				jagArm->Set(0.0);
			}
		}
		SwapAndWait();
	}

	return 0;
}

