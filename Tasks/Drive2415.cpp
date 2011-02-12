#include "Drive2415.h"

Drive2415::Drive2415(void) {
	Start("drive2415");
}

int Drive2415::Main(int a2, int a3, int a4, int a5, int a6,
					 int a7, int a8, int a9, int a10) {
	int i;
	for (i = 0; i < 100; i++) {
		printf("[%d] chillin in drive\n", i);
		SwapAndWait();
	}
	
	return 0;
}
