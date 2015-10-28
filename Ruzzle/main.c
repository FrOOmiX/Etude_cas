#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

#define LOCATION_DICO "./res/txt/dico.txt"

int main(int argc, char *argv[]) {

    // Create Trie with all words (and search a specific word)
    createFullTrie(LOCATION_DICO);

    return 0;
}
