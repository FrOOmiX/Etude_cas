#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"

void initNode(Trie *t) {

    t->root = createNode();
}

Node *createNode() {

    Node *pNode = NULL;

    pNode = (Node *)malloc(sizeof(Node));

    if(pNode) {

        int i;

        pNode->letter = 0;

        for(i = 0; i < ALPHABET; i++) {

            pNode->child[i] = NULL;
        }
    }

    return pNode;
}

int insertNode(Trie *t, unsigned char *string) {

    int position = 0;
    unsigned char c = (unsigned char)string[position];

    if(c) {                                         // if string not finished

        if(t->root->child[c] == 0) {                // if no child, create node

            t->root->child[c] = malloc(sizeof(Node));

            if(t->root->child[c] == 0) {

                return 0;
            }

            initNode(t);                            // create node
        }

        position++;                                 // incremente position in string
        return insertNode(t, &c);
    } else {                                        // if string finished, everything is okay

        return 1;
    }
}

