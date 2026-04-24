#include <stdio.h>
#include "include/array.h"

void arraySortingMenu() {
    int choice = 1, arr[MAX_1D], size = 0;
    do {
        printf("\n=== SORTING MENU ===\n");
        printf("1. Bubble Sort\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                bubbleSort(arr, size);
                printf("Sorted array: ");
                printArray(arr, size);
                break;
        }
    } while (choice != 0);
}

void arraySearchingMenu() {
    int choice = 1, arr[MAX_1D], size = 0, value;
    do {
        printf("\n=== SEARCHING MENU ===\n");
        printf("1. Linear Search\n2. Binary Search\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                printf("Value to search: ");
                scanf("%d", &value);
                int pos = linearSearch(arr, size, value);
                if (pos != -1) printf("Found at index %d\n", pos);
                else printf("Not found\n");
                break;
            case 2:
                printf("Value to search: ");
                scanf("%d", &value);
                int pos2 = binarySearch(arr, size, value);
                if (pos2 != -1) printf("Found at index %d\n", pos2);
                else printf("Not found\n");
                break;
        }
    } while (choice != 0);
}

void arrayMenu() {
    int choice = 1, arr[MAX_1D], size = 0, value, index;
    do {
        printf("\n=== ARRAY MENU ===\n");
        printf("1. Insert element\n2. Delete element\n"
               "3. Search\n4. Sort\n5. Display\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                printf("Index and value: ");
                scanf("%d %d", &index, &value);
                insertAt(arr, &size, index, value);
                break;
            case 2:
                printf("Index to delete: ");
                scanf("%d", &index);
                deleteAt(arr, &size, index);
                break;
            case 3:
                arraySearchingMenu();
                break;
            case 4:
                arraySortingMenu();
                break;
        }
    } while (choice != 0);
}

int main() {
    int choice = 1;
    do {
        printf("\n=== ADS2 PROJECT DEMO ===\n");
        printf("1. Arrays\n2. Linked Lists\n3. Stacks\n"
               "4. Queues\n5. File Handling\n6. String Utils\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1: arrayMenu(); break;
            /* ... */
        }
    } while (choice != 0);
    return 0;
}