#ifndef _TRIE_H
#define _TRIE_H

#define ALPHABET 26

// struc for a node in the trie
typedef struct sNode {

    char letter;
    struct Node *child[ALPHABET];

} Node;

// struc of the trie
typedef struct sTrie {

    Node *root;
} Trie;

void initNode(Trie *);
Node *createNode();
int insertNode(Trie *, char *);
#endif // _TRIE_H
