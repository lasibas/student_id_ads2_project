#include <stdio.h>
#include "include/array.h"

void arraySortingMenu() {
    int choice = 1, arr[MAX_1D], size = 0;
    do {
        printf("\n=== SORTING MENU ===\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                bubbleSort(arr, size);
                printf("Sorted array: ");
                printArray(arr, size);
                break;
            case 2:
                selectionSort(arr, size, 0);
                printf("Sorted array: ");
                printArray(arr, size);
                break;
            case 3:
                insertionSort(arr, size);
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

void staticArrayMenu() {
    int choice = 1, arr[MAX_1D], size = 0, value, index;
    do {
        printf("\n=== STATIC ARRAY MENU ===\n");
        printf("1. Insert at index\n2. Delete at index\n3. Print array\n4. sort array\n5. search array\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                printf("Index to insert: ");
                scanf("%d", &index);
                printf("Value to insert: ");
                scanf("%d", &value);
                if (insertAt(arr, &size, index, value) == 0)
                    printf("Inserted %d at index %d\n", value, index);
                else
                    printf("Insertion failed (invalid index or array full)\n");
                break;
            case 2:
                printf("Index to delete: ");
                scanf("%d", &index);
                if (deleteAt(arr, &size, index) == 0)
                    printf("Deleted element at index %d\n", index);
                else
                    printf("Deletion failed (invalid index or array empty)\n");
                break;
            case 3:
                printArray(arr, size);
                break;
            case 4:
                arraySortingMenu();
                break;
            case 5:
                arraySearchingMenu();
                break;
        }
    } while (choice != 0);
}

void matrixMenu() {
    int choice = 1, matrix[MAX_ROWS][MAX_COLS], transposed[MAX_ROWS][MAX_COLS], rows = 0, cols = 0;
    do {
        printf("\n=== MATRIX MENU ===\n");
        printf("1. Input matrix\n2. Print matrix\n3. Transpose matrix\n4. Add matrices\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                initMatrix(matrix, &rows, &cols);
                break;
            case 2:
                printMatrix(matrix, rows, cols);
                break;
            case 3:
                transposeMatrix(matrix, rows, cols, transposed);
                printf("Transposed matrix:\n");
                printMatrix(transposed, cols, rows);
                break;
            case 4:
                addMatrices(matrix, matrix, transposed, rows, cols);
                printf("Result of adding matrix to itself:\n");
                printMatrix(transposed, rows, cols);
                break;
        }
    } while (choice != 0);
}

void arrayMenu() {
    int choice = 1;
    do {
        printf("\n=== ARRAY MENU ===\n");
        printf("1. static array\n2. dynamic array\n3. matrices\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                staticArrayMenu();
                break;
            case 2:
                printf("Dynamic array features not implemented yet.\n");
                break;
            case 3:
                matrixMenu();
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

/*
 * Some VS Code compile actions build only demo.c.
 * Include array implementation in that mode so linking still succeeds.
 */
#ifndef ADS2_SEPARATE_COMPILATION
#include "src/array.c"
#endif