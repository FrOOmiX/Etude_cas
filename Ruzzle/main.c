#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include "Grid.h"

#define LOCATION_DICO "./res/txt/dico.txt"
#define LOCATION_GRID "./res/txt/grille.txt"

int main(int argc, char *argv[]) {

    // Create Trie with all words (and search a specific word)
    createFullTrie(LOCATION_DICO);

    // Create grid
    createFullGrid(LOCATION_GRID);

    return 0;
}
