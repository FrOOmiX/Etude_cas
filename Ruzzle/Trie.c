#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

#define MAX_LENGTH 512

Node *createNode() {                                    // create a Node and init his parameters

    Node *n = (Node *)malloc(sizeof(Node));

    if (n) {

        int i;
        n->isEnd = 0;

        for (i = 0; i < 26; i++) {

            n->child[i] = NULL;
        }
    }

    return n;
}

void createTrie(Trie *t) {                              // Create a new trie and init the root

    t->root = createNode();
}

void insertNode(Trie *t, char *string) {

    int i;
    int length = strlen(string);
    Node *temp = t->root;

    for (i = 0; i < length; i++) {

        int indexLetter = string[i] - 'a';              // For each letter, fetch his index

        if (temp->child[indexLetter] == NULL) {          // No child for this letter

            temp->child[indexLetter] = createNode();
        }

        temp = temp->child[indexLetter];                // New temp is the old temp
    }

    temp->isEnd = 1;                                    // Mark last node as leaf
}

int searchNode(Trie *t, char *string) {

    int i;
    int length = strlen(string);
    Node *temp = t->root;

    for (i = 0; i < length; i++) {

        int indexLetter = string[i] - 'a';

        if (temp->child[indexLetter] == NULL) {          // No match

            return 0;
        }

        temp = temp->child[indexLetter];
    }

    return (temp != 0 && temp->isEnd);                  // Temp and isEnd shoud be != 0
}

void createFullTrie(char *nameFile) {

    FILE* readFile = NULL;
    char myString[MAX_LENGTH];
    char *string;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen(nameFile, "r");

    if (readFile != NULL) {

        // Create a new trie
        Trie t;
        createTrie(&t);

        // Populate the Trie
        while ((string = fgets(myString, MAX_LENGTH, readFile))) {

            // Erase the \n at the end of each word
            int i = strlen(string);
            string[i - 1] = '\0';

            insertNode(&t, string);
        }

        // Search for a word
        int i = searchNode(&t, "zwinglianismes");

        if (i == 1)
            printf("Word found");
        else
            printf("Not found");

        // close file
        fclose(readFile);
    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }
}
