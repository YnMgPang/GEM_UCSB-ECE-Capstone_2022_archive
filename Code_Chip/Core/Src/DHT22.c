/*
 * DHT22.c
 *
 *  Created on: Apr 7, 2022
 *      Author: Michael
 */

#include "delay.h"

void setOut(GPIO_TypeDef* GPIOx) { //set gpio output mode
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void setIn(GPIO_TypeDef* GPIOx) { //set gpio input mode
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

#define PC GPIOC

void sensorInit() {
	setOut(PC); //set output mode
	HAL_GPIO_WritePin(PC, GPIO_PIN_1, 1);
	//HAL_Delay(200);
	HAL_Delay(200); //wait two seconds before doing anything. just keep the pin high
	HAL_GPIO_WritePin(PC, GPIO_PIN_1, 0);
	HAL_Delay(5);
	//delay(5000); //5ms. wait 5 miliseconds
	HAL_GPIO_WritePin(PC, GPIO_PIN_1, 1);
	delay(20); //wait 20 microseconds
	setIn(PC); //set input to read the sensor response in next function
}

uint8_t sensorVerify() {
	//setIn(PA);
	uint8_t r = 0;
	delay(40);
	if(HAL_GPIO_ReadPin(PC, GPIO_PIN_1) == GPIO_PIN_RESET) {  //if the pin is low
		delay(80);
		if((HAL_GPIO_ReadPin(PC, GPIO_PIN_1))) { //if the pin is high
			r = 1;
		} else {
			r = -1;
		}
	}
	while((HAL_GPIO_ReadPin(PC, GPIO_PIN_1)));
	//sensor does not send back response?
	//r = 0 indicates that the pin is always high and never pulls down.
	return r;
}

uint8_t sensorRead() {
	uint8_t i, j;
	for(j = 0; j < 8; j++) {
		while(!(HAL_GPIO_ReadPin(PC, GPIO_PIN_1)));
		delay(40);
		if(!(HAL_GPIO_ReadPin(PC, GPIO_PIN_1))) {
			i &= ~(1<<(7-j));
		} else {
			i |= (1<<(7-j));
		}
		while((HAL_GPIO_ReadPin(PC, GPIO_PIN_1)));
	}
	return i;
}
