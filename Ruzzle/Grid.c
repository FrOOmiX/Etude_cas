#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grid.h"

void createGrid(Cell (*grid)[N], char charFile[]) {

    int i;

    for (i = 0; i < N; i++) {

        //grid[i] = createCell(charFile[i]);
    }
}

void initGrid(Cell grid[N]) {

    int i;

    for (i = 0; i < N; i++) {

        grid[i].letter = ' ';
        grid[i].score = 0;
        grid[i].isEmpty = 0;
        strcpy(grid[i].bonL, "  ");
        strcpy(grid[i].bonW, "  ");
    }

    // Set bonuses
    strcpy(grid[1].bonW, "DW");
    strcpy(grid[7].bonW, "TW");
    strcpy(grid[10].bonL, "DL");
    strcpy(grid[12].bonL, "TL");
}

Cell *createCell(char c) {

    Cell *cell = (Cell*)malloc(sizeof(Cell));
    cell->letter = c;
    cell->score = getScore(c);
    cell->isEmpty = 1;

    return cell;
}

void createFullGrid(char *nameFile) {

    FILE* readFile = NULL;
    //int i;
    // char charFile[16];
    //char c;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {

        Cell grid[N];
        //i = 0;

        /*
        do {

            c = getc(readFile);

            if (c != '\n') {

                charFile[i] = c;
                i++;
            }
        } while (c != EOF);
        */

        initGrid(grid);
        //createGrid(grid, charFile);
        //toString(grid);

        // close file
        fclose(readFile);
    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }
}

int getScore(char c) {

    int i, score;
    Cell boxScore[26] = {

        {'a', 1}, {'b', 3}, {'c', 2}, {'d', 2},
        {'e', 1}, {'f', 3}, {'g', 3}, {'h', 3},
        {'i', 1}, {'j', 10}, {'k', 12}, {'l', 2},
        {'m', 2}, {'n', 1}, {'o', 2}, {'p', 2},
        {'q', 6}, {'r', 1},{'s', 1}, {'t', 1},
        {'u', 2}, {'v', 4}, {'w', 15}, {'x', 10},
        {'y', 10}, {'z', 4}
    };

    for (i = 0; i < sizeof(boxScore); i++) {

        if (boxScore[i].letter == c) {

            score = boxScore[i].score;
        }
    }

    return score;
}

void toString(Cell (*grid)[N]) {

    int i;

    for (i = 0; i < N; i++) {

        printf("%c - score : %d", grid[i]->letter, grid[i]->score);
    }
}
