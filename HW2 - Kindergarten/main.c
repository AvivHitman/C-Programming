#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"

int main() {

	printf("Enter 1 for binary file 0 for test file\n ");


	int opt;
	scanf("%d", &opt);

	City utz = { NULL, 0 };
	int uReq;

	//first time read
	readCity(&utz, opt);
	do {
		uReq = menu();
		switch (uReq) {
		case READ_CITY:
			readCity(&utz, opt);
			break;

		case SHOW_CITY:
			showCityGardens(&utz);
			break;

		case SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case WRITE_CITY:
			saveCity(&utz , opt);
			break;

		case ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",
					countChova(&utz));
			break;

		case SORT1:
			sortByGardenName(&utz);
			break;

		case SORT2:
			sortByChildId(&utz);
			break;

		case SORT3:
			sortByGardenType(&utz);
			break;

		case LINKED_LIST:
			LinkedList(&utz);
			break;
		}

	} while (uReq != EXIT);

	releaseCity(&utz); //free all allocations

	return EXIT_SUCCESS;
}

