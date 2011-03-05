#include "Deployment2415.h"

Deployment2415::Deployment2415(void) {
	global = Global::GetInstance();

	Start("deployment2415");
}

int Deployment2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	printf("entering %s main", taskName);
	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP) {
			// teleop schmazz
		}
		SwapAndWait();
	}

	return 0;
}

