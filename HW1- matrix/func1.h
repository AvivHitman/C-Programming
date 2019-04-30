/*
 * func1.h
 *
 *  Created on: Nov 16, 2018
 *      Author: aviv
 */

#ifndef FUNC1_H_
#define FUNC1_H_

void initRandomMat(int* mat , int col, int row);
void printMat(int* mat , int col, int row);
void ClockWise(int* mat, int size);
void CounterClockWise (int* mat, int size);
void flipVertical(int* mat, int size);
void flipHortizontal(int* mat, int size);
void menu(int* mat , int size , int col, int row);

#endif /* FUNC1_H_ */
