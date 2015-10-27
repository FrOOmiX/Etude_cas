#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"

#define MAX_LENGTH 512

int main(int argc, char *argv[]) {

    /***** Test de lecture de fichier *****/
    FILE* readFile = NULL;                        // pointeur sur le fichier
    char myString[MAX_LENGTH];
    char *string;

    // open the file (r)
    readFile = fopen("./mots.txt", "r");

    if (readFile != NULL) {

        // Create a new trie
        Trie t;
        createTrie(&t);

        while ((string = fgets(myString, MAX_LENGTH, readFile))) {

            int i = strlen(string);
            string[i - 1] = '\0';

            insertNode(&t, string);
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
