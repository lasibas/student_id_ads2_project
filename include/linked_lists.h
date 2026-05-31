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
int  deleteByValue(ArrayList* list, int value);
Node* searchValue(ArrayList* list, int value);
void displayList(ArrayList* list);
void reverseList(ArrayList* list);
void sortListBubble(ArrayList* list);
void mergeSortedLists(ArrayList* A, ArrayList* B, ArrayList* result);

/***** Doubly Linked List Operations *****/
void initListDLL(DLL* list);
int  insertAtHeadDLL(DLL* list, int value);
int  insertAtTailDLL(DLL* list, int value);
int  insertAtIndexDLL(DLL* list, int index, int value);
int  deleteAtHeadDLL(DLL* list);
int  deleteAtTailDLL(DLL* list);
int  deleteAtIndexDLL(DLL* list, int index);
void dllDisplayForward(DLL* list);
void dllDisplayBackward(DLL* list);

/****** Stacks Operations *****/
void initStack(Stack* stack);
int  push(Stack* stack, int value);
int  pop(Stack* stack);
int  peek(Stack* stack);
int  isEmpty(Stack* stack);

/****** Queue Operations *****/
void initQueue(Queue* queue);
int  enqueue(Queue* queue, int value);
int  dequeue(Queue* queue);
int  front(Queue* queue);
int  rear(Queue* queue);

#endif // LINKED_LISTS_H