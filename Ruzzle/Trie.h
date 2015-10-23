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

void initNode(Trie *t);
Node *createNode();

#endif // _TRIE_H
