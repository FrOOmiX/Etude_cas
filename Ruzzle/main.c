#include <stdio.h>
#include <stdlib.h>
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
        Trie *t = createTrie();

        /*do {

            string = fgets(myString, MAX_LENGTH, readFile);
            insertNode(t->root, string, 0);
            //printf(string);
        } while (*string != EOF);
        */

        while ((string = fgets(myString, MAX_LENGTH, readFile))) {

            insertNode(t->root, string, 0);
        }

        if (searchNode(t->root, "page", 0)) {

            printf("Le mot a ete trouve");
        } else {

            printf("Le mot pas trouve");
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
