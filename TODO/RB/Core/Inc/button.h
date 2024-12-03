#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0
#define NUM_BUT 4
extern int button_flag[NUM_BUT];

void getKeyInput();
