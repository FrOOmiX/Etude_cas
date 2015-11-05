#ifndef _GRID_H
#define _GRID_H

#define N 4

typedef struct sCell {

    char letter;
    int isEmpty;
    struct sCell *neighbors[];
} Cell;

void insertCell(Cell *[N][N], char);
Cell *createCell(char);
void createGrid();
void createFullGrid(char *nameFile);

#endif // _GRID_H
