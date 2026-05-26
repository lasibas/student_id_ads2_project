#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
#include "common.h"

/********** Linked List Operations **********/

void initArrayList(ArrayList* list);
int  insertAtHead(ArrayList* list, int value);
int  insertAtTail(ArrayList* list, int value);
int  insertAtIndex(ArrayList* list, int index, int value);
int  deleteAtHead(ArrayList* list);
int  deleteAtTail(ArrayList* list);
void displayList(ArrayList* list);
void reverseList(ArrayList* list);
void sortListBubble(ArrayList* list);
void mergeSortedLists(ArrayList* A, ArrayList* B, ArrayList* result);

/***** Doubly Linked List Operations *****/

void initListDLL(DLL* list);
int  insertAtHeadDLL(DLL* list, int value);

#endif // LINKED_LISTS_H