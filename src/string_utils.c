#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

/* Return length of C-string `str` (number of chars before null byte).
 * Equivalent to `strlen` from the standard library.
 */
int myStrLen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

/* Copy NUL-terminated `src` into `dest`. Returns number of characters copied.
 * `dest` must have enough space for the copy.
 */
int myStrCpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;
}

/* Copy up to `n` characters from `src` into `dest`, NUL-terminating.
 * Returns number of characters copied (not counting terminating NUL).
 */
int myStrNCpy(char* dest, const char* src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return i;
}

/* Compare two strings lexicographically.
 * Returns negative/0/positive like `strcmp`.
 */
int my_strcmp(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return (unsigned char)a[i] - (unsigned char)b[i];
        i++;
    }
    return (unsigned char)a[i] - (unsigned char)b[i];
}

/* Compare up to `n` characters of two strings.
 * Returns 0 if equal for first `n` chars, otherwise negative/positive.
 */
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

/* Append `src` to `dest`. `dest` must have enough space.
 * Returns new length of `dest` after concatenation.
 */
int myStrCat(char* dest, const char* src) {
    int destLen = myStrLen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
    return destLen + i;
}

/* Count words in a string separated by whitespace (space, tab, newline).
 * Returns the word count.
 */
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

/* Check if string `s` is a palindrome (case-sensitive).
 * Returns 1 if palindrome, 0 otherwise.
 */
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

/* Copy a substring of `src` starting at `start` of length `len` into `dest`.
 * If requested range is out of bounds dest is set to empty string.
 */
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

/* Convert string `s` to uppercase in-place.
 */
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

/* Convert ASCII letter `c` to lowercase; non-uppercase return unchanged.
 */
char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

/* Reverse string `s` in-place.
 */
void reverseString(char* s) {
    int i = 0;
    int j = myStrLen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i]      = s[j];
        s[j]      = temp;
        i++;
        j--;
    }
}
 
/* Count vowels (a, e, i, o, u) in string `s` (case-insensitive).
 */
int countVowels(const char* s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = (char)toLower((unsigned char)s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}

/* Lexicographic comparison ignoring ASCII case.
 * Returns negative/zero/positive like `strcmp`.
 */
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

/* Remove spaces and tabs from `s` in-place.
 */
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

/* Remove all occurrences of character `c` from `s` in-place.
 */
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



