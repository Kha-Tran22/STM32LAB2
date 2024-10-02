/*
 * exercise6.c
 *
 *  Created on: Oct 1, 2024
 *      Author: tuank
 */

#include "exercise6.h"


void clearAll()
{
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, DOT_Pin, SET);
}





