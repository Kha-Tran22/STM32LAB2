/*
 * exercise8.h
 *
 *  Created on: Oct 1, 2024
 *      Author: tuank
 */

#ifndef INC_EXERCISE8_H_
#define INC_EXERCISE8_H_

#include "main.h"

int hour, minute, second;

void clearAll();
void enablePin(int index);
void displayNumber(int number);
void update7SEG(int index);
void updateClockBuffer();

#endif /* INC_EXERCISE8_H_ */
