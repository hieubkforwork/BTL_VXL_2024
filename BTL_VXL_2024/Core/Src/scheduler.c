/*
 * scheduler.c
 *
 *  Created on: Nov 24, 2024
 *      Author: ACER
 */

#include "scheduler.h"

sTasks SCH_TASKS_G[SCH_MAX_TASKS];
uint8_t index_val = 0;

void SCH_INIT(void) {
	// ------------------------------------------------
	// Readme:
	// - Scheduler init with number of task is 0
	// ------------------------------------------------
	index_val = 0;
}
void SCH_UPDATE(void) {
	// ------------------------------------------------
	// Readme:
	// - Scheduler update = SetTimer
	// ------------------------------------------------
	for (int i = 0; i < index_val; i++) {
		if (SCH_TASKS_G[i].Delay > 0)
			SCH_TASKS_G[i].Delay--;
		else {
			SCH_TASKS_G[i].Delay = SCH_TASKS_G[i].Period;
			SCH_TASKS_G[i].RunMe += 1;
		}
	}
}
void SCH_ADD_TASK(void (*pTask)(void), uint32_t Delay, uint32_t Period) {
	// ------------------------------------------------
	// Readme:
	// - Add new Task to scheduler
	// ------------------------------------------------
	if (index_val < SCH_MAX_TASKS)
		SCH_TASKS_G[index_val].pTask = pTask;
	SCH_TASKS_G[index_val].Delay = Delay / 10;
	SCH_TASKS_G[index_val].Period = Period / 10;
	SCH_TASKS_G[index_val].RunMe = 0;
	SCH_TASKS_G[index_val].TaskID = index_val;
	index_val++;
}
void SCH_DISPATCH_TASK(void) {
	// ------------------------------------------------
	// Readme:
	// - Scheduler dispatch = TimerRun
	// ------------------------------------------------
	for (int i = 0; i < index_val; i++) {
		if (SCH_TASKS_G[i].RunMe > 0) {
			(*SCH_TASKS_G[i].pTask)();
			SCH_TASKS_G[i].RunMe -= 1;
		}
	}
}
//void SCH_DELETE_TASK(index_val){
	// ------------------------------------------------
	// Readme:
	// - Scheduler delete
	// ------------------------------------------------
//SCH_TASKS_G[index_val].pTask = 0x0000;
//SCH_TASKS_G[index_val].Delay = 0;
//SCH_TASKS_G[index_val].Period = 0;
//SCH_TASKS_G[index_val].RunMe = 0;
//}
