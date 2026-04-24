#include "../include/file_utils.h"
#include <stdio.h>

int writeRecord(const char* filename, Record* r) {
    FILE *fp = fopen(filename, "ab");

    if (fp == NULL) {
        return -1;
    }

    if (fwrite(r, sizeof(Record), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

int createBinaryFile(const char* filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        return -1;
    }

    fclose(fp);
    return 0;
}