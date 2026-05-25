#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
#include "common.h"

/********** Linked List Operations **********/

void initArrayList(ArrayList* list);
int insertAtHead(ArrayList* list, int value);
int insertAtTail(ArrayList* list, int value);
int insertAtIndex(ArrayList* list, int index, int value);

#endif // LINKED_LISTS_H