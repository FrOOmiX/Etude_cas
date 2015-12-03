#ifndef _TRIE_H
#define _TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

// struct for a node in the trie
typedef struct sNode {

    int isEnd;                                  // if 1, node is a leaf
    struct sNode *child[ALPHABET];              // pointer to every child

} Node;

// struct of the trie
typedef struct sTrie {

    Node *root;
} Trie;

void createTrie(Trie *t);
Node *createNode();
void insertNode(Trie *t, char *);
int searchNode(Trie *t, char *);
int searchWordTrie(Trie *t, char *);
void createFullTrie(char *, Trie *t);

#endif // _TRIE_H
