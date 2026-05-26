#include "../include/linked_lists.h"
#include <stdlib.h>

/*---Singly Linked List Implementation---*/

void initArrayList(ArrayList* list) {
    list->head = NULL;
    list->size = 0;
}

int insertAtHead(ArrayList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1; // allocation failed

    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    return 0;
}

int insertAtTail(ArrayList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1; // allocation failed

    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
    return 0;
}

int insertAtIndex(ArrayList* list, int index, int value) {
    if (index < 0 || index > list->size) return -1; // invalid index

    if (index == 0) return insertAtHead(list, value);
    if (index == list->size) return insertAtTail(list, value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1; // allocation failed

    newNode->data = value;

    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
    return 0;
}

int deleteAtHead(ArrayList* L) {
    if (L->head == NULL)
        return -1;

    Node* temp = L->head;      
    int val = temp->data;      
    L->head = L->head->next;   
    free(temp);                
    return val;
}

int deleteAtTail(ArrayList* L) {
    if (L->head == NULL) return -1;

    if (L->head->next == NULL) {
        int val = L->head->data;
        free(L->head);
        L->head = NULL;
        return val;
    }

    Node* prev = L->head;
    while (prev->next->next != NULL) {
        prev = prev->next;
    }

    int val = prev->next->data;
    free(prev->next);
    prev->next = NULL;

    return val;
}

void displayList(ArrayList* list) {
    Node* current = list->head;
    printf("List (size=%d): ", list->size);
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverseList(ArrayList* list) {
    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; // store next
        current->next = prev; // reverse current node's pointer
        prev = current;       // move pointers one position ahead
        current = next;
    }
    list->head = prev;
}

void sortListBubble(ArrayList* L) {
    if (L->head == NULL) return;
    int swapped;
    Node* ptr;
    Node* last = NULL;
    do {
        swapped = 0;
        ptr = L->head;
        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

void mergeSortedLists(ArrayList* A, ArrayList* B, ArrayList* result) {
    Node* pA = A->head;
    Node* pB = B->head;
    while (pA != NULL && pB != NULL) {
        if (pA->data <= pB->data) {
            insertEnd(result, pA->data);
            pA = pA->next;
        } else {
            insertEnd(result, pB->data);
            pB = pB->next;
        }
    }
    while (pA != NULL) {
        insertEnd(result, pA->data);
        pA = pA->next;
    }
    while (pB != NULL) {
        insertEnd(result, pB->data);
        pB = pB->next;
    }
}


/*---Doubly Linked List Implementation---*/

void initListDLL(DLL* L)
{
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
}

int insertAtHeadDLL(DLL* L, int value)
{
    DNode* newNode = malloc(sizeof(DNode));

    if(newNode == NULL)
        return 0;

    newNode->data = value;

    newNode->next = L->head;
    newNode->prev = NULL;

    if(L->head != NULL)
        L->head->prev = newNode;
    else
        L->tail = newNode;

    L->head = newNode;

    L->size++;

    return 1;
}