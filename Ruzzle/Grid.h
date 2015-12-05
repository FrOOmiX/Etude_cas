#ifndef _GRID_H
#define _GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

#define N 4

/** Grid representation
 *
 *  DW : Double Word    -> [0][1]
 *  DW : Double Word    -> [0][3]
 *
 *  TW : Triple Word    -> [3][2]
 *
 *  DL : Double Letter  -> [3][1]
 *
 *  TL : Triple Letter  -> [0][2]
 *  TL : Triple Letter  -> [2][2]
 *
 *  .  DW  TL  DW
 *  .   .   .   .
 *  .   .  TL   .
 *  .  DL  TW   .
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
int scoreCell(char c);
void setBonus(Cell grid[N][N]);
void toString(Cell grid[N][N]);
int bonusCell(Cell cell);
int bonusWord(Cell cell);
int bonusLength(int length);
int scoreWord(Trie *t, Cell grid[N][N], int coord[], int i, int j);
int searchWordGrid(Cell grid[N][N], char word[], int x, int y, int indexWord, int bCell, int bWord, int *pScoreWord);

#endif // _GRID_H
