#ifndef STRING_UTILS_H
#define STRING_UTILS_H
#include "common.h"

int myStrLen(const char* str);
int myStrCpy(char* dest, const char* src);
int myStrNCpy(char* dest, const char* src, size_t n);
int myStrCat(char* dest, const char* src);
int countWords(const char* s);
void substring(const char* src, int start, int len, char* dest);
int isPalindrome(const char* s);
char toLower(char c);
int compareIgnoreCase(const char* a, const char* b);
void removeSpaces(char *s);
void removeChar(char *s, char c);

#endif // STRING_UTILS_H