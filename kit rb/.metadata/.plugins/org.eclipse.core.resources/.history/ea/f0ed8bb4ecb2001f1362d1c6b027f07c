/*
 * input_processing.c
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */
#include"input_processing.h"
void fsm_for_input_processing(void) {
	getKeyInput();
	switch (state) {
	case IDLE:
		mode_light();
		if (button_flag[0] == 1) {
			button_flag[0]=0;
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			state = AUTO;
		}
		if (button_flag[1] == 1) {
			button_flag[1]=0;
			state = NIGHT;
		}
		if (button_flag[2] == 1) {
			button_flag[2]=0;
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			state = ADJUST;
		}
		if (button_flag[3] == 1) {
			button_flag[3]=0;
			state = MANUAL;
		}
		break;

	case AUTO:
	if (button_flag[0] == 1) {
		button_flag[0]=0;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
		state = IDLE;
	}
	break;
	case NIGHT:
	if (button_flag[0] == 1) {
		button_flag[0]=0;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
		state = IDLE;

	}
	break;
	case ADJUST:
	if (button_flag[0] == 1) {
		button_flag[0]=0;
		if (valid){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			state = IDLE;
		}
	}
	if (button_flag[1] == 1) {
		button_flag[1]=0;
		adj_state = ADJ_MODE;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	}
	if (button_flag[2] == 1) {
		button_flag[2]=0;
		adj_state = INCREASE_TIME;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	}
	if (button_flag[3] == 1) {
		button_flag[3]=0;
		adj_state = DECREASE_TIME;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	}

	break;
	case MANUAL:
	if (button_flag[0] == 1) {
		button_flag[0]=0;
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
		state = IDLE;
	}
	break;
}
}
