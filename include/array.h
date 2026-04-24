#ifndef ARRAY_H
#define ARRAY_H
#include "common.h"

/* --- 1D Array --- */
void  initArray(int arr[], int* size);
void  printArray(int arr[], int size);
int   insertAt(int arr[], int* size, int index, int value);
int   deleteAt(int arr[], int* size, int index);
int   linearSearch(int arr[], int size, int value);
int   binarySearch(int arr[], int size, int value);
int   bubbleSort(int arr[], int size);
void  selectionSort(int arr[], int size, int minpos);
void  insertionSort(int arr[], int size);


/* --- 2D Array --- */
void initMatrix(int matrix[MAX_ROWS][MAX_COLS], int* rows, int* cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int transposed[MAX_ROWS][MAX_COLS]);
void addMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols);
#endif