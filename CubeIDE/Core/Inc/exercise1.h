/*
 * exercise1.h
 *
 *  Created on: Oct 1, 2024
 *      Author: tuank
 */

#ifndef INC_EXERCISE1_H_
#define INC_EXERCISE1_H_

#include "main.h"

#define TICK 10
#define LED1 1
#define LED2 2
extern int timer_flag[10];


void setTimer(int index, int duration);
void timerRun();
void clearAll();
void enablePin(int index);
void displayNumber(int number);

#endif /* INC_EXERCISE1_H_ */
