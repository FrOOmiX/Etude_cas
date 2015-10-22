#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) {

    /***** Test de lecture de fichier *****/

    FILE* lectureFichier = NULL;                        // pointeur sur le fichier
    char str[512];                                      // tableau qui stocke les chaines lues (a remplacer par une struc de donnee)

    // fonction permettant d'ouvrir le fichier en lecture (r)
    lectureFichier = fopen("./dico.txt", "r");

    if (lectureFichier != NULL) {

        // On lit le fichier

        // fgets(str, 512, lectureFichier); essai
        fscanf(lectureFichier, "", str);              //  lit le fichier selon un format, extrait chaque char quand rencontre un espace
        printf(str);

        // fermer le fichier
        fclose(lectureFichier);
    } else {

        // ouverture du fichier a echouee
        printf("Impossible de charger le dictionnaire");
        exit(1);
    }


    return 0;
}
