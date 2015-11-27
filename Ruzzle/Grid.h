#ifndef _GRID_H
#define _GRID_H

#define N 4

/** Grid representation
 *
 *  DW : Double Word    -> [0][1]
 *  TW : Triple Word    -> [3][0]
 *  DL : Double Letter  -> [2][2]
 *  TL : Triple Letter  -> [1][3]
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
    int isVisited;
    char bonus[2];
} Cell;

void createGrid(Cell grid[N][N], char charFile[]);
void initGrid(Cell grid[N][N]);
Cell createCell(char c);
void createFullGrid(char *nameFile, Cell grid[N][N]);
int getScore(char c);
void setBonus(Cell grid[N][N]);
void toString(Cell grid[N][N]);
int scoreTotalCell(Cell cell);
int bonusWord(Cell cell);
int validateWord(Trie *t, Cell grid[N][N], char word[]);
int searchWordGrid(Cell grid[N][N], char word[], int x, int y, int indexWord);

#endif // _GRID_H
