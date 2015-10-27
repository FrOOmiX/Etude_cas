#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

Node *createNode() {                                    // create a Node and init his parameters

    Node *n = (Node *)malloc(sizeof(Node));

    if (n) {

        int i;
        n->isEnd = 0;

        for (i = 0; i < 26; i++) {

            n->child[i] = NULL;
        }
    }

    return n;
}

void createTrie(Trie *t) {                              // Create a new trie and init the root

    t->root = createNode();
}

void insertNode(Trie *t, char *string) {

    int i;
    int length = strlen(string);
    Node *temp = t->root;

    for (i = 0; i < length; i++) {

        int indexLetter = string[i] - 'a';              // For each letter, fetch his index

        if (temp->child[indexLetter] == NULL) {          // No child for this letter

            temp->child[indexLetter] = createNode();
        }

        temp = temp->child[indexLetter];                // New temp is the old temp
    }

    temp->isEnd = 1;                                    // Mark last node as leaf
}

int searchNode(Trie *t, char *string) {

    int i;
    int length = strlen(string);
    Node *temp = t->root;

    for (i = 0; i < length; i++) {

        int indexLetter = string[i] - 'a';

        if (temp->child[indexLetter] == NULL) {          // No match

            return 0;
        }

        temp = temp->child[indexLetter];
    }

    return (temp != 0 && temp->isEnd);                  // Temp and isEnd shoud be != 0
}
