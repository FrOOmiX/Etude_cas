#ifndef _GRID_H
#define _GRID_H

#define N 16

/** Grid representation
 *
 *  DW : Double Word    -> [0][1]
 *  TW : Triple Word    -> [1][3]
 *  DL : Double Letter  -> [2][2]
 *  TL : Triple Letter  -> [3][0]
 *
 *  . DW  .  .
 *  .  .  . TL
 *  .  . DL  .
 *  TW .  .  .
 *
 */

typedef struct sCell {

    char letter;
    int score;
    int isEmpty;
    char bonL[2];
    char bonW[2];
} Cell;

void createGrid(Cell grid[N], char charFile[]);
void initGrid(Cell grid[N]);
Cell *createCell(char c);
void createFullGrid(char *nameFile);
int getScore(char c);
void toString(Cell grid[N]);

#endif // _GRID_H
