// test
#include "Arm2415.h"

Arm2415::Arm2415(void) {
	Start("arm2415");
}

int Arm2415::Main(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	while (keepTaskAlive) {
		if (taskStatus == STATUS_TELEOP) {
			int i;
			for (i = 0; i < 100; i++) {
				printf("[%d] chillin in arm\n", i);
				SwapAndWait();
			}
		}
	}
	
	return 0;
}
