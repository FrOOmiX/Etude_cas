#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

#define MAX_LENGTH 512

int main(int argc, char *argv[]) {

    FILE* readFile = NULL;
    char myString[MAX_LENGTH];
    char *string;

    // open the file (r)
    // There must be a \n at the end of the file
    readFile = fopen("./dico.txt", "r");

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

        if (i == 1) {
            printf("Word found");
        }
        else {
            printf("Not found");
        }

        // close file
        fclose(readFile);
    } else {

        // reading file failed
        printf("File not found");
        exit(1);
    }

    return 0;
}
