/*
 * input_processing.c
 *
 *  Created on: Sep 30, 2024
 *      Author: User
 */


void fsm_for_input_processing(void) {
    getKeyInput();

    if (button_flag[0]) {
        button_flag[0] = 0;

    }

    if (button_flag[1]) {
        button_flag[1] = 0;

    }

    if (button_flag[2]) {
    	button_flag[2] = 0;
    }

    if (button4_flag[3]) {
    	button_flag[3] = 0;
    }

    //update_handlemode();
}
