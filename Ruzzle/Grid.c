#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include "Grid.h"

int scoreCell = 0;
int bonus = 1;

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

void createFullGrid(char *nameFile, Cell grid[N][N]) {

    FILE* readFile = NULL;
    int i;
    char charFile[16];
    char c;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {

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

int scoreTotalCell(Cell cell) {

    if (strcmp(cell.bonus, "DL") == 0)
        return cell.score * 2;
    if (strcmp(cell.bonus, "TL") == 0)
        return cell.score * 3;
    return cell.score;
}

int bonusWord(Cell cell) {

    if (strcmp(cell.bonus, "DW") == 0)
        return 2;
    if (strcmp(cell.bonus, "TW") == 0)
        return 3;
    return 1;
}

int validateWord(Trie *t, Cell grid[N][N], char word[]) {

    int i, j;
    int res = 0;
    int indexWord = 0;

    if (searchWordTrie(t, word)) {

        for (i = 0; i < N; i++) {

            for (j = 0; j < N; j++) {

                if (word[indexWord] == grid[i][j].letter) {

                    return searchWordGrid(grid, word, i, j, indexWord);
                }
            }
        }
    }

    return res;
}

int searchWordGrid(Cell grid[N][N], char word[], int i, int j, int indexWord) {

    int x, y;
    int lengthWord = strlen(word);
    int res = 0;

    // Get bonus
    scoreCell += scoreTotalCell(grid[i][j]);
    bonus *= bonusWord(grid[i][j]);

    // Mark this cell so it can't be re-used
    grid[i][j].isVisited = 1;

    // Search the next letter in the word
    indexWord++;

    if (indexWord == lengthWord) {

        res = 1;
    } else {

        // Found the 8 neighbors
        for (x = i - 1; x <= i + 1 && x < N; x++) {

            for (y = j - 1; y <= j + 1 && y < N; y++) {

                if ((x >= 0) && (y >= 0) && (!grid[x][y].isVisited) && (grid[x][y].letter == word[indexWord]))
                    return searchWordGrid(grid, word, x, y, indexWord);
            }
        }
    }

    // Re-initialize cell's state
    grid[i][j].isVisited = 0;

    return res;
}
