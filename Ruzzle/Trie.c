#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

Node *createNode() {                            // create a Node and init his parameters

    Node *n = (Node *)malloc(sizeof(Node));

    if (n) {

        int i;

        for(i = 0; i < 26; i++) {

            n->child[i] = NULL;
        }
    }

    return n;
}

void createTrie(Trie *t) {                      // Create a new trie and init the root

    t->root = createNode();
}

void insertNode(Trie *t, char *string) {

    int i;
    int length = strlen(string);
    Node *temp = t->root;

    for (i = 0; i < length; i++) {

        int letter = string[i] - 'a';
        if (temp->child[letter] == NULL) {

            temp->child[letter] = createNode();
        }

        temp = temp->child[letter];
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
