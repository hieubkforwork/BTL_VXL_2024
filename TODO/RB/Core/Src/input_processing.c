/*
 * input_processing.c
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */

void fsm_for_input_processing(void) {
	getKeyInput();

	switch (state) {
	case IDLE:
		if (button_flag[0] == 1) {
			button_flag[0];
			state = MODE;
		}
		break;
	case MODE:
		if (button_flag[0] == 1) {
			button_flag[0];
			state = AUTO;
		}
		if (button_flag[1] == 1) {
			button_flag[1];
			state = NIGHT;
		}
		if (button_flag[2] == 1) {
			button_flag[2];
			state = ADJUST;
		}
		if (button_flag[3] == 1) {
			button_flag[3];
			state = MANUAL;
		}
		break;

	}
	case AUTO:
	if (button_flag[0] == 1) {
		button_flag[0];
		state = IDLE;
	}
	break;
	case NIGHT:
	if (button_flag[0] == 1) {
		button_flag[0];
		state = IDLE;

	}
	break;
	case ADJUST:
	if (button_flag[0] == 1) {
		button_flag[0];
		if (valid)
			state = IDLE;

	}
	if (button_flag[1] == 1) {
		button_flag[1];
		adj_state = ADJ_MODE;
	}
	if (button_flag[2] == 1) {
		button_flag[2];
		adj_state = INCREASE_TIME;
	}
	if (button_flag[3] == 1) {
		button_flag[3];
		adj_state = DECREASE_TIME;
	}

	break;
	case MANUAL:
	if (button_flag[0] == 1) {
		button_flag[0];
		state = IDLE;
	}
	break;

}
