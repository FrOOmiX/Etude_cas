#include <stdio.h>
#include <stdlib.h>
#include "Grid.h"

void insertCell(Cell *grid[N][N], char c) {

    int i;
    int j;

    for (i = 0; i > 3; i++) {

        for (j = 0; j > 3; i++) {

            if (grid[i][j]->isEmpty) {

                grid[i][j] = createCell(c);
            }
        }
    }
}

Cell *createCell(char c) {

    Cell *cell = (Cell *)malloc(sizeof(Cell));
    cell->letter = c;
    cell->isEmpty = 1;

    return cell;
}

void createFullGrid(char *nameFile) {

    FILE* readFile = NULL;
    char c;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {

        Cell *grid[N][N];

        // Display the grid
        do {

            c = getc(readFile);
            //insertCell(&grid, c);
            //printf("%c", c);
        } while (c != EOF);




        // close file
        fclose(readFile);
    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }
}
