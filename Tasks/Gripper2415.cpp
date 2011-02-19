#include "Gripper2415.h"

Gripper2415::Gripper2415(void) {
	global = Global::GetInstance();
	jagGripper = new CANJaguar(4);

	stickL = global->GetLeftJoystick();
	stickR = global->GetRightJoystick();

	Start("gripper2415");
}

int Gripper2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	printf("entering %s main", taskName);
	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP) {
			if (global->GetDigitalButton(4)) {
				jagGripper->Set(0.8);
			} else if (global->GetDigitalButton(2)) {
				jagGripper->Set(-0.8);
			} else {
				jagGripper->Set(0.0);
			}
		}
		SwapAndWait();
	}

	return 0;
}

