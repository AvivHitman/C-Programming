/*
 * list.h
 *
 *  Created on: Jan 7, 2019
 *      Author: aviv
 */
//#include "City.h"

#ifndef LIST_H_
#define LIST_H_


typedef void* DATA;

typedef struct node  {
	DATA  key;
	struct node* next;
}NODE;

typedef struct  {
	NODE head;
}LIST;


int L_init(LIST* pList);
NODE* L_insert(NODE* pNode, DATA Value);
int L_delete(NODE* pNode);
int L_free(LIST* pList);
int L_print(LIST* pList, void (*print)(const void*));



#endif /* LIST_H_ */
