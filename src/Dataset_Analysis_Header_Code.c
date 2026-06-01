#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void displayDataset(Record arr[], int count)
{
    int i;

    // Print table header (column names)
    printf("ID\tNAME\t\tSCORE\tCATEGORY\n");

    // Print a separator line for better readability
    printf("-----------------------------------------\n");

    // Loop through all records in the array
    for(i = 0; i < count; i++)
    {
        // Print each record with formatted columns
        // %-5d   → left aligned integer (id)
        // %-15s  → left aligned string (name)
        // %-7.2f → float with 2 decimals (score)
        // %-10s  → left aligned string (category)
        printf("%-5d %-15s %-7.2f %-10s\n",
               arr[i].id,        // student/product/employee id
               arr[i].name,      // name field
               arr[i].score,     // numeric value (score/price/salary)
               arr[i].category); // category or department
    }
}

void sortDatasetByField(Record arr[], int count, char *field)
{
    int i, j;
    Record temp;

    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            int swap = 0;

            if (strcmp(field, "id") == 0)
            {
                if (arr[j].id > arr[j + 1].id)
                    swap = 1;
            }
            else if (strcmp(field, "score") == 0)
            {
                if (arr[j].score > arr[j + 1].score)
                    swap = 1;
            }
            else if (strcmp(field, "name") == 0)
            {
                if (strcmp(arr[j].name, arr[j + 1].name) > 0)
                    swap = 1;
            }

            if (swap)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

Record findMinByField(Record arr[], int count, char *field)
{
    Record min = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (strcmp(field, "id") == 0)
        {
            if (arr[i].id < min.id)
                min = arr[i];
        }
        else if (strcmp(field, "score") == 0)
        {
            if (arr[i].score < min.score)
                min = arr[i];
        }
        else if (strcmp(field, "name") == 0)
        {
            if (strcmp(arr[i].name, min.name) < 0)
                min = arr[i];
        }
    }
    return min;
}

Record findMaxByField(Record arr[], int count, char *field)
{
    Record max = arr[0];
    for (int i = 1; i < count; i++)
    {
        if (strcmp(field, "id") == 0)
        {
            if (arr[i].id > max.id)
                max = arr[i];
        }
        else if (strcmp(field, "score") == 0)
        {
            if (arr[i].score > max.score)
                max = arr[i];
        }
        else if (strcmp(field, "name") == 0)
        {
            if (strcmp(arr[i].name, max.name) > 0)
                max = arr[i];
        }
    }
    return max;
}

float averageByField(Record arr[], int count, char *field)
{
    float sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(field, "score") == 0)
        {
            sum += arr[i].score;
        }
    }
    return (count > 0) ? (sum / count) : 0.0;
}

int filterByCategory(Record arr[], int count, const char* category, Record result[], int maxResults) {
    int matched = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(arr[i].category, category) == 0) {
            if (matched < maxResults) {
                result[matched++] = arr[i];
            } else {
                break;
            }
        }
    }
    return matched;
}

int saveBinaryReport(const char* filename, Record arr[], int count) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("  Could not open '%s' for writing.\n", filename);
        return -1;
    }
    fwrite(arr, sizeof(Record), count, fp);
    fclose(fp);
    printf("  Report saved to '%s' with %d records.\n", filename, count);
    return 0;
}
