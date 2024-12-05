/*
 * fsm_adjust.c
 *
 *  Created on: Dec 3, 2024
 *      Author: ACER
 */

#include "fsm_adjust.h"

void error_led() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
}
void no_error_led() {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
}
void fsm_adjust() {
	if (state == ADJUST) {

		switch (adj_state) {
		case ADJ_INIT:
			if (red_time != green_time + amber_time) {
				error_led();
				valid = 0;
			} else {
				no_error_led();
				valid = 1;
			}
			break;
		case ADJ_MODE:
			switch (__mode) {
			case MODE_RED:
				on_red1_led();
				on_red2_led();
				__mode = MODE_GREEN;
				break;
			case MODE_GREEN:
				on_green1_led();
				on_green2_led();
				__mode = MODE_AMBER;
				break;
			case MODE_AMBER:
				on_yellow1_led();
				on_yellow2_led();
				__mode = MODE_RED;
				break;
			}
			adj_state = ADJ_INIT;
			break;
		case INCREASE_TIME:
			if (__mode == MODE_RED) {
				red_time++;
			} else if (__mode == MODE_GREEN) {
				green_time++;
			} else if (__mode == MODE_AMBER) {
				amber_time++;
			}
			adj_state = ADJ_INIT;
			break;
		case DECREASE_TIME:
			if (__mode == MODE_RED)
				red_time--;
			else if (__mode == MODE_GREEN)
				green_time--;
			else if (__mode == MODE_AMBER)
				amber_time--;
			adj_state = ADJ_INIT;
			break;
		}

	}
}
