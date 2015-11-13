#ifndef _TRIE_H
#define _TRIE_H

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

void createTrie(Trie *);
Node *createNode();
void insertNode(Trie *, char *);
int searchNode(Trie *, char *);
int searchWord(Trie *, char *);
void createFullTrie(char *, Trie *);

#endif // _TRIE_H
