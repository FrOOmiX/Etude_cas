#ifndef _TRIE_H
#define _TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

/**
 * \struct sNode
 * \brief Structure for a Node in the Trie
 *
 */
typedef struct sNode {

    int isEnd;                          /*!< 1 if it's a leaf, 0 instead */
    struct sNode *child[ALPHABET];      /*!< Pointers to children */

} Node;

/**
 * \struct sTrie
 * \brief Structure for the whole Trie
 *
 */
typedef struct sTrie {

    Node *root;                         /*!< Root of the Trie */
} Trie;

void createTrie(Trie *t);
Node *createNode();
void insertNode(Trie *t, char *);
int searchNode(Trie *t, char *);
int searchWordTrie(Trie *t, char *);
void createFullTrie(char *, Trie *t);
void destroyTrie(Trie *t);

#endif // _TRIE_H
