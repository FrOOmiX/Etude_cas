#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "interfaces.h"

void close()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int init(){
     if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 )
    {
        fprintf(stderr,"Erreur lors de l'initialisation de la SDL\n");
        return -1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    /*pour le fenetre de depart*/
    /*const unsigned int windowWidth = 480;
    const unsigned int windowHeight = 800;

    SDL_Surface* pWindowSurface = NULL; // Ecran principal
    char mustContinue = 1; // Indicateur boolean pour la boucle principale
    int GAME_STATE = 0;
    // Creer la fenetre
    if( init() != 0){

    //a mettre sur windows pour voir les messages des printf etc
    //freopen( "CON", "w", stdout );
    //freopen( "CON", "w", stderr );
    pWindowSurface = SDL_SetVideoMode(windowWidth,windowHeight,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
	if ( pWindowSurface == NULL )
	{
	    fprintf(stderr,"Erreur lors de l'ouverture de la fenetre\n");
	    close();
        return -2;
	}

    FenetrePrincipale *menu = vueMenu_new();

    SDL_Event event;
    // Boucle principale
	while ( mustContinue )
	{
	    switch( GAME_STATE){
        case 0:
            vueMenu_draw(menu,pWindowSurface);
	    }
        // Affiche
        SDL_Flip(pWindowSurface);


	    SDL_PollEvent(&event);

        // Pour fermer la fenetre de jeu en cliquant sur la croix
	    if( event.type == SDL_QUIT )
	    {
            //On quitte la boucle principale
            mustContinue = 0;
		}

	}
    close();*/


    /*pour la fenetre avec la grille*/
    const unsigned int SCREEN_WIDTH = 480;
    const unsigned int SCREEN_HEIGHT = 800;

    SDL_Surface* pWindowSurface = NULL; // Ecran principal
    char mustContinue = 1; // Indicateur boolean pour la boucle principale
    int GAME_STATE = 0;
    // Creer la fenetre
    if( init() != 0){
        return -1;
    }
    //a mettre sur windows pour voir les messages des printf etc
    //freopen( "CON", "w", stdout );
    //freopen( "CON", "w", stderr );
    pWindowSurface = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE | SDL_DOUBLEBUF);
	if ( pWindowSurface == NULL )
	{
	    fprintf(stderr,"Erreur lors de l'ouverture de la fenetre\n");
	    close();
        return -2;
	}

    FenetreGrille *grille = gv_new();

    SDL_Event event;

    /*pour afficher les sprites*/
    const int SHEET_WIDTH = 200;
    const int SHEET_HEIGHT = 512;
    SDL_Rect clip[ 5 ];
    SDL_Surface* faces = IMG_Load("./assets/gfx/tile_spritesheet_lowres.png");
    //On coupe la partie en haut à gauche (premier sprite)
    //On coupe la partie case sans bonus
    clip[ 0 ].x = 0;
    clip[ 0 ].y = 0;
    clip[ 0 ].w = SHEET_WIDTH/2;
    clip[ 0 ].h = SHEET_HEIGHT/5;

    //On coupe la partie en haut à droite (second sprite)
    clip[ 1 ].x = 0;
    clip[ 1 ].y = SHEET_HEIGHT/5;
    clip[ 1 ].w = SHEET_WIDTH/2;
    clip[ 1 ].h = SHEET_HEIGHT/5;

    //On coupe la partie en bas à gauche (troisième sprite)
    clip[ 2 ].x = 0;
    clip[ 2 ].y = (SHEET_HEIGHT/5)*2;
    clip[ 2 ].w = SHEET_WIDTH/2;
    clip[ 2 ].h = SHEET_HEIGHT/5;

    //On coupe la partie en bas à droite (quatrième sprite)
    clip[ 3 ].x = 0;
    clip[ 3 ].y = (SHEET_HEIGHT/5)*3;
    clip[ 3 ].w = SHEET_WIDTH/2;
    clip[ 3 ].h = SHEET_HEIGHT/5;

    clip[ 4 ].x = 0;
    clip[ 4 ].y = (SHEET_HEIGHT/5)*4;
    clip[ 4 ].w = SHEET_WIDTH/2;
    clip[ 4 ].h = SHEET_HEIGHT/5;




    // Boucle principale
	while ( mustContinue )
	{
	    switch( GAME_STATE){
        case 0:
            gv_draw(grille,pWindowSurface);
            apply_surface( 40, 150, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 40, 250, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 40, 350, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 40, 450, faces, pWindowSurface, &clip[ 4 ] );

            apply_surface( 140, 150, faces, pWindowSurface, &clip[ 2 ] );
            apply_surface( 140, 250, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 140, 350, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 140, 450, faces, pWindowSurface, &clip[ 0 ] );

            apply_surface( 240, 150, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 240, 250, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 240, 350, faces, pWindowSurface, &clip[ 3 ] );
            apply_surface( 240, 450, faces, pWindowSurface, &clip[ 0 ] );

            apply_surface( 340, 150, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 340, 250, faces, pWindowSurface, &clip[ 1 ] );
            apply_surface( 340, 350, faces, pWindowSurface, &clip[ 0 ] );
            apply_surface( 340, 450, faces, pWindowSurface, &clip[ 0 ] );

	    }


        SDL_Flip(pWindowSurface);


	    SDL_PollEvent(&event);

        // Pour fermer la fenetre de jeu en cliquant sur la croix
	    if( event.type == SDL_QUIT )
	    {
            //On quitte la boucle principale
            mustContinue = 0;
		}
    }

 close();
    return 0;
}

