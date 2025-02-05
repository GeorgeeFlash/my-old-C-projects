/*
* A program from online to delete a record from a binary file
* https://www.codingunit.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char *name;
    int code;
    int number;
};

int createBinFile(char *fname) {
    FILE *fp;
    struct person newrecord;

    // Open for binary writing
    fp = fopen(fname, "wb");
    if (!fp) {
        printf("Unable to open file!");
        return -1;
    }

    // Just write three records, so we have
    // something to play with.
    // do this with a loop and/or user input!

    newrecord.name = "aaa bbbb";
    newrecord.code = 12345;
    newrecord.number = 1;
    fwrite(&newrecord, sizeof(struct person), 1, fp);

    newrecord.name = "cc ddd";
    newrecord.code = 1234578;
    newrecord.number = 2;
    fwrite(&newrecord, sizeof(struct person), 1, fp);

    newrecord.name = "eeee ffffff";
    newrecord.code = 123456;
    newrecord.number = 3;
    fwrite(&newrecord, sizeof(struct person), 1, fp);

    fclose(fp);
    return 0;
}

int readBinFile(char *fname) {
    FILE *fp;
    struct person myrecord;

    fp = fopen(fname, "rb");
    if(!fp) {
        printf("Unable to open file!");
        return -1;
    }

    printf("The following records are in the binary file %s:\n", fname);

    while (fread(&myrecord, sizeof(struct person), 1, fp)) {
        printf("Name: %s\n", myrecord.name);
        printf("Code: %d\n", myrecord.code);
        printf("Number: %d\n\n", myrecord.number);
    }

    fclose(fp);
    return 0;
}

int deleteRecordByName(char *fname, char *searchname) {
    FILE *fp;
    FILE *fp_temp;
    int found = 0;
    struct person myrecord;

    fp = fopen(fname, "rb");
    if (!fp) {
        printf("Unable to open file %s", fname);
        return -1;
    }

    fp_temp = fopen("tmp.bin", "wb");
    if (!fp_temp) {
        printf("Unable to open file temp file.");
        return -1;
    }

    while(fread(&myrecord, sizeof(struct person), 1, fp)) {
        if(strcmp(searchname, myrecord.name) == 0) {
            printf("A record with requested name found and deleted.\n\n");
            found = 1;
        } else {
            fwrite(&myrecord, sizeof(struct person), 1, fp_temp);
        }
    }

    if(!found) {
        printf("No record(s) found with the requested name: %s\n\n", searchname);
    }

    fclose(fp);
    fclose(fp_temp);

    remove(fname);
    rename("tmp.bin", fname);

    return 0;
}

int main() {
    int result, errno;

    // Setup a new file on each run.

    result = createBinFile("test.bin");
    if(result == -1) {
        perror("Error creating bin file!");
        exit(1);
    }

    result = readBinFile("test.bin");
    if(result == -1) {
        perror("Error reading bin file!");
        exit(1);
    }

    result = deleteRecordByName("test.bin", "cc ddd");
    if(result == -1) {
        perror("Error deleting record!");
        exit(1);
    }

    result = readBinFile("test.bin");
    if(result == -1) {
        perror("Error reading bin file!");
        exit(1);
    }

    return 0;
}