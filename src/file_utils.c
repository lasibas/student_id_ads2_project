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

int appendRecord(const char* filename, Record* r) {
    FILE* file = fopen(filename, "ab");
    
    if (file == NULL) {
        return -1;
    }
    
    int written = fwrite(r, sizeof(Record), 1, file);
    fclose(file);
    
    if (written == 1) {
        return 0;
    } else {
        return -1;
    }
}

int searchRecordById(const char* filename, int id, Record* result) {
    FILE* file = fopen(filename, "rb");
    
    if (file == NULL) {
        return -1;
    }
    
    Record temp;
    int index = 0;
    int found = 0;
    
    while (fread(&temp, sizeof(Record), 1, file) == 1) {
        if (temp.id == id) {
            *result = temp;
            found = 1;
            break;
        }
        index++;
    }
    
    fclose(file);
    
    if (found == 1) {
        return index;
    } else {
        return -1;
    }
}