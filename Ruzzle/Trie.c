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

    if(c) {

        if(0 == t->root->child[c]) {

            t->root->child[c] = malloc(sizeof(Node));

            if(0 == t->root->child[c])
                return 0;

            initNode(t);

        }

        position++;
        return insertNode(t, &c);
    } else {


    }
}

