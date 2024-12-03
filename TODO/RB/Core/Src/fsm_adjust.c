/*
 * fsm_adjust.c
 *
 *  Created on: Dec 3, 2024
 *      Author: ACER
 */

#include "fsm_adjust.h"

int __mode = MODE_RED;
void fsm_adjust(){
	if(state==ADJUST){
	switch(man_state){
	case ADJ_MODE:
		switch(__mode){
		case MODE_RED:
			__mode = MODE_GREEN;
			break;
		case MODE_GREEN:
			__mode = MODE_AMBER;
			break;
		case MODE_AMBER:
			__mode = MODE_RED;
			break;
		}
		break;
	case INCREASE_TIME:
		if(__mode==MODE_RED) red_time++;
		else if(__mode==MODE_GREEN) green_time++;
		else if(__mode==MODE_AMBER) amber_time++;
		break;
	case DECREASE_TIME:
		if(__mode==MODE_RED) red_time--;
		else if(__mode==MODE_GREEN) green_time--;
		else if(__mode==MODE_AMBER) amber_time--;
		break;
	}
	if(red_time != green_time+amber_time) {
		error_led(); // chưa làm
		valid=0;
	}
	else {
		no_error_led(); // chưa làm
		valid=1;
	}
	}
}
