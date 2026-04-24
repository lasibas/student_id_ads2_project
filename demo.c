#include <stdio.h>
#include "include/array.h"

void arraySortingMenu(int arr[], int size) {
    int choice = 1;
    if (size <= 0) {
        printf("Array is empty. Add elements first.\n");
        return;
    }
    do {
        printf("\n=== SORTING MENU ===\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n0. Back\nChoice: ");
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
            case 4:
                mergeSort(arr, 0, size - 1);
                printf("Sorted array: ");
                printArray(arr, size);
                break;
            case 5:
                quickSort(arr, 0, size - 1);
                printf("Sorted array: ");
                printArray(arr, size);
                break;
        }
    } while (choice != 0);
}

void arraySearchingMenu(int arr[], int size) {
    int choice = 1, value;
    if (size <= 0) {
        printf("Array is empty. Add elements first.\n");
        return;
    }
    do {
        printf("\n=== SEARCHING MENU ===\n");
        printf("1. Linear Search\n2. Binary Search\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                printf("Value to search: ");
                scanf("%d", &value);
                {
                    int pos = linearSearch(arr, size, value);
                    if (pos != -1) printf("Found at index %d\n", pos);
                    else printf("Not found\n");
                }
                break;
            case 2:
                bubbleSort(arr, size);
                printf("Value to search: ");
                scanf("%d", &value);
                {
                    int pos2 = binarySearch(arr, size, value);
                    if (pos2 != -1) printf("Found at index %d\n", pos2);
                    else printf("Not found\n");
                }
                break;
        }
    } while (choice != 0);
}

void staticArrayMenu() {
    int choice = 1, arr[MAX_1D], size = 0, value, index;
    arrayInput(arr, &size);
    do {
        printf("\n=== STATIC ARRAY MENU ===\n");
        printf("1. Insert at index\n2. Delete at index\n3. Print array\n4. sort array\n5. search array\n6. sum array\n7. find minimum\n8. find maximum\n0. Back\nChoice: ");
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
                arraySortingMenu(arr, size);
                break;
            case 5:
                arraySearchingMenu(arr, size);
                break;
            case 6:
                printf("Sum of array elements: %d\n", sumArray(arr, size));
                break;
            case 7:
                printf("Minimum element: %d\n", findMin(arr, size));
                break;
            case 8:
                printf("Maximum element: %d\n", findMax(arr, size));
                break;
        }
    } while (choice != 0);
}

void dynamicArrayMenu() {
    int choice = 1, size;
    int* dynArr = NULL;
    do{
        printf("\n=== DYNAMIC ARRAY MENU ===\n");
        printf("1. Create dynamic array\n2. Fill dynamic array\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                printf("Size of dynamic array: ");
                scanf("%d", &size);
                {
                    dynArr = createDynamicArray(size);
                    if (dynArr != NULL) {
                        printf("Dynamic array of size %d created.\n", size);
                    }
                }
                break;
            case 2:
                {
                    if (dynArr != NULL) {
                        fillDynamicArray(dynArr, size);
                        printf("You entered: ");
                        printArray(dynArr, size);
                    }
                }
                break;
            case 0:
                if (dynArr != NULL) {
                    freeArray(dynArr);
                    printf("Dynamic array memory freed.\n");
                }
                break;
            
        }
    }while (choice != 0);
}

void matrixMenu() {
    int choice = 1, matrix[MAX_ROWS][MAX_COLS], transposed[MAX_ROWS][MAX_COLS], rows = 0, cols = 0;
    do {
        printf("\n=== MATRIX MENU ===\n");
        printf("1. Input matrix\n2. Print matrix\n3. Transpose matrix\n4. Add matrices\n5. Multiply matrices\n6. Sum diagonals/anti-diagonals\n7. sort rows\n8. isSymmetric\n0. Back\nChoice: ");
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
            case 5:
                multiplyMatrices(matrix, matrix, transposed, rows);
                printf("Result of multiplying matrix by itself:\n");
                printMatrix(transposed, rows, cols);
                break;
            case 6:
                sumDiagonal_antiDiagonal(matrix, rows);
                break;
            case 7:
                sortRows(matrix, rows, cols);
                printf("Matrix with sorted rows:\n");
                printMatrix(matrix, rows, cols);
                break;
            case 8:
                if (isSymmetric(matrix, rows, cols)) {
                    printf("Matrix is symmetric.\n");
                } else {
                    printf("Matrix is not symmetric.\n");
                }
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
                dynamicArrayMenu();
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
#define ADS2_EMBEDDED_ARRAY
#include "src/array.c"
#undef ADS2_EMBEDDED_ARRAY
#endif