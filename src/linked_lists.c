#include "../include/linked_lists.h"
#include <stdlib.h>
#include <stdio.h>


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

// Delete the first node with the given value
int deleteByValue(ArrayList* L, int value)
{
    // Start from the first node
    Node* current = L->head;

    // Previous node
    Node* previous = NULL;

    // Search for the value
    while(current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    // Value not found
    if(current == NULL)
    {
        return -1;
    }

    // If the node is the head
    if(previous == NULL)
    {
        L->head = current->next;
    }
    else
    {
        // Skip the node
        previous->next = current->next;
    }

    // Free memory
    free(current);

    return 0;
}

// Search for a value in the list
Node* searchValue(ArrayList* L, int value)
{
    // Start from the first node
    Node* current = L->head;

    // Go through all nodes
    while(current != NULL)
    {
        // Check if value is found
        if(current->data == value)
        {
            return current;
        }

        // Move to the next node
        current = current->next;
    }

    // Value not found
    return NULL;
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
            insertAtTail(result, pA->data);
            pA = pA->next;
        } else {
            insertAtTail(result, pB->data);
            pB = pB->next;
        }
    }
    while (pA != NULL) {
        insertAtTail(result, pA->data);
        pA = pA->next;
    }
    while (pB != NULL) {
        insertAtTail(result, pB->data);
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

int insertAtTailDLL(DLL* L, int value) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) return 0;

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = L->tail;      

    if (L->tail != NULL) {
        L->tail->next = newNode;  
    } else {
        L->head = newNode;        
    }

    L->tail = newNode;            
    L->size++;
    return 1;
}

int insertAtIndexDLL(DLL* L, int index, int value) {
    if (index < 0 || index > L->size) return 0;

    if (index == 0) return insertAtHeadDLL(L, value);
    if (index == L->size) return insertAtTailDLL(L, value);

    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    if (!newNode) return 0;

    newNode->data = value;

    DNode* current = L->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    L->size++;
    return 1;
}

int deleteAtHeadDLL(DLL* L) {
    if (L->head == NULL) return -1;

    DNode* temp = L->head;
    int val = temp->data;

    L->head = L->head->next;
    if (L->head != NULL) {
        L->head->prev = NULL;
    } else {
        L->tail = NULL; 
    }

    free(temp);
    return val;
}

int deleteAtTailDLL(DLL* L) {
    if (L->tail == NULL) return -1;

    DNode* temp = L->tail;
    int val = temp->data;

    L->tail = L->tail->prev;
    if (L->tail != NULL) {
        L->tail->next = NULL;
    } else {
        L->head = NULL; 
    }

    free(temp);
    return val;
}

int deleteAtIndexDLL(DLL* L, int index) {
    if (index < 0 || index >= L->size) return -1;

    if (index == 0) return deleteAtHeadDLL(L);
    if (index == L->size - 1) return deleteAtTailDLL(L);

    DNode* current = L->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    int val = current->data;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    L->size--;
    return val;
}

void dllDisplayForward(DLL* L) {
    printf("NULL -> ");
    DNode* curr = L->head;
    while (curr != NULL) {
        printf("[%d]", curr->data);
        if (curr->next != NULL) printf(" -> ");
        curr = curr->next;
    }
    printf(" -> NULL  (size=%d)\n", L->size);
}
 
void dllDisplayBackward(DLL* L) {
    printf("NULL -> ");
    DNode* curr = L->tail;
    while (curr != NULL) {
        printf("[%d]", curr->data);
        if (curr->prev != NULL) printf(" -> ");
        curr = curr->prev;
    }
    printf(" -> NULL  (reversed, size=%d)\n", L->size);
}
 


