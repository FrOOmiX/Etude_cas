#include <stdio.h>
#include <stdlib.h>
#include "Grid.h"

createFullGrid(char *nameFile) {

    FILE* readFile = NULL;
    char myString[MAX_LENGTH];
    char *string;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {






        // close file
        fclose(readFile);
    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }
}
