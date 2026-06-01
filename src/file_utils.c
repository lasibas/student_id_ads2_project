#include "../include/file_utils.h"
#include <stdio.h>

/* Append a single `Record` to a binary file.
 * Parameters: `filename` - path to binary file, `r` - record to write.
 * Returns 0 on success, -1 on failure (open or write error).
 */
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

/* Create or truncate a binary file specified by `filename`.
 * Returns 0 on success, -1 if the file cannot be created.
 */
int createBinaryFile(const char* filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        return -1;
    }

    fclose(fp);
    return 0;
}

/* Read the record at `index` from a binary file into `r`.
 * Returns 0 on success, -1 on error (open or read failure).
 */
int readRecord(const char* filename, int index, Record* r) {
    FILE* fp = fopen(filename, "rb");
    
    if (fp == NULL) {
        return -1;
    }

    /* Seek to the start of the desired record and read one Record */
    fseek(fp, index * sizeof(Record), SEEK_SET);

    if (fread(r, sizeof(Record), 1, fp) != 1) {
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

/* Return the number of `Record` entries in a binary file.
 * Returns record count on success, -1 if file cannot be opened.
 */
int countRecords(const char* filename) {
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);

    return size / sizeof(Record);
}

/* Alias for writing/appending a Record; appends `r` to `filename`.
 * Returns 0 on success, -1 on failure.
 */
int appendRecord(const char* filename, Record* r) {
    FILE* file = fopen(filename, "ab");
    
    if (file == NULL) {
        return -1;
    }
    
    int written = fwrite(r, sizeof(Record), 1, file);
    fclose(file);
    
    return (written == 1) ? 0 : -1;
}

/* Search for a record with `id` in `filename` and copy it into `result`.
 * Returns the zero-based index of the found record, or -1 if not found or on error.
 */
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
    
    return found ? index : -1;
}

/* Overwrite the record at `index` in `filename` with `newData`.
 * Returns 0 on success, -1 on open error.
 */
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

/* Copy a binary file containing `Record` entries from `src` to `dest`.
 * Returns 0 on success, -1 on open error.
 */
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