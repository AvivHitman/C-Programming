/*
 * function.h
 *
 *  Created on: Apr 27, 2019
 *      Author: yevgeni
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_


int result[27] ;

typedef struct {

	int row;
	int col;
	int** board;

} infro_without_mutex;

typedef struct {

	int row;
	int col;
	int** board;
	char ch;

} infro_with_mutex;


void *check_cols(void *params);
void *check_rows(void *params);
void *check_grid(void * params);
void check_result() ;
int check_grid_m(int startRow , int startCol , int** sudoku);
int check_rows_m(int row , int** sudoku);
int check_cols_m(int col , int** sudoku);
int** createMatrix();

#endif /* FUNCTION_H_ */
