#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"
#include "list.h"

#define DATA_TXT_FILE "DataFile.txt"
#define DATA_BIN_FILE "DataFile.bin"
typedef struct
{
	Garden** pGardenList;
	int count;
}City;



void readCity(City* pCity, int num);
void	showCityGardens(City* pCity);
void	showSpecificGardenInCity(City* pCity);
void saveCity(City* pCity, int num);
void	cityAddGarden(City* pCity);
void	addChildToSpecificGardenInCity(City* pCity);
void	birthdayToChild(City* pCity);
int		countChova(City* pCity);
void	releaseCity(City* pCity);
void sortByGardenName(City* pCity);
void sortByChildId(City* pCity);
void sortByGardenType(City* pCity);

void displayKindergartensFromList(LIST* pLst);
LIST* createLinkedListForKindergartenType(City* pCity, int type);
void LinkedList(City* pcity);


#endif
