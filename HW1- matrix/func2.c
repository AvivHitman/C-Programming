/*
 * func2.c
 *
 *  Created on: Nov 17, 2018
 *      Author: aviv
 */

#include "func2.h"
#include <stdlib.h>
#include <time.h>

//create matrix
void initMat(int* mat, int col, int row) {
	int i;
	int num = 0;
	*(mat + row * col - 1) = 0;
	for (i = 0; i < row * col; i++) {
		*(mat + i -1) = num;
			num++;
		}

}

void shuffel_count(int* mat, int col, int row) {
	srand(time(NULL));
	int swapCol = rand() % col;
	int swapRow = rand() % row;

	int swapCol2 = rand() % col;
	int swapRow2 = rand() % row;

	int temp, *ptemp;

	temp = *(mat + swapRow * col + swapCol);

	ptemp = mat + swapRow * col + swapCol;
	*ptemp = *(mat + swapRow2 * col + swapCol2);

	ptemp = mat + swapRow2 * col + swapCol2;
	*ptemp = temp;

}

//check ascending order
int check(int* mat, int col, int row) {
	int i;
	if (*(mat + row * col - 1) != 0)
		return -1;

	for (i = 0; i < row * col - 2; i++) {

		if (*(mat + i) > *(mat + i + 1)) {
			return -1;
		}
	}
	return 0;
}
// check where is zero number
int search(int* mat, int col, int row, int num) {
	int i, j, place;
	place = -1;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (*mat == num)
				place = col * i + j + 1;
			mat++;
		}
	}
	return place;
}
 //check if the chosen number is next to zero
int checkNearZero(int* mat, int col, int row, int place) {

	if (*(mat + place) == 0)
		return place + 1;

	else if (*(mat + place - 2) == 0) {

		return place - 1;

	}

	else if (*(mat + place - col - 1) == 0)
		return place - col;

	else if (*(mat + place + col - 1) == 0)
		return place + col;

	else
		return -1;

}
// swap between the chosen number and zero
void swap(int* mat, int col, int row, int place, int placeZero) {

	int temp, *ptemp;

	temp = *(mat + place - 1);

	ptemp = mat + place - 1;
	*ptemp = *(mat + placeZero - 1);

	ptemp = mat + placeZero - 1;
	*ptemp = temp;

}
// menu for game number 2
void menu2() {
	int mat[ROW * COL];
	initMat(mat, COL, ROW); //create mat
	shuffel_count(mat, COL, ROW);
	printMat(mat, COL, ROW);

	int num;
	int validAns;
	int check1 = check(mat, COL, ROW);

	do {
		do {
			printf("your step:\n");
			scanf("%d", &num);
			int place = search(mat, COL, ROW, num);
			int ans = checkNearZero(mat, COL, ROW, place);
			if (ans == -1) {
				printf("\ninvalid!!\n");
				validAns = -1;
			}

			else {
				printf("\nswap!!!\n");
				swap(mat, COL, ROW, place, ans);
				validAns = 1;
			}

		} while (validAns == -1);

		printMat(mat, COL, ROW);

	} while (check1 == -1);
	printf("you won!!!");

}

