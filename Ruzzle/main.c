#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include "Grid.h"
#include "interfaces.h"

#define LOCATION_DICO "./res/txt/dico.txt"
#define LOCATION_GRID "./res/txt/grille.txt"
#define LOCATION_GRIDVALIDATION "./res/txt/grille_validation.txt"

int main(int argc, char* argv[]) {

    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);

    Trie *t = (Trie*)malloc(sizeof(Trie));
    Cell grid[N][N];

    // Create Trie with words from file
    createFullTrie(LOCATION_DICO, t);

    // Create grid
    createFullGrid(LOCATION_GRID, grid);

    // Validate or not the word in the grid
    int result = scoreWord(t, grid, "vecurent", 2, 0);
    printf("\nScore : %d", result);

    //mainDisplay();

    free(t->root);
    free(t);

    return 0;
}
