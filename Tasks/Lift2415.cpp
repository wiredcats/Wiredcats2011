#include "Lift2415.h"

Lift2415::Lift2415(void) {
	global = Global::GetInstance();

	jagLiftA = new CANJaguar(6);
	jagLiftB = new CANJaguar(5);
	jagLiftC = new CANJaguar(2);

	stickL = global->GetLeftJoystick();
	stickR = global->GetRightJoystick();

	encoder = new Encoder(1, 3);

	Start("lift2415");
}

int Lift2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	printf("entering %s main", taskName);

	encoder->Start();

	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP) {
			printf("enc: [%d]\n", encoder->Get());
			if (global->GetAnalogButton(1)) {
				SyncMotorLift(-0.6);
			} else if (global->GetAnalogButton(8)) {
				SyncMotorLift(0.3);
			} else {
				SyncMotorLift(0.0);
			}
		}
		SwapAndWait();
	}

	return 0;
}

void Lift2415::SyncMotorLift(float speed) {
	jagLiftA->Set(speed);
	jagLiftB->Set(speed);
	jagLiftC->Set(speed);
}

