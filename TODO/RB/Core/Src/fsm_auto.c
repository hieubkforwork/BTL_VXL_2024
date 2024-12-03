/*
 * fsm_auto.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#include "fsm_auto.h"

void fsm_auto(){
	if(modeh == AUTO){
	switch(status){
	case INIT:
		status = RED_GREEN;
		break;
	case RED_GREEN:
		//led_red_green();
		on_green1_led();
		on_red2_led();
		//display_seg(green_time-auto_timer+10, green_time+amber_time-auto_timer+10 );

		if(auto_timer >= green_time){
		 status = RED_AMBER;
		 auto_timer=0;
		}
		break;
	case RED_AMBER:
		//led_red_amber();
		on_yellow1_led();
		on_red2_led();
		//display_seg(amber_time - auto_timer+10, amber_time-auto_timer+10);

		if(auto_timer >= amber_time){
		 status = GREEN_RED;
		 auto_timer=0;
		}
		break;
	case GREEN_RED:
		//led_green_red();
		on_green2_led();
		on_red1_led();
		//display_seg(green_time+amber_time-auto_timer+10, green_time-auto_timer+10);

		if(auto_timer >= green_time){
		status = AMBER_RED;
		auto_timer=0;
		}
		break;
	case AMBER_RED:
		//led_amber_red();
		on_yellow2_led();
		on_red1_led();
		//display_seg(amber_time-auto_timer+10, amber_time-auto_timer+10);

		if(auto_timer >= amber_time){
		status = RED_GREEN;
		auto_timer=0;
		}
		break;
	}
	auto_timer+=1;
	}
}


