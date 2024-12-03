/*
 * global.c
 *
 *  Created on: Dec 3, 2024
 *      Author: ACER
 */


#include "global.h"


int state=IDLE;
int auto_state=INIT;

int auto_timer = 0, led_catch_timer=0;
int red_time=12, amber_time = 4, green_time = 8;
int valid = 1;
