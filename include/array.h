#ifndef ARRAY_H
#define ARRAY_H
#include "common.h"

/* --- 1D Array --- */
void  initArray(int arr[], int* size);
void  arrayInput(int arr[], int* size);
void  printArray(int arr[], int size);
int   insertAt(int arr[], int* size, int index, int value);
int   deleteAt(int arr[], int* size, int index);
int   linearSearch(int arr[], int size, int value);
int   binarySearch(int arr[], int size, int value);
int   bubbleSort(int arr[], int size);
void  selectionSort(int arr[], int size, int minpos);
void  insertionSort(int arr[], int size);
void  mergeSort(int arr[], int left, int right);
void  quickSort(int arr[], int low, int high);
int   sumArray(int arr[], int size);
int   findMax(int arr[], int size);
int   findMin(int arr[], int size);
double averageArray(int numbers[], int size);
void  reverseArray(int numbers[], int size);
void  mergeSortedArrays(int a[], int na, int b[], int nb, int out[]);
void  rotateLeft(int arr[], int size, int k);


/* --- 2D Array --- */
void initMatrix(int matrix[MAX_ROWS][MAX_COLS], int* rows, int* cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int transposed[MAX_ROWS][MAX_COLS]);
void addMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols);
void multiplyMatrices(int MatA[][100], int MatB[][100], int result[][100], int n);
void sortRows(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
int  isSymmetric(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
int  sumDiagonal_antiDiagonal(int m[][50], int n);

/* --- Dynamic Arrays --- */
int* createDynamicArray(int size);
void fillDynamicArray(int* array, int size);
void freeArray(int* arr);
int* resizeArray(int* arr, int newCapacity);
#endif