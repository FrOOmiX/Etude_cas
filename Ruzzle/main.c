#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trie.h"
#include "Grid.h"

#define LOCATION_DICO "./res/txt/dico.txt"
#define LOCATION_GRID "./res/txt/grille.txt"

//globals var to difine window size
const unsigned int SCREEN_WIDTH = 480;
const unsigned int SCREEN_HEIGHT = 800;

void close()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int init(){
     if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 )
    {
        fprintf(stderr,"SDL init failed\n");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    // Create Trie with all words (and search a specific word)
    createFullTrie(LOCATION_DICO);

    // Create grid
    createFullGrid(LOCATION_GRID);

    /*Graphic part*/

    SDL_Surface* screen = NULL; // screen principal
    char continu = 1; // Indicateur boolean pour la boucle principale
    int state = 0;
    // Creer la fenetre
    if( init() != 0){
        return -1;
    }
    //a mettre sur windows pour voir les messages des printf etc
    //freopen( "CON", "w", stdout );
    //freopen( "CON", "w", stderr );
    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
	if ( screen == NULL )
	{
	    fprintf(stderr,"Open Window Failed\n");
	    close();
        return -2;
	}

    GridWindow *grid = grid_window_create();

    SDL_Event event;

    // Boucle principale
	while ( continu )
	{
	    switch( state){
        case 0:
            grid_window_draw(grid,screen);


	    }


        SDL_Flip(screen);


	    SDL_PollEvent(&event);

        // Pour fermer la fenetre de jeu en cliquant sur la croix
	    if( event.type == SDL_QUIT )
	    {
            //On quitte la boucle principale
            continu = 0;
		}
    }

    close();

    return 0;
}
