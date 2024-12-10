/*
 * fsm_auto.c
 *
 *  Created on: Nov 15, 2024
 *      Author: ACER
 */

#include "fsm_auto.h"

void fsm_auto(){
	if(state == AUTO){

	switch(auto_state){
	case INIT:
		auto_state = RED_GREEN;
		break;
	case RED_GREEN:
		on_green1_led();
		on_red2_led();

		if(auto_timer >= green_time){
		 auto_state = RED_AMBER;
		 auto_timer=0;
		}
		break;
	case RED_AMBER:
		on_yellow1_led();
		on_red2_led();

		if(auto_timer >= amber_time){
			auto_state = GREEN_RED;
		 auto_timer=0;
		}
		break;
	case GREEN_RED:
		on_green2_led();
		on_red1_led();

		if(auto_timer >= green_time){
			auto_state = AMBER_RED;
		auto_timer=0;
		}
		break;
	case AMBER_RED:
		on_yellow2_led();
		on_red1_led();

		if(auto_timer >= amber_time){
			auto_state = RED_GREEN;
		auto_timer=0;
		}
		break;
	}
	auto_timer+=1;
	}

}


