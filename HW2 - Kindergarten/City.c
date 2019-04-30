#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "City.h"
#include "Kindergarten.h"
#include "General.h"



void readCity(City* pCity, int num) {

	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}

	if (num == 0) {
		pCity->pGardenList = readAllGardensFromFile(DATA_TXT_FILE,
				&(pCity->count));
	} else {
		pCity->pGardenList = readAllGardensFromFileBin(DATA_BIN_FILE,
				&(pCity->count));
	}

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void showCityGardens(City* pCity) {
	showAllGardens(pCity->pGardenList, pCity->count);
}

void showSpecificGardenInCity(City* pCity) {
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity, int num) {
	if (num == 0) {
		writeGardensToFile(pCity->pGardenList, pCity->count, DATA_TXT_FILE);
		} else {
			writeGardensToFileBin(pCity->pGardenList, pCity->count, DATA_BIN_FILE);
		}
}

void cityAddGarden(City* pCity) {
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL) //Allocation error
		printf("Error adding kindergarten\n");
}

void addChildToSpecificGardenInCity(City* pCity) {
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void birthdayToChild(City* pCity) {
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int countChova(City* pCity) {
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++) {
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void releaseCity(City* pCity) {
	release(pCity->pGardenList, pCity->count);
}

void sortByGardenName(City* pCity) {
	GenInsertSort(pCity->pGardenList, pCity->count, sizeof(pCity->pGardenList),
			compareGardenByName);

}

void sortByChildId(City* pCity) {

	Garden* pGarden;
	pGarden = getGardenAskForName(pCity->pGardenList, pCity->count);
	GenInsertSort(pGarden->childPtrArr,
				pGarden->childCount, sizeof(pGarden->childPtrArr),
				compareChildtByID);

}

void sortByGardenType(City* pCity) {
	GenInsertSort(pCity->pGardenList, pCity->count, sizeof(pCity->pGardenList),
			compareGardenByType);

}
void LinkedList(City* pcity) {
	int num;

	num = (int) getTypeOption();

	LIST* list = createLinkedListForKindergartenType(pcity, num);

	displayKindergartensFromList(list);

}



LIST* createLinkedListForKindergartenType(City* pCity, int type) {
	int i;
	LIST lst;
	LIST* pLst;

	NODE* pNode;

	L_init(&lst);
	pNode = &lst.head;

	for (i = 0; i < pCity->count; i++) {
		if (pCity->pGardenList[i]->type == type) {

			pNode = L_insert(pNode, &pCity->pGardenList[i]);
		}
	}

	pLst = (LIST*) malloc(sizeof(lst));

	if (!pLst) {
		return NULL;
	}
	memcpy(pLst, &lst, sizeof(lst));

	return pLst;
}

void displayKindergartensFromList(LIST* pLst) {
	L_print(pLst, printGarden);
	L_free(pLst);
}

