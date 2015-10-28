#ifndef _GRID_H
#define _GRID_H

typedef struct sCell {

    char letter;
    struct sCell *neighbors[];
} Cell;

typedef struct sGrid {

    Cell *root;
} Grid;

#endif // _GRID_H
