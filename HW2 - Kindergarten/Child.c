#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"

/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild) {
	//Child ID
	fscanf(fp, "%d", &pChild->id);
	fscanf(fp, "%d", &pChild->age);
}

/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild) {
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}

/**************************************************/
void getChildFromUser(Child* pChild, int id)
/**************************************************/
/**************************************************/
{
	pChild->id = id;

	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}

/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp, const Child* pChild) {
	fprintf(fp, "%d %d\n", pChild->id, pChild->age);
}

int findChildById(Child** pChildList, int count, int id) {
	Child temp = { id, 0 };
	Child* pTemp = &temp;
	int index;
	Child** pFound = NULL;

	qsort(pChildList, count, sizeof(Child*), compareChildtByID);

	pFound = (Child**) bsearch(&pTemp, pChildList, count, sizeof(Child*),
			compareChildtByID);
	index = pFound - pChildList;

	if (index < 0)
		index = -1;
	return index;
}

void birthday(Child* pChild) {
	pChild->age++;
}

int compareChildtByID(const void* st1, const void* st2) {
	Child* pS1 = *(Child**) st1;
	Child* pS2 = *(Child**) st2;
	return pS1->id - pS2->id;
}

///Binary File
void writeChildToBFile(FILE* fp, Child* pChild) {
	unsigned char info[2];
		unsigned char mask = 255;

		info[1] = (pChild->age) << 5 | (pChild->id) >> 8;
		info[0] = pChild->id & mask;

		fwrite(info, sizeof(unsigned char), 2, fp);
}

void readChildFromBFile(FILE* fp, Child* pChild) {
	unsigned char info[2];

		unsigned char mask = 31;

		fread(info, sizeof(unsigned char), 2, fp);

		pChild->id = (info[1] & mask) << 8 | info[0];

		pChild->age = info[1] >> 5;
}
