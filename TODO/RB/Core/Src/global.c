/*
 * global.c
 *
 *  Created on: Dec 3, 2024
 *      Author: ACER
 */


#include "global.h"

int status = INIT;
int modeh = AUTO;
int auto_timer = 0,man_timer=0,error_timer=0;
int red_time=12, amber_time = 4, green_time = 8;
int temp_red,temp_amber,temp_green;
int first_time=1;
