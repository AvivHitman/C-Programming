#ifndef __CHILD__
#define __CHILD__


typedef struct
{
	int	 id;
	int  age;
}Child;


void	readChild(FILE* fp, Child* pChild);
void	getChildFromUser(Child* pChild, int id);
void	showChild(const Child* pChild);
void	writeChild(FILE* fp,const Child* pChild);
int		findChildById(Child** pChildList, int count, int id);
void	birthday(Child* pChild);
int compareChildtByID(const void* st1, const void* st2);
void writeChildToBFile(FILE* fp, Child* pChild);
void readChildFromBFile(FILE* fp, Child* pChild);
#endif
