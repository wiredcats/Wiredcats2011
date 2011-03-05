#include "Gripper2415.h"

Gripper2415::Gripper2415(void) {
	global = Global::GetInstance();
	jagGripper = new Jaguar(5);

	stickL = global->GetLeftJoystick();
	stickR = global->GetRightJoystick();

	taskState = WAIT_FOR_GRIP_INPUT;

	Start("gripper2415");
}

int Gripper2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	printf("entering %s main\n", taskName);
	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP || STATUS_AUTO) {
			switch (taskState) {
				case WAIT_FOR_GRIP_INPUT:
					if (stickL->GetRawButton(2)) {
						jagGripper->Set(0.8);
					} else {
						jagGripper->Set(-0.8);
					}
					break;
				
				case DELAY_GRIP_MOTOR:
					jagGripper->Set(0.0);
					break;

				case SCORE_RUN_BACK:
					jagGripper->Set(0.4);
					break;
			}
		}
		SwapAndWait();
	}

	return 0;
}

