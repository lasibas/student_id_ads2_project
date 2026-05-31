#include <stdio.h>
#include <stdlib.h>
#include "../include/Dataset_Analysis.h"

static void clear_screen(void);

int main(){
    int choice = 1;
    Record arr[MAX_1D];
    int count = 0;
    clear_screen();
    do {
        printf("\n=== DATASET ANALYSIS MENU ===\n");
        printf("1. Load dataset from file\n2. Display dataset\n3. Sort dataset by field\n4. Filter by category\n5. Save binary report\n0. Exit\nChoice: ");
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
                    char category[50];
                    printf("Enter category to filter by: ");
                    scanf("%s", category);
                    Record filtered[MAX_1D];
                    int filtered_count = filterByCategory(arr, count, category, filtered, MAX_1D);
                    if (filtered_count > 0) {
                        printf("Filtered records for category '%s':\n", category);
                        displayDataset(filtered, filtered_count);
                    } else {
                        printf("No records found for category '%s'.\n", category);
                    }
                } else {
                    printf("No dataset to filter.\n");
                }
                break;
            case 5:
                if (count > 0) {
                    char filename[100];
                    printf("Enter filename to save binary report: ");
                    scanf("%s", filename);
                    saveBinaryReport(filename, arr, count);
                } else {
                    printf("No dataset to save.\n");
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
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

