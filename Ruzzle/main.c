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

    // Create Trie with all words (and search a specific word)
    createFullTrie(LOCATION_DICO, t);

    // Search a word
    //searchWordTrie(t, "soir");

    // Create grid
    createFullGrid(LOCATION_GRIDVALIDATION, grid);

    validateWord(t, grid, "soir");

    //mainDisplay();

    free(t->root);
    free(t);

    return 0;
}
