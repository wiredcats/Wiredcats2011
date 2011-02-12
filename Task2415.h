// test
#ifndef TASK2415_H_
#define TASK2415_H_

#include "WPILib.h"

#define TASK2415_DEFAULT_PRIORITY (200)
#define TASK2415_STACKSIZE (1024 * 64)
#define TASK2415_MAX_TASKS (32)

class Task2415 {
protected:
	bool isAwake;
	bool keepTaskAlive;

public:
	Task2415(void);
	
	void Start(char * id);
	static int TaskWrapper(void *this_p, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
	virtual int Main(int a2, int a3, int a4, int a5, int a6,  int a7, int a8, int a9, int a10) = 0;
	
	void SwapAndWait();
};

#endif
