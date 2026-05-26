#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

int myStrLen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int myStrCpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // null-terminate the destination string
    return i; // return length of copied string
}

int myStrNCpy(char* dest, const char* src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; // null-terminate the destination string
    return i; // return length of copied string
}

int myStrCat(char* dest, const char* src) {
    int destLen = myStrLen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0'; // null-terminate the destination string
    return destLen + i; // return length of concatenated string
}