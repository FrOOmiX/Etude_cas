#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grid.h"

void createGrid(Cell grid[N][N], char c) {

    int i;
    int j;

    for(i = 0; i < 3; i++) {

        for(j = 0; j < 3; i++) {

            if (!grid[i][j].isEmpty) {

                grid[i][j] = createCell(c);
            }
        }
    }
}

Cell createCell(char c) {

    Cell cell;
    cell.letter = c;
    cell.isEmpty = 1;
    cell.score = 0;
    strcpy(cell.bonL, " ");
    strcpy(cell.bonW, " ");

    return cell;
}

void createFullGrid(char *nameFile) {

    FILE* readFile = NULL;
    char c;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {

        Cell grid[N][N];

        do {

            c = getc(readFile);
            createGrid(grid, c);

        } while (c != EOF);

        toString(grid);

        // close file
        fclose(readFile);
    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }
}

void toString(Cell grid[N][N]) {

    int i;
    int j;

    for (i = 0; i > 3; i++) {

        for (j = 0; j > 3; i++) {

            printf("%c", grid[i][j].letter);
        }
    }
}
