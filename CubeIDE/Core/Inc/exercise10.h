/*
 * exercise9.h
 *
 *  Created on: Oct 1, 2024
 *      Author: tuank
 */

#ifndef INC_EXERCISE10_H_
#define INC_EXERCISE10_H_

#include "main.h"

int hour, minute, second;

void clearAll();
void enablePin(int index);
void displayNumber(int number);
void update7SEG(int index);
void updateClockBuffer();

void displayCol(int index);
void clearMatrix();
void updateLEDMatrix(int index);

#endif /* INC_EXERCISE10_H_ */
