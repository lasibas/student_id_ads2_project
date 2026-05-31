#ifndef DATASET_ANALYSIS_H
#define DATASET_ANALYSIS_H
#include "common.h"

int loadDataset(const char* filename, Record arr[], int* count);
void displayDataset(Record arr[], int count);
void sortDatasetByField(Record arr[], int count, char *field);
int filterByCategory(Record arr[], int count, const char* category, Record result[], int maxResults);
int saveBinaryReport(const char* filename, Record arr[], int count);
#endif // DATASET_ANALYSIS_H