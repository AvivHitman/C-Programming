/*
 * exe1.c
 *
 *  Created on: Nov 15, 2018
 *      Author: aviv
 */

#include <stdio.h>
#include <ctype.h>
#include "exe1.h"
#include "func1.h"
#include "func2.h"


//
void MainMenu() {
	char ch;
	do {
		printf("Please choose one of the following options \n"
				" P/p- picture manipulation \n"
				" N/n-number game \n"
				" E/e- Exit\n");

		scanf("%c", &ch);
		ch = tolower(ch);
		srand(time(NULL));
		int num = rand() % 6 + 2;
		int mat[num * num];

		switch (ch) {
		case 'p':
			initRandomMat(mat, num, num);
			printMat(mat, num, num);
			menu(mat, num, num, num);
			break;

		case 'n':
			menu2();
			break;
		case 'e':
			printf("bye bye");
			break;
		default:
			break;
		}
	} while (ch != 'e');

}
