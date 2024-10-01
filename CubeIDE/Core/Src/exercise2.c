/*
 * exercise2.c
 *
 *  Created on: Oct 1, 2024
 *      Author: tuank
 */

#include "exercise2.h"

char seg[10] =
{
		0x40,
		0x79,
		0x24,
		0x30,
		0x19,
		0x12,
		0x02,
		0x78,
		0x00,
		0x10
};

void clearAll()
{
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, SET);
}

void enablePin(int index)
{
	if (index == 0)
		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
	if (index == 1)
		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
	if (index == 2)
		HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
	if (index == 3)
		HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);

}

void displayNumber(int number)
{
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin, (seg[number] & 0x01) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, SEG1_Pin, (seg[number] & 0x02) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, SEG2_Pin, (seg[number] & 0x04) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, SEG3_Pin, (seg[number] & 0x08) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, SEG4_Pin, (seg[number] & 0x10) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, SEG5_Pin, (seg[number] & 0x20) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, SEG6_Pin, (seg[number] & 0x40) ? SET : RESET);
}






