/*
 * func2.h
 *
 *  Created on: Nov 17, 2018
 *      Author: aviv
 */

#ifndef FUNC2_H_
#define FUNC2_H_

#define ROW 4
#define COL 3

void initMat(int* mat, int col, int row);
void shuffel_count(int* mat, int col, int row);
int check(int* mat, int col, int row);
int search(int* mat, int col, int row, int num);
void swap(int* mat, int col, int row, int place, int placeZero);
int checkNearZero(int* mat, int col, int row, int place);
void menu2();
#endif /* FUNC2_H_ */
