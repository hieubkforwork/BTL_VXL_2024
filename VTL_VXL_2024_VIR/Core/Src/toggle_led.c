/*
 * toggle_led.c
 *
 *  Created on: Nov 24, 2024
 *      Author: ACER
 */
#include "toggle_led.h"
void toggle_led(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
