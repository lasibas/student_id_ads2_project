#include <stdio.h>
#include <stdlib.h>
#include "../include/Dataset_Analysis.h"
#include "../include/file_utils.h"
#include "../include/string_utils.h"


int loadDataset(const char* filename, Record arr[], int* count) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("  Could not open '%s'. Try option 1 first.\n", filename);
        return -1;
    }
    *count = 0;
    while (*count < MAX_1D &&
           fread(&arr[*count], sizeof(Record), 1, fp) == 1)
        (*count)++;
    fclose(fp);
    printf("  Loaded %d records from '%s'.\n", *count, filename);
    return 0;
}