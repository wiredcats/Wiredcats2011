#ifndef ARM2415_H_
#define ARM2415_H_

#include "WPILib.h"
#include "../Task2415.h"

class Arm2415 : public Task2415 {
public:
	Arm2415(void);
	
	virtual int Main(int a2, int a3, int a4, int a5, int a6, int a7,
					  int a8, int a9, int a10);
};

#endif
