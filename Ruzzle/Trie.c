/**
 * \file Trie.c
 * \brief Generate a Trie and search words in it
 * \author RUSIECKI.R, DECHAUME.S, BADENS.R
 * \date 14 decembre 2015
 *
 */

#include "Trie.h"

#define MAX_LENGTH 512

/** \brief Create a Node and initialize his parameters
 *
 * \return Node* : pointers on a Node
 *
 */
Node *createNode() {

    Node *n = (Node *)malloc(sizeof(Node));

    if (n) {

        int i;
        n->isEnd = 0;

        // Each child is initialized
        for (i = 0; i < 26; i++) {

            n->child[i] = NULL;
        }
    }

    return n;
}

/** \brief Create a new Trie and initialize the root
 *
 * \param Trie
 *
 */
void createTrie(Trie *t) {

    t->root = createNode();
}

/** \brief Insert a word in the Trie
 *
 * \param Trie
 * \param char* : a word
 *
 */
void insertNode(Trie *t, char *string) {

    int i;
    int length = strlen(string);
    Node *temp = t->root;

    for (i = 0; i < length; i++) {

        // For each letter, fetch his index
        int indexLetter = string[i] - 'a';

        // If there's no child for this letter
        if (temp->child[indexLetter] == NULL) {

            temp->child[indexLetter] = createNode();
        }

        // New temp is the old temp
        temp = temp->child[indexLetter];
    }

    // Mark last node as a leaf
    temp->isEnd = 1;
}

/** \brief Search a word in the Trie
 *
 * \param Trie
 * \param char* : a word
 * \return int : 1 if the word is in the Trie, 0 instead
 *
 */
int searchNode(Trie *t, char *string) {

    int i;
    int length = strlen(string);
    Node *temp = t->root;

    for (i = 0; i < length; i++) {

        int indexLetter = string[i] - 'a';

        // If there's no child for this letter
        if (temp->child[indexLetter] == NULL) {

            return 0;
        }

        temp = temp->child[indexLetter];
    }

    // Temp and isEnd shoud be != 0
    return (temp != 0 && temp->isEnd);
}

/** \brief Display a message if the word is in the Trie or not
 *
 * \param Trie
 * \param char* : a word
 * \return int : 1 if the word is in the Trie, 0 instead
 *
 */
int searchWordTrie(Trie *t, char *string) {

    int i = searchNode(t, string);
    int res = 0;

    if (i == 1) {
        printf("Word found\n");
        res = 1;
    } else
        printf("Not found\n");

    return res;
}

/** \brief Create the Trie by adding words from a file
 *
 * \param char* : name of the file to be used
 * \param Trie
 *
 */
void createFullTrie(char *nameFile, Trie *t) {

    FILE* readFile = NULL;
    char myString[MAX_LENGTH];
    char *string;

    // Open the file in read-mode
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {

        // Initialize the root
        createTrie(t);

        // Populate the Trie
        while ((string = fgets(myString, MAX_LENGTH, readFile))) {

            // Erase the \n at the end of each word
            int i = strlen(string);
            string[i - 1] = '\0';

            insertNode(t, string);
        }

        // close file
        fclose(readFile);
    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }
}

/** \brief Free the memory for the Trie
 *
 * \param Trie
 *
 */
void destroyTrie(Trie *t) {

    free(t->root);
    free(t);
}
