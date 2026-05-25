#include "../include/linked_lists.h"
#include <stdlib.h>

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