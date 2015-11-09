#ifndef _GRID_H
#define _GRID_H

#define N 4

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
    int isEmpty;
    int score;
    char bonL[2];
    char bonW[2];
} Cell;

void createGrid(Cell grid[N][N], char c);
Cell createCell(char c);
void createFullGrid(char *nameFile);
void toString(Cell grid[N][N]);

#endif // _GRID_H