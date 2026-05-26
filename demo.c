#include <stdio.h>
#include <stdlib.h>
#include "include/array.h"
#include "include/file_utils.h"
#include "include/linked_lists.h"
#include "include/string_utils.h"

static void clear_screen(void);
static void wait_for_enter(void);
void arrayMenu();
void fileUtilsMenu();
void staticArrayMenu();
void dynamicArrayMenu();
void matrixMenu();
void arraySortingMenu(int arr[], int size);
void arraySearchingMenu(int arr[], int size);
void singlyLinkedListsMenu();
void linkedListsMenu();
void stringUtilsMenu();

int main() {
    int choice = 1;
    clear_screen();
    do {
        printf("\n=== ADS2 PROJECT DEMO ===\n");
        printf("1. Arrays\n2. Linked Lists\n3. Stacks\n"
               "4. Queues\n5. File Handling\n6. String Utils\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                arrayMenu();
                clear_screen();
                break;
            case 2:
                linkedListsMenu();
                clear_screen();
                break;
            case 5:
                fileUtilsMenu();
                clear_screen();
                break;
            case 6:
                stringUtilsMenu();
                clear_screen();
                break;
        }
    } while (choice != 0);
    return 0;
}

static void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void wait_for_enter(void) {
    int c;
    printf("\nPress Enter to continue...");
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void fileUtilsMenu() {
    int choice = 1;
    char filename[MAX_STRING_LEN];
    Record r;
    clear_screen();
    do {
        printf("\n=== FILE UTILITIES MENU ===\n");
        printf("1. Create binary file\n2. Write record to file\n3. Read record from file\n4. Count records in file\n5. Append record to file\n6. Search record by ID\n7. Update record\n8. Copy binary file\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                if (createBinaryFile(filename) == 0)
                    printf("Binary file '%s' created successfully.\n", filename);
                else
                    printf("Failed to create file '%s'.\n", filename);
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter record ID: ");
                scanf("%d", &r.id);
                printf("Enter record name: ");
                scanf("%s", r.name);
                printf("Enter record note: ");
                scanf("%f", &r.note);
                if (writeRecord(filename, &r) == 0)
                    printf("Record written to '%s' successfully.\n", filename);
                else
                    printf("Failed to write record to '%s'.\n", filename);
                break;
            case 3:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter record ID: ");
                scanf("%d", &r.id);
                printf("Enter record name: ");
                scanf("%s", r.name);
                printf("Enter record note: ");
                scanf("%f", &r.note);
                if (appendRecord(filename, &r) == 0)
                    printf("Record appended to '%s' successfully.\n", filename);
                else
                    printf("Failed to append record to '%s'.\n", filename);
                break;
            case 4:
                printf("Enter filename: ");
                scanf("%s", filename);
                int count = countRecords(filename);
                if (count != -1) {
                    printf("Number of records in '%s': %d\n", filename, count);
                } else {
                    printf("Failed to count records in '%s'.\n", filename);
                }
                break;
            case 5:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter record ID: ");
                scanf("%d", &r.id);
                printf("Enter record name: ");
                scanf("%s", r.name);
                printf("Enter record note: ");
                scanf("%f", &r.note);
                if (appendRecord(filename, &r) == 0)
                    printf("Record appended to '%s' successfully.\n", filename);
                else
                    printf("Failed to append record to '%s'.\n", filename);
                break;
            case 6:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter record ID to search: ");
                scanf("%d", &r.id);
                if (searchRecordById(filename, r.id, &r) != -1) {
                    printf("Record found:\n");
                    printf("ID: %d\nName: %s\nNote: %.2f\n", r.id, r.name, r.note);
                } else {
                    printf("Record with ID %d not found.\n", r.id);
                }
                break;
            case 7:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter record index to update: ");
                scanf("%d", &r.id);
                printf("Enter new record name: ");
                scanf("%s", r.name);
                printf("Enter new record note: ");
                scanf("%f", &r.note);
                if (updateRecord(filename, r.id, r) == 0)
                    printf("Record updated in '%s' successfully.\n", filename);
                else
                    printf("Failed to update record in '%s'.\n", filename);
                break;
            case 8:
                printf("Enter source filename: ");
                scanf("%s", filename);
                printf("Enter destination filename: ");
                scanf("%s", r.name);
                if (copyBinaryFile(filename, r.name) == 0)
                    printf("File copied from '%s' to '%s' successfully.\n", filename, r.name);
                else
                    printf("Failed to copy file from '%s' to '%s'.\n", filename, r.name);
                break;
        }
    } while (choice != 0);
}

void arraySortingMenu(int arr[], int size) {
    int choice = 1;
    if (size <= 0) {
        printf("Array is empty. Add elements first.\n");
        return;
    }
    clear_screen();
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
    clear_screen();
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
    clear_screen();
    do {
        printf("\n=== STATIC ARRAY MENU ===\n");
        printf("1. Insert at index\n2. Delete at index\n3. Print array\n4. sort array\n5. search array\n6. sum array\n7. find minimum\n8. find maximum\n9. average array\n10. reverse array\n0. Back\nChoice: ");
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
            case 9:
                printf("Average of array elements: %.2f\n", averageArray(arr, size));
                break;
            case 10:
                reverseArray(arr, size);
                printf("Reversed array: ");
                printArray(arr, size);
                break;
        }

        if (choice != 0) {
            wait_for_enter();
        }
    } while (choice != 0);
}

void dynamicArrayMenu() {
    int choice = 1, size;
    int* dynArr = NULL;
    clear_screen();
    do{
        printf("\n=== DYNAMIC ARRAY MENU ===\n");
        printf("1. Create dynamic array\n2. Fill dynamic array\n3. Print dynamic array\n4. Resize dynamic array\n5. Sort dynamic array\n6. Search dynamic array\n0. Back\nChoice: ");
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
                    else printf("Failed to create dynamic array.\n");
                }
                break;
            case 2:
                {
                    if (dynArr != NULL) {
                        fillDynamicArray(dynArr, size);
                        printf("You entered: ");
                        printArray(dynArr, size);
                    }
                    else printf("Failed to fill dynamic array.\n");
                }
                break;
            case 3:
                {
                    if (dynArr != NULL) {
                        printDynamicArray(dynArr, size);
                    }
                    else printf("Failed to print dynamic array.\n");
                }
                break;
            case 4:
                {
                    if (dynArr != NULL) {
                        int newSize;
                        printf("New size for dynamic array: ");
                        scanf("%d", &newSize);
                        int* resizedArr = resizeArray(dynArr, newSize);
                        if (resizedArr != NULL) {
                            dynArr = resizedArr;
                            size = newSize;
                            printf("Dynamic array resized to %d.\n", newSize);
                        }
                        else printf("Failed to resize dynamic array.\n");
                    }
                }
                break;
            case 5:
                {
                    if (dynArr != NULL) {
                        arraySortingMenu(dynArr, size);
                    }
                    else printf("Failed to sort dynamic array.\n");
                }
                break;
            case 6:
                {
                    if (dynArr != NULL) {
                        arraySearchingMenu(dynArr, size);
                    }
                    else printf("Failed to search dynamic array.\n");
                }
                break;
            case 0:
                if (dynArr != NULL) {
                    freeArray(dynArr);
                    printf("Dynamic array memory freed.\n");
                }
                else printf("No dynamic array to free.\n");
                break;
        }
    }while (choice != 0);
}

void matrixMenu() {
    int choice = 1, matrix[MAX_ROWS][MAX_COLS], transposed[MAX_ROWS][MAX_COLS], rows = 0, cols = 0;
    clear_screen();
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
    clear_screen();
    do {
        printf("\n=== ARRAY MENU ===\n");
        printf("1. static array\n2. dynamic array\n3. matrices\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                staticArrayMenu();
                clear_screen();
                break;
            case 2:
                dynamicArrayMenu();
                clear_screen();
                break;
            case 3:
                matrixMenu();
                clear_screen();
                break;
        }
    } while (choice != 0);
}

void singlyLinkedListsMenu() {
    int choice = 1;
    ArrayList list;
    initArrayList(&list);
    clear_screen();
    do {
        printf("\n=== SINGLY LINKED LISTS MENU ===\n");
        printf("1. Insert at head\n2. Insert at tail\n3. Insert at index\n4. Delete at head\n5. Delete at tail\n8. Display list\n9. Reverse list\n10. Sort list\n 11. Merge sorted lists\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                {
                    int value;
                    printf("Value to insert at head: ");
                    scanf("%d", &value);
                    if (insertAtHead(&list, value) == 0)
                        printf("Inserted %d at head.\n", value);
                    else
                        printf("Failed to insert at head.\n");
                }
                break;
            case 2:
                {
                    int value;
                    printf("Value to insert at tail: ");
                    scanf("%d", &value);
                    if (insertAtTail(&list, value) == 0)
                        printf("Inserted %d at tail.\n", value);
                    else
                        printf("Failed to insert at tail.\n");
                }
                break;
            case 3:
                {
                    int value, index;
                    printf("Index to insert: ");
                    scanf("%d", &index);
                    printf("Value to insert: ");
                    scanf("%d", &value);
                    if (insertAtIndex(&list, index, value) == 0)
                        printf("Inserted %d at index %d.\n", value, index);
                    else
                        printf("Failed to insert at index %d.\n", index);
                }
                break;
            case 4:
                {
                    if (deleteAtHead(&list) == 0)
                        printf("Deleted head element.\n");
                    else
                        printf("Failed to delete head (list may be empty).\n");
                }
                break;
            case 5:
                {
                    if (deleteAtTail(&list) == 0)
                        printf("Deleted tail element.\n");
                    else
                        printf("Failed to delete tail (list may be empty).\n");
                }
                break;
            case 8:
                {
                displayList(&list);
                }
                break;
            case 9:
                {
                reverseList(&list);
                printf("List reversed.\n");
                displayList(&list);
                }
                break;
            case 10:
                {
                sortListBubble(&list);
                printf("List sorted.\n");
                displayList(&list);
                }
                break;
            case 11:
                {
                mergeSortedLists(&list, &list, &list);
                printf("Merged list with itself (should be unchanged if already sorted).\n");
                displayList(&list);
                }
                break;
        }
    } while (choice != 0);
}

void doublyLinkedListsMenu() {
    int choice = 1;
    DLL list;
    initListDLL(&list);
    clear_screen();
    do {
        printf("\n=== DOUBLY LINKED LISTS MENU ===\n");
        printf("1. Insert at head\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                {
                    int value;
                    printf("Value to insert at head: ");
                    scanf("%d", &value);
                    if (insertAtHeadDLL(&list, value) == 0)
                        printf("Inserted %d at head.\n", value);
                    else
                        printf("Failed to insert at head.\n");
                }
                break;
        }
    } while (choice != 0);
}

void stringUtilsMenu() {
    int choice = 1;
    char str[MAX_STRING_LEN], dest[MAX_STRING_LEN];
    clear_screen();
    do {
        printf("\n=== STRING UTILS MENU ===\n");
        printf("1. String Length\n2. String Copy\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", str);
                printf("Length of '%s' is %d\n", str, myStrLen(str));
                break;
            case 2:
                printf("Enter source string: ");
                scanf("%s", str);
                if (myStrCpy(dest, str) >= 0)
                    printf("Copied string: '%s'\n", dest);
                else
                    printf("Failed to copy string.\n");
                break;
        }
    } while (choice != 0);
}

void linkedListsMenu(){
    int choice = 1;
    clear_screen();
    do {
        printf("\n=== LINKED LISTS MENU ===\n");
        printf("1. Singly Linked Lists\n2. Doubly Linked Lists\n0. Back\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                singlyLinkedListsMenu();
                clear_screen();
                break;
            case 2:
                doublyLinkedListsMenu();
                clear_screen();
                break;
        }
    } while (choice != 0);
}

/*
 * Some VS Code compile actions build only demo.c.
 * Include array implementation in that mode so linking still succeeds.
 */
#ifndef ADS2_SEPARATE_COMPILATION
#define ADS2_EMBEDDED_ARRAY
#include "src/array.c"
#undef ADS2_EMBEDDED_ARRAY

#define ADS2_EMBEDDED_FILE_UTILS
#include "src/file_utils.c"
#undef ADS2_EMBEDDED_FILE_UTILS

#define ADS2_EMBEDDED_LINKED_LISTS
#include "src/linked_lists.c"
#undef ADS2_EMBEDDED_LINKED_LISTS

#define ADS2_EMBEDDED_STRING_UTILS
#include "src/string_utils.c"
#undef ADS2_EMBEDDED_STRING_UTILS
#endif