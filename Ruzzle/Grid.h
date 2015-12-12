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

// Struct for a Cell
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
int bonusCell(Cell cell);
int bonusWord(Cell cell);
int bonusLength(int length);
char *getWordFromCoord(Cell grid[N][N], int coord[17][2]);
int scoreWord(Trie *t, Trie *tGrid, Cell grid[N][N], int coord[17][2]);
int scoreTotal(Cell grid[N][N], int coord[17][2], int *pScoreWord, int lengthWord);

#endif // _GRID_H
