/*
 * DS18B20.c
 *
 *  Created on: Apr 7, 2022
 *      Author: Michael
 */

#include "delay.h"
#define PC GPIOC

void setOutDS(GPIO_TypeDef* GPIOx) { //set gpio output mode
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void setInDS(GPIO_TypeDef* GPIOx) { //set gpio input mode
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

uint8_t dsInit() {
	uint8_t r = 0;
	setOutDS(PC);
	HAL_GPIO_WritePin(PC, GPIO_PIN_2, 0);
	delay(50);
	//delay(480);
	setInDS(PC);
	delay(50);
	//delay(80);
	if(!(HAL_GPIO_ReadPin(PC, GPIO_PIN_2))) {
		r = 1;
	} else {
		r = -1;
	}
	delay(50);
	//delay(400);
	return r;
}

void dsWrite(uint8_t data) {
	setOutDS(PC);
	for(int i = 0; i < 8; i++) {
		if((data & (1 << i)) != 0) {
			setOutDS(PC);
			HAL_GPIO_WritePin(PC, GPIO_PIN_2, 0);
			delay(1);
			setInDS(PC);
			delay(50);
		} else {
			setOutDS(PC);
			HAL_GPIO_WritePin(PC, GPIO_PIN_2, 0);
			delay(50);
			setInDS(PC);
		}
	}
}

uint8_t dsRead() {
	uint8_t v = 0;
	setInDS(PC);
	for(int i = 0; i < 8; i++) {
		setOutDS(PC);
		HAL_GPIO_WritePin(PC, GPIO_PIN_2, 0);
		delay(2);
		setInDS(PC);
		if(HAL_GPIO_ReadPin(PC, GPIO_PIN_2)) {
			v |= 1 << i;
		}
		delay(60);
	}
	return v;
}
