/*
 * hw2.h
 *
 *  Created on: Apr 27, 2019
 *      Author: yevgeni
 */

#ifndef HW2_H_
#define HW2_H_
#include "function.h"

#define NUM_OF_MISSION 27
#define ERROR 1
#define N 5

int result_thread;
int count ;


int** read_From_File(char* argv);
void threads_without_mutex(int** sudoku);
void threads_with_mutex(int** sudoku);
void create_list_Tasks(int** sudoku);
void* get_task_from_list(void* ar);
void doTask(infro_with_mutex* parameter);

#endif /* HW2_H_ */
