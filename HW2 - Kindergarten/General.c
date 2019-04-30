#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "General.h"

const char* optionStr[NofOptions] = { "Exit", "Read City information from file",
		"Show all Kindergartens", "Show a specific Kindergarten",
		"Save City information to file", "Add a Kindergarten", "Add a Child",
		"Birthday to a Child", "Count Hova childres", "Sort garden by name",
		"sort by id", "sort by garden type", "kindergartensLinkedList" };

/**************************************************/
int menu()
/**************************************************/
/**************************************************/
{
	int option, i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for (i = 0; i < NofOptions; i++)
		printf("\n\t%d. %s.", i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr) {
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*) malloc(len * sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p) {
	if (!p) {
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

// Function GenInsertSort
void GenInsertSort(void *arr, int size, int typeSize,
		int (*compare)(void*, void*)) {
	char *temp = (char*) malloc(typeSize);
	char *i, *j;
	for (i = (char*) arr + typeSize; i < (char*) arr + size * typeSize; i +=
			typeSize) {
		memcpy(temp, i, typeSize);
		for (j = i - typeSize; j >= (char*) arr && compare(j, temp) > 0; j -=
				typeSize) {
			memmove(j + typeSize, j, typeSize);
		}

		memcpy(j + typeSize, temp, typeSize);
	}
	free(temp);
}

void variadicPrint(char* str, ...)
{

	va_list list;
	int num =0;

	va_start(list, str);
	while (str != NULL) {

		num = va_arg(list, int);
		printf("%s %d\n", str, num);
		str = va_arg(list, char*);

	}

	va_end(list);
}
