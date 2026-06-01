#include "../include/array.h"
#include <stdio.h>
#include <stdlib.h>

/* Helper: merge two sorted subarrays [left..mid] and [mid+1..right].
 * Parameters: `arr` - array to merge into; `left, mid, right` - bounds.
 * Behavior: allocates temporary buffers, merges in-place, frees buffers.
 * Complexity: O(n) time, O(n) extra memory where n = right-left+1.
 */
static void merge(int arr[], int left, int mid, int right);

/* Helper: partition used by quicksort.
 * Parameters: `arr` - array; `low, high` - partition bounds.
 * Returns: pivot final index after partitioning.
 * Complexity: O(n) time for the partition step.
 */
static int partition(int arr[], int low, int high);

/*--- 1D Array Operations ---*/

/* Initialize array metadata.
 * Sets the logical `size` to 0 (empties the array). `arr` is unused
 * here but kept for API symmetry with other operations.
 */
void initArray(int arr[], int* size) {
    (void)arr;
    *size = 0;
}

/* Read integers into `arr` from stdin.
 * Prompts for number of elements (clamped to [0, MAX_1D]) and then
 * reads that many integers. On invalid input the function sets `size`
 * to the number successfully read and returns early.
 */
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

/* Print the array in a readable list format: [a, b, c].
 * Parameters: `arr` and its logical `size`.
 */
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/* Insert `value` at `index` shifting subsequent elements right.
 * Returns 0 on success, -1 on invalid index or when array is full.
 */
int insertAt(int arr[], int* size, int index, int value) {
    if (index < 0 || index > *size) return -1;  // invalid index
    if (*size >= MAX_1D) return -1;             // array full

    for (int i = *size; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    (*size)++;
    return 0;
}

/* Delete element at `index` shifting elements left.
 * Returns 0 on success, -1 on invalid index or empty array.
 */
int deleteAt(int arr[], int* size, int index) {
    if (index < 0 || index >= *size) return -1; // invalid index
    if (*size == 0) return -1;// array empty
    if(*size > MAX_1D) return -1; // size exceeds max

    for (int i = index; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
    return 0;
}

/* Linear search for `value` in `arr`.
 * Returns index of first match or -1 if not found.
 * Complexity: O(n).
 */
int linearSearch(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return i; // found
    }
    return -1; // not found
}

/* Binary search for `value` in a sorted `arr`.
 * Returns index if found, -1 otherwise. Requires `arr` sorted.
 * Complexity: O(log n).
 */
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

/* Bubble sort: in-place stable sort. Returns 0.
 * Complexity: O(n^2) average and worst-case.
 */
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

/* Selection sort: in-place unstable sort.
 * `minpos` is used internally as the index of minimum element.
 * Complexity: O(n^2).
 */
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

/* Insertion sort: in-place stable sort.
 * Good for small or nearly-sorted arrays. Complexity O(n^2).
 */
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

/* Merge sort: recursive divide-and-conquer.
 * Sorts the subarray `arr[left..right]` in-place using extra memory
 * in the `merge` helper. Complexity: O(n log n) time.
 */
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);   
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    }
}

/* Quick sort: recursive in-place sort using Lomuto partition.
 * Average complexity O(n log n), worst-case O(n^2).
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}

/* Sum of array elements. Returns the integer sum.
 * Complexity: O(n).
 */
int sumArray(int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }

    return sum;
}

/* Find maximum value in `arr`. Returns 0 for empty arrays.
 * Complexity: O(n).
 */
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

/* Find minimum value in `arr`. Returns 0 for empty arrays.
 * Complexity: O(n).
 */
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

/* Compute average of integer array as double.
 * Returns 0.0 when `size` is zero to avoid division by zero.
 */
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

/* Reverse array in-place.
 * Swaps elements symmetrically. Complexity O(n).
 */
void reverseArray(int numbers[], int size)
 {
    for (int i = 0; i < size / 2; i++)
	 {
        int tmp = numbers[i];
        
        numbers[i] = numbers[size - 1 - i];
        
        numbers [size - 1 - i] = tmp;
    }
}

/* Rotate array left by `k` positions (in-place).
 * Complexity: O(n*k) with current implementation; can be optimized.
 */
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

/* Merge two already-sorted arrays `a` (size `na`) and `b` (size `nb`)
 * into `out[]` producing a sorted merged array. Complexity O(na+nb).
 */
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
/* Initialize matrix by reading rows, cols and values from stdin.
 * On invalid input sets `rows` and `cols` to 0.
 */
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

/* Print a matrix row-by-row using bracketed row notation.
 */
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

/* Compute the transpose of `matrix` into `transposed`.
 * Result has dimensions `cols x rows`.
 */
void transposeMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int transposed[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

/* Element-wise addition of two matrices into `result`.
 */
void addMatrices(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/* Multiply two n x n matrices `MatA` and `MatB` into `result`.
 * Uses the straightforward triple-loop algorithm. Complexity O(n^3).
 */
void multiplyMatrices(int MatA[MAX_ROWS][MAX_COLS], int MatB[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int n) {
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
            for (k = 0; k < n; k++)
                result[i][j] += MatA[i][k] * MatB[k][j];
        }
}

/* Check whether a square matrix is symmetric (matrix == transpose).
 * Returns 1 if symmetric, 0 otherwise.
 */
int isSymmetric(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    if (rows != cols) return 0;

    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < cols; j++)
            if (matrix[i][j] != matrix[j][i])
                return 0;  
    return 1;
}

/* Sort each row of the matrix independently using bubble sort.
 * Complexity per row O(cols^2).
 */
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

/* Internal merge helper used by `mergeSort`.
 * Merges two sorted subarrays in `arr` by allocating temporary buffers.
 */
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

/* Compute sum of main diagonal and anti-diagonal of an n x n matrix.
 * If n is odd, the center element is subtracted once to avoid double-count.
 */
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

/* Lomuto partition implementation for quicksort.
 * Chooses last element as pivot and partitions array in-place.
 */
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