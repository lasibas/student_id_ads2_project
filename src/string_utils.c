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

int my_strcmp(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return (unsigned char)a[i] - (unsigned char)b[i];
        i++;
    }
    return (unsigned char)a[i] - (unsigned char)b[i];
}

int my_strncmp(const char* a, const char* b, int n) {
    int i = 0;
    while (i < n && a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return (unsigned char)a[i] - (unsigned char)b[i];
        i++;
    }
    if (i == n)
        return 0;
    return (unsigned char)a[i] - (unsigned char)b[i];
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

int countWords(const char* s)
{
    int count = 0;
    int inWord = 0;

    while (*s)
    {
        if (*s != ' ' && *s != '\t' && *s != '\n')
        {
            if (!inWord)
            {
                inWord = 1;
                count++;
            }
        }
        else
        {
            inWord = 0;
        }

        s++;
    }

    return count;
}

int isPalindrome(const char* s)
{
    int j = 0;
    while (s[j] != '\0')
        j++;
    j--;

    int i = 0;

    while (i < j)
    {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }

    return 1;
}

void substring(const char* src, int start, int len, char* dest) {
    int srcLen = strlen(src);
    
    if (start + len > srcLen) {
        dest[0] = '\0';
        return;
    }

    
    int i;
    for (i = 0; i < len; i++) {
        dest[i] = src[start + i];
    }

    dest[len] = '\0';
}

// Convert string to uppercase
void toUpperCase(char* s)
{
    int i = 0;

    // loop until end of string
    while(s[i] != '\0')
    {
        // if character is lowercase letter
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            // convert to uppercase using ASCII
            s[i] = s[i] - 32;
        }

        i++;
    }
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int compareIgnoreCase(const char* a, const char* b) {
    while (*a != '\0' && *b != '\0') {
        char ca = toLower(*a);
        char cb = toLower(*b);

        if (ca != cb)
            return ca - cb; 
        a++;
        b++;
    }

    return toLower(*a) - toLower(*b);
}

void removeSpaces(char *s)
{
    int i, j = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] != ' ' && s[i] != '\t')
        {
            s[j] = s[i];
            j++;
        }
    }

    s[j] = '\0';
}

void removeChar(char *s, char c)
{
    int i, j = 0;

    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] != c)
        {
            s[j] = s[i];
            j++;
        }
    }

    s[j] = '\0';
}



