#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>

/*--- 1D Array Operations ---*/

/* Initialize: set size to 0 — array is logically empty */
void initArray(int arr[], int* size) {
    (void)arr;
    *size = 0;
}

void arrayInput(int arr[], int* size) {
    printf("Enter number of elements (max %d): ", MAX_1D);
    if (scanf("%d", size) <= 0 || *size < 0 || *size > MAX_1D) {
        printf("Invalid size\n");
        *size = 0;
        return;
    }
    printf("Enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &arr[i]) <= 0) {
            printf("Invalid input\n");
            *size = i; // set size to number of successfully read elements
            return;
        }
    }
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

void addMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int isSymmetric(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    if (rows != cols) return 0;

    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < cols; j++)
            if (matrix[i][j] != matrix[j][i])
                return 0;  
    return 1;
}

void sortRows(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int pass = 0; pass < cols - 1; pass++)
            for (int j = 0; j < cols - 1 - pass; j++)
                if (matrix[i][j] > matrix[i][j + 1]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][j + 1];
                    matrix[i][j + 1] = temp;
                }
    }
}

/*
 * Some IDE actions compile this file directly as an executable.
 * Provide a fallback main only for that mode.
 */
#if !defined(ADS2_SEPARATE_COMPILATION) && !defined(ADS2_EMBEDDED_ARRAY)
int main(void) {
    return 0;
}
#endif