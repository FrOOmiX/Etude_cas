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
    cell.score = scoreCell(c);
    cell.isVisited = 0;
    strcpy(cell.bonus, " ");

    return cell;
}

void setBonus(Cell grid[N][N]) {

    strcpy(grid[0][1].bonus, "DW");
    strcpy(grid[0][3].bonus, "DW");
    strcpy(grid[3][2].bonus, "TW");
    strcpy(grid[3][1].bonus, "DL");
    strcpy(grid[0][2].bonus, "TL");
    strcpy(grid[2][2].bonus, "TL");
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

    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }
}

int scoreCell(char c) {

    int i, score;
    Cell boxScore[26] = {

        {'a', 1}, {'b', 3}, {'c', 3}, {'d', 2},
        {'e', 1}, {'f', 4}, {'g', 2}, {'h', 4},
        {'i', 1}, {'j', 8}, {'k', 10}, {'l', 1},
        {'m', 2}, {'n', 1}, {'o', 1}, {'p', 3},
        {'q', 8}, {'r', 1}, {'s', 1}, {'t', 1},
        {'u', 1}, {'v', 4}, {'w', 10}, {'x', 10},
        {'y', 10}, {'z', 10}
    };

    for (i = 0; i < sizeof(boxScore); i++) {

        if (boxScore[i].letter == c) {

            score = boxScore[i].score;
            break;
        }
    }

    return score;
}

int bonusCell(Cell cell) {

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

int bonusLength(int length) {

    int bonus = 0;

    switch (length) {

        case 5:
            bonus = 5;
            break;
        case 6:
            bonus = 10;
            break;
        case 7:
            bonus = 15;
            break;
        case 8:
            bonus = 20;
            break;
        case 9:
            bonus = 25;
            break;
        case 10:
            bonus = 30;
            break;
        case 11:
            bonus = 35;
            break;
        case 12:
            bonus = 40;
            break;
        case 13:
            bonus = 45;
            break;
        case 14:
            bonus = 50;
            break;
        case 15:
            bonus = 55;
            break;
        case 16:
            bonus = 60;
            break;
        default:
            bonus = 0;
            break;
    }

    return bonus;
}

char *getWordFromCoord(Cell grid[N][N], int coord[17][2]) {

    int i, j, x, y;
    char *word = malloc(16 * sizeof(char));

    for (i = 0; i < 17; i++) {

        for (j = 0; j < 1; j++) {

            if (x == -1) {

                return word;
            } else {

                x = coord[i][j];
                y = coord[i][j+1];
                word[i] = grid[x][y].letter;
            }
        }
    }

    return word;
}

int scoreWord(Trie *t, Cell grid[N][N], int coord[17][2]) {

    int scoreWord = 0;
    int *pScoreWord = &scoreWord;
    char *word = getWordFromCoord(grid, coord);
    int lengthWord = strlen(word);

    if (searchWordTrie(t, word)) {

        searchWordGrid(grid, coord, pScoreWord, lengthWord);
    }

    free(word);

    return *pScoreWord;
}

int searchWordGrid(Cell grid[N][N], int coord[17][2], int *pScoreWord, int lengthWord) {

    int bCell = 0, bWord = 1, x = 0, y = 0, i, j;
    int bLength = bonusLength(lengthWord);

    for (i = 0; i < 17; i++) {

        for (j = 0; j < 1; j++) {

            if (x == -1) {

                return *pScoreWord = bCell * bWord + bLength;

            } else {

                x = coord[i][j];
                y = coord[i][j+1];
                bCell += bonusCell(grid[x][y]);
                bWord *= bonusWord(grid[x][y]);
            }
        }
    }

    return 0;
}
