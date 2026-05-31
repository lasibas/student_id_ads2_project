#include "Dataset_Analysis.h"

static void clear_screen(void);
static void wait_for_enter(void);

int main(){
    int choice = 1;
    Record arr[MAX_1D];
    int count = 0;
    clear_screen();
    do {
        printf("\n=== DATASET ANALYSIS MENU ===\n");
        printf("1. Load dataset from file\n0. Exit\nChoice: ");
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
                            printf("ID: %d, Name: %s, Note: %.2f\n", arr[i].id, arr[i].name, arr[i].note);
                        }
                    } else {
                        printf("Failed to load dataset from '%s'.\n", filename);
                    }
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

