#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"

void initNode(Node *n) {                            // init a Node

    int i;
    for(i = 0; i < 26; i++) {

        n->child[i] = 0;
    }

    n->letter = 0;
}

Trie *createTrie() {                                // Create a new trie and initialize the root

    Trie *t = malloc(sizeof(Trie));
    t->root = malloc(sizeof(Node));
    initNode(t->root);
    return t;
}

int insertNode(Node *n, char *string, int position) {

    unsigned char c = (unsigned char)string[position];

    if (c) {                                        // if string not finished

        if (n->child[c] == 0) {

            n->child[c] = malloc(sizeof(Node));

            if (n->child[c] == NULL) {

                return 0;
            }

            initNode(n);                            // create node
            n->letter = c;
        }

        position++;                                 // increment position in string
        return insertNode(n, string, position);
    } else {                                        // if string finished, everything is okay

        return 1;
    }
}

int searchNode(Node *n, char *string, int position) {

    unsigned char c = (unsigned char)string[position];

    if (c) {                                         // if string not finished

        if (n->child[c]) {

            position++;
            return searchNode(n, string, position);
        } else {

            return 0;                               // char not found
        }
    } else {                                        // string found

        return 1;
    }
}
