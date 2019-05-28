/*
 * function.c
 *
 *  Created on: Apr 27, 2019
 *      Author: yevgeni
 */

#include "function.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *check_cols(void *params) {
	infro_without_mutex *data = (infro_without_mutex *) params;

	int validarray[10] = { 0 };
	for (int i = 0; i < 9; i++) {
		int val = data->board[i][data->col];
		if (validarray[val] != 0)
			pthread_exit(NULL);
		else
			validarray[val] = 1;
	}

	result[18 + data->col] = 1;
	pthread_exit(NULL);
}

void *check_rows(void *params) {
	infro_without_mutex *data = (infro_without_mutex *) params;

	int validarray[10] = { 0 };
	for (int j = 0; j < 9; j++) {
		int val = data->board[data->row][j];
		if (validarray[val] != 0)
			pthread_exit(NULL);
		else
			validarray[val] = 1;
	}

	result[9 + data->row] = 1;
	pthread_exit(NULL);
}

void *check_grid(void * params) {
	infro_without_mutex *data = (infro_without_mutex *) params;

	int validarray[10] = { 0 };
	for (int i = data->row; i < data->row + 3; ++i) {
		for (int j = data->col; j < data->col + 3; ++j) {
			int val = data->board[i][j];
			if (validarray[val] != 0)
				pthread_exit(NULL);
			else
				validarray[val] = 1;
		}
	}

	result[data->row + data->col / 3] = 1;
	pthread_exit(NULL);
}

void check_result() {
	int flag = 0;
	for (int i = 0; i < 27; i++) {
		if (result[i] == 0) {
			printf("solution is not legal\n");
			flag = 1;
			break;
		}
	}
	if (flag != 1)
		printf("solution is legal\n");
}

int check_grid_m(int startRow, int startCol, int** sudoku) {

	int validarray[10] = { 0 };
	for (int i = startRow; i < startRow + 3; ++i) {
		for (int j = startCol; j < startCol + 3; ++j) {
			int val = sudoku[i][j];
			if (validarray[val] != 0)
				return 1;
			else
				validarray[val] = 1;
		}
	}
	return 0;
}

int check_rows_m(int row, int** sudoku) {

	int validarray[10] = { 0 };
	for (int j = 0; j < 9; j++) {
		int val = sudoku[row][j];
		if (validarray[val] != 0)
			return 1;
		else
			validarray[val] = 1;
	}

	return 0;
}

int check_cols_m(int col, int** sudoku) {

	int validarray[10] = { 0 };
	for (int i = 0; i < 9; i++) {
		int val = sudoku[i][col];
		if (validarray[val] != 0)
			return 1;
		else
			validarray[val] = 1;
	}

	return 0;
}
int** createMatrix() {
	int** temp = (int**) malloc(sizeof(int*) * 9);
	int i, j;

	for (i = 0; i < 9; i++) {
		temp[i] = (int*) malloc(sizeof(int) * 9);
	}

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &temp[i][j]);
		}
	}

	return temp;
}
