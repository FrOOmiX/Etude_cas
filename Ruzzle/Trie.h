#ifndef _TRIE_H
#define _TRIE_H

#define ALPHABET 26

// struct for a node in the trie
typedef struct sNode {

    char letter;
    struct sNode *child[ALPHABET];

} Node;

// struct of the trie
typedef struct sTrie {

    Node *root;
} Trie;

void createTrie(Trie *);
Node *createNode();
void insertNode(Trie *, char *);
int searchNode(Node *, char *, int);

#endif // _TRIE_H
