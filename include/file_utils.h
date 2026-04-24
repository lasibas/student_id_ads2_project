#ifndef FILE_UTILS_H
#define FILE_UTILS_H
#include "common.h"

int writeRecord(const char* filename, Record* r);
int createBinaryFile(const char* filename);
#endif // FILE_UTILS_H