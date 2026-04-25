#ifndef FILE_UTILS_H
#define FILE_UTILS_H
#include "common.h"

int writeRecord(const char* filename, Record* r);
int createBinaryFile(const char* filename);
int appendRecord(const char* filename, Record* r);
int searchRecordById(const char* filename, int id, Record* result);
#endif // FILE_UTILS_H