#include <stdio.h>
#include <stdlib.h>
#include "Trie.h"


int main(int argc, char *argv[]) {

    /***** Test de lecture de fichier *****/
    FILE* readFile = NULL;                        // pointeur sur le fichier
    char myString[100];

    // open the file (r)
    readFile = fopen("./dico.txt", "r");

    if (readFile != NULL) {

        // Create a new trie
        Trie t;
        initNode(&t);

        char *string = fgets(myString, 100, readFile);
        printf(string);

        // fermer le fichier
        fclose(readFile);
    } else {

        // ouverture du fichier a echouee
        printf("Impossible de charger le dictionnaire");
        exit(1);
    }

    return 0;
}
