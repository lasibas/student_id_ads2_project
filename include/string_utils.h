#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include "common.h"

int myStrLen(const char* str);
int myStrCpy(char* dest, const char* src);
int myStrNCpy(char* dest, const char* src, size_t n);
int myStrCat(char* dest, const char* src);

#endif // STRING_UTILS_H