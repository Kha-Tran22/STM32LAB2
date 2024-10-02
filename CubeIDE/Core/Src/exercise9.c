/*
 * exercise9.c
 *
 *  Created on: Oct 1, 2024
 *      Author: tuank
 */

#include "exercise9.h"

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


const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1, 2, 3, 4};
void update7SEG(int index)
{
	clearAll();
	switch (index)
	{
		case 0:
			enablePin(0);
			displayNumber(led_buffer[0]);
			break;

		case 1:
			enablePin(1);
			displayNumber(led_buffer[1]);
			break;

		case 2:
			enablePin(2);
			displayNumber(led_buffer[2]);
			break;

		case 3:
			enablePin(3);
			displayNumber(led_buffer[3]);
			break;

		default:
			break;

	}
}

void updateClockBuffer()
{
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}


const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;



uint8_t matrix_buffer[8] =
{
	0x3C, 0x7E, 0xC3, 0xC3, 0xFF, 0xC3, 0xC3, 0xC3
};

void displayCol(int index)
{
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, (matrix_buffer[index] & 0x01) ? RESET : SET);
	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, (matrix_buffer[index] & 0x02) ? RESET : SET);
	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, (matrix_buffer[index] & 0x04) ? RESET : SET);
	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, (matrix_buffer[index] & 0x08) ? RESET : SET);
	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, (matrix_buffer[index] & 0x10) ? RESET : SET);
	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, (matrix_buffer[index] & 0x20) ? RESET : SET);
	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, (matrix_buffer[index] & 0x40) ? RESET : SET);
	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, (matrix_buffer[index] & 0x80) ? RESET : SET);
}

void clearMatrix(){
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin , SET);
}

void updateLEDMatrix(int index)
{
	clearMatrix();
	switch (index)
	{
		case 0:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW0_Pin, RESET);
			break;
		case 1:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW1_Pin, RESET);
			break;
		case 2:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW2_Pin, RESET);
			break;
		case 3:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW3_Pin, RESET);
			break;
		case 4:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW4_Pin, RESET);
			break;
		case 5:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW5_Pin, RESET);
			break;
		case 6:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW6_Pin, RESET);
			break;
		case 7:
			displayCol(index);
			HAL_GPIO_WritePin(GPIOB, ROW7_Pin, RESET);
			break;
		default:
			break;
	}
}


