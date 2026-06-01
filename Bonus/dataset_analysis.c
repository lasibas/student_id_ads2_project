#include <stdio.h>
#include <stdlib.h>
#include "../include/Dataset_Analysis.h"

static void clear_screen(void);

/*
 * When compiling this file directly (without the project's Makefile),
 * the helper/source implementations may not be linked. If the build
 * does not define `ADS2_SEPARATE_COMPILATION`, include the source
 * files here so the file can compile standalone for quick testing.
 */
#ifndef ADS2_SEPARATE_COMPILATION
#include "../src/Dataset_Analysis_Header_Code.c"
#include "../src/file_utils.c"
#include "../src/string_utils.c"
#endif

int main(){
    int choice = 1;
    Record arr[MAX_1D];
    int count = 0;
    clear_screen();
    do {
        printf("\n=== DATASET ANALYSIS MENU ===\n");
        printf("1. Load dataset from file\n2. Display dataset\n3. Sort dataset by field\n4. Find minimum by field\n5. Find maximum by field\n6. Calculate average by field\n7. Filter by category\n8. Save binary report\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) <= 0) break;
        switch(choice) {
            case 1:
                {
                    char filename[100];
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    if (loadDataset(filename, arr, &count) == 0) {
                        printf("Dataset loaded successfully. Records:\n");
                        for (int i = 0; i < count; i++) {
                            printf("ID: %d, Name: %s, Score: %.2f, Category: %s\n", arr[i].id, arr[i].name, arr[i].score, arr[i].category);
                        }
                    } else {
                        printf("Failed to load dataset from '%s'.\n", filename);
                    }
                }
                break;
            case 2:
                if (count > 0) {
                    displayDataset(arr, count);
                } else {
                    printf("No dataset to display.\n");
                }
                break;
            case 3:
                if (count > 0) {
                    char field[50];
                    printf("Enter field to sort by (id, name, score): ");
                    scanf("%s", field);
                    sortDatasetByField(arr, count, field);
                    printf("Dataset sorted by %s.\n", field);
                } else {
                    printf("No dataset to sort.\n");
                }
                break;
            case 4:
                if (count > 0) {
                    char field[50];
                    printf("Enter field to find minimum (id, name, score): ");
                    scanf("%s", field);
                    Record min = findMinByField(arr, count, field);
                    printf("Minimum by %s: ID: %d, Name: %s, Score: %.2f, Category: %s\n", field, min.id, min.name, min.score, min.category);
                } else {
                    printf("No dataset to analyze.\n");
                }
                break;
            case 5:
                if (count > 0) {
                    char field[50];
                    printf("Enter field to find maximum (id, name, score): ");
                    scanf("%s", field);
                    Record max = findMaxByField(arr, count, field);
                    printf("Maximum by %s: ID: %d, Name: %s, Score: %.2f, Category: %s\n", field, max.id, max.name, max.score, max.category);
                } else {
                    printf("No dataset to analyze.\n");
                }
                break;
            case 6:
                if (count > 0) {
                    char field[50];
                    printf("Enter field to calculate average (score): ");
                    scanf("%s", field);
                    float avg = averageByField(arr, count, field);
                    printf("Average by %s: %.2f\n", field, avg);
                } else {
                    printf("No dataset to analyze.\n");
                }
                break;
            case 7:
                if (count > 0) {
                    char category[50];
                    printf("Enter category to filter by: ");
                    scanf("%s", category);
                    Record filtered[MAX_1D];
                    int filteredCount = filterByCategory(arr, count, category, filtered, MAX_1D);
                    printf("Records in category '%s':\n", category);
                    for (int i = 0; i < filteredCount; i++) {
                        printf("ID: %d, Name: %s, Score: %.2f, Category: %s\n", filtered[i].id, filtered[i].name, filtered[i].score, filtered[i].category);
                    }
                } else {
                    printf("No dataset to filter.\n");
                }
                break;
            case 8:
                if (count > 0) {
                    char filename[100];
                    printf("Enter filename to save binary report: ");
                    scanf("%s", filename);
                    if (saveBinaryReport(filename, arr, count) == 0) {
                        printf("Binary report saved to '%s' successfully.\n", filename);
                    } else {
                        printf("Failed to save binary report to '%s'.\n", filename);
                    }
                } else {
                    printf("No dataset to save.\n");
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
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

