#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>

static void merge(int arr[], int left, int mid, int right);
static int partition(int arr[], int low, int high);

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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);   
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}

int sumArray(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }

    return sum;
}

int findMax(int arr[], int size) {
    if (size <= 0) return 0;
    int max = arr[0];         

    for (int i = 1; i < size; i++) { 
        if (arr[i] > max) {  
            max = arr[i];    
        }
    }

    return max;              
}

int findMin(int arr[], int size) {
    if (size <= 0) return 0;
    int min = arr[0];         

    for (int i = 1; i < size; i++) {  
        if (arr[i] < min) {  
            min = arr[i];    
        }
    }

    return min;              
}

double averageArray(int numbers[], int size)

 {
    if (size == 0) 
	
	return 0.0;
    
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
    	
        sum =  sum + numbers[i];
        
    }
    return (double)sum / size;
    
    
}

void reverseArray(int numbers[], int size)
 {
    for (int i = 0; i < size / 2; i++)
	 {
        int tmp = numbers[i];
        
        numbers[i] = numbers[size - 1 - i];
        
        numbers [size - 1 - i] = tmp;
    }
}

void rotateLeft(int arr[], int size, int k) {
    if (size <= 0) return;
    k = k % size;

    for (int i = 0; i < k; i++) {
        int first = arr[0];

        for (int j = 0; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }

        arr[size - 1] = first;
    }
}

void mergeSortedArrays(int a[], int na, int b[], int nb, int out[]) {
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            out[k++] = a[i++];
        } else {
            out[k++] = b[j++];
        }
    }

    while (i < na) {
        out[k++] = a[i++];
    }

    while (j < nb) {
        out[k++] = b[j++];
    }
}

/*--- 2D Array Operations ---*/
void initMatrix(int matrix[MAX_ROWS][MAX_COLS], int* rows, int* cols) {
    printf("Enter matrix rows (1-%d): ", MAX_ROWS);
    if (scanf("%d", rows) <= 0 || *rows < 1 || *rows > MAX_ROWS) {
        printf("Invalid row count\n");
        *rows = 0;
        *cols = 0;
        return;
    }

    printf("Enter matrix cols (1-%d): ", MAX_COLS);
    if (scanf("%d", cols) <= 0 || *cols < 1 || *cols > MAX_COLS) {
        printf("Invalid column count\n");
        *rows = 0;
        *cols = 0;
        return;
    }

    printf("Enter %d values:\n", (*rows) * (*cols));
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            if (scanf("%d", &matrix[i][j]) <= 0) {
                printf("Invalid matrix input\n");
                *rows = i;
                *cols = (i == 0) ? j : *cols;
                return;
            }
        }
    }
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

void multiplyMatrices(int MatA[MAX_ROWS][MAX_COLS], int MatB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int n) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
            for (k = 0; k < n; k++)
                result[i][j] += MatA[i][k] * MatB[k][j];
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

static void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc((size_t)n1 * sizeof(int));
    int* R = (int*)malloc((size_t)n2 * sizeof(int));
    if (L == NULL || R == NULL) {
        free(L);
        free(R);
        return;
    }

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

int sumDiagonal_antiDiagonal(int m[MAX_ROWS][MAX_COLS], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += m[i][i];         
        sum += m[i][n - 1 - i]; 
    }

    if (n % 2 != 0)
        sum -= m[n / 2][n / 2]; //this used to fix the center element being added twice in case of odd n

    printf("Sum of diagonals/anti-diagonals: %d\n", sum);
    return sum;
}

static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

/*Dynamic arrays*/

int* createDynamicArray(int size){
    int* array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return array;
}

void fillDynamicArray(int* array, int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) <= 0) {
            printf("Invalid input\n");
            return;
        }
    }
}

void printDynamicArray(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void freeArray(int* arr) {
    free(arr);
}

int* resizeArray(int* arr, int newCapacity) {
    int* newArr = (int*) realloc(arr, newCapacity * sizeof(int));
    if (newArr == NULL) {
        printf("Error: original array unchanged.\n");
        return NULL;  
    }
    return newArr;
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