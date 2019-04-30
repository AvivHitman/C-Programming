/*
 * func1.c
 *
 *  Created on: Nov 16, 2018
 *      Author: aviv
 */
#include "func1.h"
#include <stdlib.h>
#include <time.h>

//menu for game number 1
void menu(int* mat, int size, int col, int row) {
	int option;
	do {
		printf("Please choose one of the following options \n"
				" 1- 90 degree clockwise \n"
				" 2-90 degree clockwise\n"
				" 3- Flip horizontal\n "
				" 4-flip vertical \n "
				"-1- exit\n");

		scanf("%d", &option);

		switch (option) {
		case 1:
			ClockWise(mat, size);
			printMat(mat, col, row);
			break;
		case 2:
			CounterClockWise(mat, size);
			printMat(mat, col, row);
			break;
		case 3:
			flipHortizontal(mat, size);
			printMat(mat, col, row);
			break;
		case 4:
			flipVertical(mat, size);
			printMat(mat, col, row);
			break;
		default:
			break;
		}
	} while (option != -1);

}
//create matrix with random numbers
void initRandomMat(int* mat, int col, int row) {
	srand(time(NULL));
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			*mat = rand() % 6;
			mat++;
		}
	}
}

void printMat(int* mat, int col, int row) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%5d", *mat);
			mat++;
		}
		printf("\n");
	}
}

void ClockWise(int* mat, int size) {
	int i, j, temp, *ptemp;

	for (i = 0; i < size / 2; i++) {
		for (j = i; j < size - i - 1; j++) {

			temp = *(mat + i * size + j);

			ptemp = mat + i * size + j;
			*ptemp = *(mat + (size - 1 - j) * size + i);

			ptemp = mat + (size - 1 - j) * size + i;
			*ptemp = *(mat + (size - 1 - i) * size + size - 1 - j);

			ptemp = mat + (size - 1 - i) * size + size - 1 - j;
			*ptemp = *(mat + j * size + size - 1 - i);

			ptemp = mat + j * size + size - 1 - i;
			*ptemp = temp;
		}

	}

}

void CounterClockWise(int* mat, int size) {
	int i, j, temp, *ptemp;

	for (i = 0; i < size / 2; i++) {
		for (j = i; j < size - i - 1; j++) {

			temp = *(mat + i * size + j);

			ptemp = mat + i * size + j;
			*ptemp = *(mat + j * size + size - 1 - i);

			ptemp = mat + j * size + size - 1 - i;
			*ptemp = *(mat + (size - 1 - i) * size + size - 1 - j);

			ptemp = mat + (size - 1 - i) * size + size - 1 - j;
			*ptemp = *(mat + (size - 1 - j) * size + i);

			ptemp = mat + (size - 1 - j) * size;
			*ptemp = temp;
		}

	}

}

void flipHortizontal(int* mat, int size) {
	int i, j, temp, *ptemp;

	for (i = 0; i < size / 2; i++) {
		for (j = 0; j < size; j++) {

			temp = *(mat + i * size + j);

			ptemp = mat + i * size + j;
			*ptemp = *(mat + (size - 1 - i) * size + j);

			ptemp = mat + (size - 1 - i) * size + j;
			*ptemp = temp;

		}

	}

}

void flipVertical(int* mat, int size) {
	int i, j, temp, *ptemp;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size / 2; j++) {

			temp = *(mat + i * size + j);

			ptemp = mat + i * size + j;
			*ptemp = *(mat + i * size + size - 1 - j);

			ptemp = mat + i * size + size - 1 - j;
			*ptemp = temp;

		}

	}

}
