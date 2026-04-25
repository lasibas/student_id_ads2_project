#ifndef FILE_UTILS_H
#define FILE_UTILS_H
#include "common.h"

int writeRecord(const char* filename, Record* r);
int createBinaryFile(const char* filename);
int readRecord(const char* filename, int index, Record* r);
int countRecords(const char* filename);
int appendRecord(const char* filename, Record* r);
int searchRecordById(const char* filename, int id, Record* result);
int updateRecord(const char *filename, int index, Record newData);
int copyBinaryFile(const char *src, const char *dest);
#endif // FILE_UTILS_H