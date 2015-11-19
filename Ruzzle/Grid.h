#ifndef _GRID_H
#define _GRID_H

#define N 16

/** Grid representation
 *
 *  DW : Double Word    -> [1]
 *  TW : Triple Word    -> [7]
 *  DL : Double Letter  -> [10]
 *  TL : Triple Letter  -> [12]
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
    char bonus[2];
} Cell;

void createGrid(Cell grid[N], char charFile[]);
void initGrid(Cell grid[N]);
Cell createCell(char c);
void createFullGrid(char *nameFile);
int getScore(char c);
void setBonus(Cell grid[N]);
void toString(Cell grid[N]);

#endif // _GRID_H
