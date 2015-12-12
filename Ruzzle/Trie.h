#ifndef _TRIE_H
#define _TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

// Struct for a node in the Trie
typedef struct sNode {

    int isEnd;
    struct sNode *child[ALPHABET];

} Node;

// Struct of the Trie
typedef struct sTrie {

    Node *root;
} Trie;

void createTrie(Trie *t);
Node *createNode();
void insertNode(Trie *t, char *);
int searchNode(Trie *t, char *);
int searchWordTrie(Trie *t, char *);
void createFullTrie(char *, Trie *t);
void destroyTrie(Trie *t);

#endif // _TRIE_H
