#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include "Grid.h"

void createGrid(Cell grid[N][N], char charFile[]) {

    int i, j;
    int x = 0;

    for (i = 0; i < N; i++) {

        for (j = 0; j < N; j++) {

            grid[i][j] = createCell(charFile[x]);
            x++;
        }
    }
}

void initGrid(Cell grid[N][N]) {

    int i, j;

    for (i = 0; i < N; i++) {

        for (j = 0; j < N; j++) {

            grid[i][j].letter = ' ';
            grid[i][j].score = 0;
            grid[i][j].isVisited = 0;
        }
    }
}

Cell createCell(char c) {

    Cell cell;
    cell.letter = c;
    cell.score = getScore(c);
    cell.isVisited = 0;
    strcpy(cell.bonus, " ");

    return cell;
}

void setBonus(Cell grid[N][N]) {

    strcpy(grid[0][1].bonus, "DW");
    strcpy(grid[3][0].bonus, "TW");
    strcpy(grid[2][2].bonus, "DL");
    strcpy(grid[1][3].bonus, "TL");
}

void createFullGrid(char *nameFile) {

    FILE* readFile = NULL;
    int i;
    char charFile[16];
    char c;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {

        Cell grid[N][N];
        i = 0;

        do {

            c = getc(readFile);

            if (c != '\n') {

                charFile[i] = c;
                i++;
            }
        } while (c != EOF);

        // close file
        fclose(readFile);

        initGrid(grid);
        createGrid(grid, charFile);
        setBonus(grid);
        toString(grid);

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
        {'q', 6}, {'r', 1}, {'s', 1}, {'t', 1},
        {'u', 2}, {'v', 4}, {'w', 15}, {'x', 10},
        {'y', 10}, {'z', 4}
    };

    for (i = 0; i < sizeof(boxScore); i++) {

        if (boxScore[i].letter == c) {

            score = boxScore[i].score;
            break;
        }
    }

    return score;
}

void toString(Cell grid[N][N]) {

    int i, j;

    for (i = 0; i < N; i++) {

        for (j = 0; j < N; j++) {

            printf("%c - score : %d - bonus : %s - isVisited : %d\n", grid[i][j].letter, grid[i][j].score, grid[i][j].bonus, grid[i][j].isVisited);
        }
    }
}

int searchWordGrid(Trie *t, Cell grid[N][N], char word[]) {

    int i, j;

    if (searchWord(t, word)) {




    }

    return 0;
}


for (i = 0; i < N; i++) {

            for (j = 0; j < N; j++) {

                if (word[0] == grid[i][j].letter && !grid[i][j].isVisited) {

                    // the first letter of the word is in the grid
                    grid[i][j].isVisited = 1;
                }
            }
        }
