#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include "Grid.h"
#include "interfaces.h"

#define LOCATION_DICO "./res/txt/dico.txt"
#define LOCATION_GRID "./res/txt/grille_validation.txt"

int main(int argc, char* argv[]) {

    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);


    /***************************
    *** Dico & Grid creation ***
    ***************************/

    // Trie for dictionnary
    Trie *t = (Trie*)malloc(sizeof(Trie));

    // Trie for grid
    Trie *tGrid = (Trie*)malloc(sizeof(Trie));

    // Grid
    Cell grid[N][N];

    // Create Trie with words from file
    createFullTrie(LOCATION_DICO, t);

    // Create Trie for grid
    createTrie(tGrid);

    // Create grid
    createFullGrid(LOCATION_GRID, grid);


    /****************************
    ********** Display **********
    ****************************/

    const unsigned int SCREEN_WIDTH = 480;
    const unsigned int SCREEN_HEIGHT = 650;

    TTF_Init();
    SDL_Surface* screen = NULL; // screen principal
    char continu = 1;
    int state = 0;

    // array for coord
    int coord[17][2] = {{0,0}};
    int c = 0;
    int *cpt = &c;
    int scoreTotal = 0;
    int *pScore = malloc(sizeof(int));
    pScore = &scoreTotal;

    if (init() != 0) {

        fprintf(stderr,"SDL init failed\n");
        return -1;
    }

    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("RUZZLE : Etude de Cas", NULL);

    if (screen == NULL) {

        fprintf(stderr,"Open Window Failed\n");
        close();
        return -2;
    }

    PrincipalWindow *principal = principal_window_create();
    GridWindow *gride = NULL;
    ScoreWindow *score = NULL;
    SDL_Event event;

    // Boucle principale
    while (continu) {

        switch (state) {

        case 0:
            principal_window_draw(principal,screen);
            if (principal_window_load_window_grid(principal,event) != 0) {

                principal_window_destroy(principal);
                gride = grid_window_create(pScore, grid);

                grid_window_draw(gride,screen, event);
                letter_display(LOCATION_GRID, gride, screen);
                state = 1;
            }

            break;
        case 1:

            if(grid_window_draw_on_clic(gride, screen, event, t, tGrid, grid, coord, cpt, pScore) == 1){
                continu = 0;
            }

            if (grid_window_update(gride) != 0) {

                grid_window_destroy(gride);
                score = score_window_create();
                state = 2;
            }

            break;
        case 2:

            score_window_draw(score, screen);

            if (score_window_load(score, event) != 0) {
                score_window_destroy(score);
                destroyTrie(tGrid);
                principal = principal_window_create();
                state = 0;
            }

            break;
        }

        //to close application on cross clic
        if (event.type == SDL_QUIT) {

            //leave the principal loop
            continu = 0;
        }

        SDL_PollEvent(&event);
        SDL_Delay(10);
        SDL_Flip(screen);
    }

    close();

    grid_window_destroy(gride);

    destroyTrie(tGrid);

    destroyTrie(t);

    return 0;
}
