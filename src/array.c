#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>

/*--- 1D Array Operations ---*/

/* Initialize: set size to 0 — array is logically empty */
void initArray(int arr[], int* size) {
    (void)arr;
    *size = 0;
}

/* Print in [a, b, c] format */
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/* Insert value at index — shift elements right first */
int insertAt(int arr[], int* size, int index, int value) {
    if (index < 0 || index > *size) return -1;  // invalid index
    if (*size >= MAX_1D) return -1;             // array full

    for (int i = *size; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    (*size)++;
    return 0;
}

/* Delete element at index — shift elements left */
int deleteAt(int arr[], int* size, int index) {
    if (index < 0 || index >= *size) return -1; // invalid index
    if (*size == 0) return -1;// array empty
    if(*size > MAX_1D) return -1; // size exceeds max

    for (int i = index; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
    return 0;
}

/* Linear search:*/
int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i; // found
    }
    return -1; // not found
}

/* Binary search: */
int binarySearch(int arr[], int size, int value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return mid; // found
        else if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // not found
}

/* Bubble sort: */
int bubbleSort(int arr[], int size) {
    if (size <= 1) return 0; // already sorted
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

void selectionSort(int arr[], int size, int minpos) {
    for (int i = 0; i < size - 1; i++) {
         minpos = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minpos])
                minpos = j;
 
        int temp     = arr[i];
        arr[i]       = arr[minpos];
        arr[minpos]  = temp;
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i]; 
        int j   = i - 1;
 
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; 
    }
}


/*--- 2D Array Operations ---*/
void initMatrix(int matrix[MAX_ROWS][MAX_COLS], int* rows, int* cols) {
    (void)matrix;
    *rows = 0;
    *cols = 0;
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf("]\n");
    }
}

void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int transposed[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}