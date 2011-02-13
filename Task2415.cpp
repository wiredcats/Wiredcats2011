#include "Task2415.h"

Task2415::Task2415(void) {
	taskID = 0;
	taskStatus = STATUS_BLANK;

	isAwake = false;
	keepTaskAlive = true;
}

void Task2415::Start(char * id) {
	taskID = taskSpawn(id, TASK2415_DEFAULT_PRIORITY, VX_FP_TASK, TASK2415_STACKSIZE,
			   (FUNCPTR) Task2415::TaskWrapper, (int)this, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

int Task2415::TaskWrapper(void *this_p, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	int j;
	for (j = 0; j < TASK2415_MAX_TASKS; j++) 
		if (TaskList[j] == NULL) break;

	TaskList[j] = (Task2415 *)this_p;

	return ((Task2415 *)this_p)->Main(a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

void Task2415::SetTaskStatuses(TASK_STATUS ts) {
	int j;
	for (j = 0; j < TASK2415_MAX_TASKS; j++) {
		if (TaskList[j] == NULL) break;
		TaskList[j]->SetIndividualStatus(ts);
	}
}

void Task2415::SetIndividualStatus(TASK_STATUS ts) {
	taskStatus = ts;
}

void Task2415::SwapAndWait(void) {
	taskUnlock();
	taskDelay(2);
	taskLock();
}
