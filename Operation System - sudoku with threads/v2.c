/*
 * v2.c
 *
 *  Created on: May 19, 2019
 *      Author: yevgeni
 */


#include "hw2.h"
#include "function.h"

int main(int argc, char **argv) {

	int** sudoku;
	if (argc == 1)
		sudoku = createMatrix();

	else {

		sudoku = read_From_File(argv[1]);
	}


	threads_with_mutex(sudoku);

	return 1;
}
