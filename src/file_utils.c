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

int readRecord(const char* filename, int index, Record* r) {
    FILE* fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        return -1;
    }

    // Move the file pointer to the position of the record we want to read
    // The position is: index multiplied by the size of one Record
    fseek(fp, index * sizeof(Record), SEEK_SET);

    // Read one Record from the file and store it inside r
    // fread returns 1 if it successfully reads one Record
    if (fread(r, sizeof(Record), 1, fp) != 1) {
        fclose(fp);  // Close the file before leaving
        return -1;   // Return -1 because reading failed
    }

    // Close the file after reading
    fclose(fp);

    // Return 0 because the record was read successfully
    return 0;
}

int countRecords(const char* filename) {
    // Open the file in binary read mode
    FILE* fp = fopen(filename, "rb");

    // Check if the file failed to open
    if (fp == NULL) {
        return -1;   // Return -1 if there is an error
    }

    // Move the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    // Get the current position (this is the file size in bytes)
    long size = ftell(fp);

    // Close the file
    fclose(fp);

    // Return number of records (file size divided by size of one Record)
    return size / sizeof(Record);
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

int updateRecord(const char *filename, int index, Record newData) {
    FILE *f = fopen(filename, "r+b");
    if (f == NULL) {
        return -1;
    }

    fseek(f, index * sizeof(Record), SEEK_SET);
    fwrite(&newData, sizeof(Record), 1, f);

    fclose(f);
    return 0;
}

int copyBinaryFile(const char *src, const char *dest) {
    FILE *f_src = fopen(src, "rb");
    if (f_src == NULL) {
        return -1;
    }

    FILE *f_dest = fopen(dest, "wb");
    if (f_dest == NULL) {
        fclose(f_src);
        return -1;
    }

    Record temp;

    while (fread(&temp, sizeof(Record), 1, f_src) == 1) {
        fwrite(&temp, sizeof(Record), 1, f_dest);
    }

    fclose(f_src);
    fclose(f_dest);

    return 0;
}