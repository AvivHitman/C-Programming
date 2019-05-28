/*
 * hw2.c
 *
 *  Created on: Apr 27, 2019
 *      Author: yevgeni
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "function.h"
#include "hw2.h"

#define SIZE 9

int sudoku[9][9];
int done = 0;
int global = 1;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

infro_with_mutex** task;

int** read_From_File(char* argv) {

	FILE* file = fopen(argv, "r");
	if (!file) {
		printf("Fail");

	}

	int** sudoku = (int**) malloc(SIZE * sizeof(int*));
	int i, j, num;
	for (i = 0; i < SIZE; i++) {
		sudoku[i] = (int*) malloc(SIZE * sizeof(int));
		for (j = 0; j < SIZE; j++) {
			fscanf(file, "%d", &num);
			sudoku[i][j] = num;
		}

	}
	fclose(file);

	return sudoku;
}

void threads_without_mutex(int** sudoku) {

	pthread_t threads[NUM_OF_MISSION];
	int threadIndex = 0;
	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (i % 3 == 0 && j % 3 == 0) {
				infro_without_mutex *grid = (infro_without_mutex *) malloc(
						sizeof(infro_without_mutex));
				grid->row = i;
				grid->col = j;
				grid->board = sudoku;
				pthread_create(&threads[threadIndex++], NULL, check_grid, grid);
			}

			if (j == 0) {
				infro_without_mutex *row = (infro_without_mutex *) malloc(
						sizeof(infro_without_mutex));
				row->row = i;
				row->col = j;
				row->board = sudoku;
				pthread_create(&threads[threadIndex++], NULL, check_rows, row);
			}
			if (i == 0) {
				infro_without_mutex *colum = (infro_without_mutex *) malloc(
						sizeof(infro_without_mutex));
				colum->row = i;
				colum->col = j;
				colum->board = sudoku;
				pthread_create(&threads[threadIndex++], NULL, check_cols,
						colum);
			}
		}
	}

	for (int i = 0; i < NUM_OF_MISSION; i++) {
		pthread_join(threads[i], NULL);
	}

	check_result();
}

void threads_with_mutex(int** sudoku) {
	pthread_t tr[N];
	int i;

	create_list_Tasks(sudoku);
	count = 0;

	for (i = 0; i < N; i++) {
		pthread_create(&tr[i], NULL, get_task_from_list, NULL);
	}

	pthread_mutex_lock(&lock1);

	while (done != N) {
		pthread_cond_wait(&cond, &lock1);
	}

	pthread_mutex_unlock(&lock1);

	if (global == 1) {
		printf("solution is legal\n");
	} else {
		printf("solution is not legal\n");
	}

	for (i = 0; i < N; i++) {
		pthread_join(tr[i], NULL);
	}

	pthread_mutex_destroy(&lock);
	pthread_mutex_destroy(&lock1);
	pthread_cond_destroy(&cond);
}

void create_list_Tasks(int** sudoku) {
	task = (infro_with_mutex**) malloc(
	NUM_OF_MISSION * sizeof(infro_with_mutex*));
	int i, j;
	int count = 0;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {

			if (i % 3 == 0 && j % 3 == 0) {

				task[count] = (infro_with_mutex*) malloc(
						sizeof(infro_with_mutex));
				task[count]->ch = 'g';
				task[count]->row = i;
				task[count]->col = j;
				task[count]->board = sudoku;

				count++;

			}

			if (j == 0) {
				task[count] = (infro_with_mutex*) malloc(
						sizeof(infro_with_mutex));
				task[count]->ch = 'r';
				task[count]->row = i;
				task[count]->col = j;
				task[count]->board = sudoku;

				count++;

			}

			if (i == 0) {
				task[count] = (infro_with_mutex*) malloc(
						sizeof(infro_with_mutex));
				task[count]->ch = 'c';
				task[count]->row = i;
				task[count]->col = j;
				task[count]->board = sudoku;

				count++;

			}

		}
	}
}

void* get_task_from_list(void* ar) {
	infro_with_mutex toDo;

	while (count != (NUM_OF_MISSION - 1)) {
		pthread_mutex_lock(&lock);

		toDo = *(task[count]);
		count++;

		doTask(&toDo);

		if (result_thread == ERROR) {
			count = NUM_OF_MISSION-1;
			global = 0;
		}
		pthread_mutex_unlock(&lock);

	}
	pthread_mutex_lock(&lock2);
	done++;
	pthread_mutex_unlock(&lock2);

	if (done == N) {
		pthread_cond_signal(&cond);
	}

	pthread_exit(NULL);
}

void doTask(infro_with_mutex* parameter) {

	switch (parameter->ch) {
	case 'r':
		result_thread = check_rows_m(parameter->row, parameter->board);
		break;
	case 'c':
		result_thread = check_cols_m(parameter->col, parameter->board);
		break;
	case 'g':
		result_thread = check_grid_m(parameter->row, parameter->col,
				parameter->board);
	}
}

