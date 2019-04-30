#ifndef __PROTOTYPE__
#define __PROTOTYPE__

typedef enum
{
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT1,
	SORT2,
	SORT3,
	LINKED_LIST,
	NofOptions
} MenuOptions;


int		menu();
char*	getStrExactLength(char* inpStr);
int		checkAllocation(const void* p);
void variadicPrint(char* str, ...);
#endif
