#include "interfaces.h"

/*Pour l'screen principal au lancement du RUZZLE */

PrincipalWindow* principal_window_create(){
    PrincipalWindow* retour = (PrincipalWindow*)malloc(sizeof(PrincipalWindow));
     if(retour == NULL){
      return retour;
    }

    char const *titleIMG = "./assets/gfx/game_over_logo.png";
    char const *backgroundIMG = "./assets/gfx/background.png";

     //Background
     retour->background = IMG_Load(backgroundIMG);
     if(retour->background == NULL){
        //principal_window_destroy(retour);
        return NULL;
     }
     retour->backgroundPosition.x = 0;
     retour->backgroundPosition.y = 0;

     retour->gameStartPosition.x = 185 ;
     retour->gameStartPosition.y = 400 ;

     //chargement du logo ruzzle
     retour->title = IMG_Load(titleIMG);
     if ( retour->title == NULL){
        //principal_window_destroy(retour);
        return NULL;
     }
     retour->logoRuzzlePosition.x = 150;
     retour->logoRuzzlePosition.y = 50;

     return  retour;
}


void principal_window_draw(PrincipalWindow* menu,SDL_Surface* screen){
    if( menu != NULL){
        SDL_BlitSurface(menu->background,NULL,screen,&(menu->backgroundPosition));
        SDL_BlitSurface(menu->title,NULL,screen,&(menu->logoRuzzlePosition));
    }
}

void principal_window_destroy(PrincipalWindow* menu){
    SDL_FreeSurface(menu->title);
    SDL_FreeSurface(menu->background);
    free(menu);
}

/*Pour l'screen avec la grid du RUZZLE */

GridWindow* grid_window_create(){
    const int SHEET_WIDTH = 200;
    const int SHEET_HEIGHT = 512;
  /*fenetre sans grille*/
  GridWindow* grid = (GridWindow*)malloc(sizeof(GridWindow));
  if(grid == NULL){
      return grid;
  }

    char const *titleIMG = "./assets/gfx/game_over_logo.png";
    char const *backgroundIMG = "./assets/gfx/background.png";
    char const *trophyIMG = "./assets/gfx/trophy_decoration.png";

     //Background
     grid->background = IMG_Load(backgroundIMG);
     if(grid->background == NULL){
        //principal_window_destroy(retour);
        return NULL;
     }
     grid->backgroundPosition.x = 0;
     grid->backgroundPosition.y = 0;

     //chargement du logo Ruzzle
     grid->title = IMG_Load(titleIMG);
     if ( grid->title == NULL){
        //principal_window_destroy(retour);
        return NULL;
     }
     grid->logoRuzzlePosition.x = 150;
     grid->logoRuzzlePosition.y = 50;

     //chargement du bottom
     grid->trophy = IMG_Load(trophyIMG);
     if (grid->trophy == NULL){
        //principal_window_destroy(retour);
        return NULL;
     }
     grid->trophyPosition.x = 0;
     grid->trophyPosition.y = 600;

    /*pour la grille*/
    grid->faces = IMG_Load("./assets/gfx/tile_spritesheet_lowres.png");

    //On coupe la partie en haut à gauche (premier sprite)
    //On coupe la partie case sans bonus
    grid->clip[ 0 ].x = 0;
    grid->clip[ 0 ].y = 0;
    grid->clip[ 0 ].w = SHEET_WIDTH/2;
    grid->clip[ 0 ].h = SHEET_HEIGHT/5;

    //On coupe la partie en haut à droite (second sprite)
    grid->clip[ 1 ].x = 0;
    grid->clip[ 1 ].y = SHEET_HEIGHT/5;
    grid->clip[ 1 ].w = SHEET_WIDTH/2;
    grid->clip[ 1 ].h = SHEET_HEIGHT/5;

    //On coupe la partie en bas à gauche (troisième sprite)
    grid->clip[ 2 ].x = 0;
    grid->clip[ 2 ].y = (SHEET_HEIGHT/5)*2;
    grid->clip[ 2 ].w = SHEET_WIDTH/2;
    grid->clip[ 2 ].h = SHEET_HEIGHT/5;

    //On coupe la partie en bas à droite (quatrième sprite)
    grid->clip[ 3 ].x = 0;
    grid->clip[ 3 ].y = (SHEET_HEIGHT/5)*3;
    grid->clip[ 3 ].w = SHEET_WIDTH/2;
    grid->clip[ 3 ].h = SHEET_HEIGHT/5;

    grid->clip[ 4 ].x = 0;
    grid->clip[ 4 ].y = (SHEET_HEIGHT/5)*4;
    grid->clip[ 4 ].w = SHEET_WIDTH/2;
    grid->clip[ 4 ].h = SHEET_HEIGHT/5;



    return  grid;
}

void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface* dest, SDL_Rect* clip ){
    SDL_Rect pos;

    pos.x = x;
    pos.y = y;

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &pos );
}

void grid_window_draw(GridWindow* grid, SDL_Surface* screen){ //GridWindow* grid, SDL_Surface* screen


    SDL_BlitSurface(grid->background,NULL,screen,&(grid->backgroundPosition));
    SDL_BlitSurface(grid->title,NULL,screen,&(grid->logoRuzzlePosition));
    SDL_BlitSurface(grid->trophy,NULL,screen,&(grid->trophyPosition));


    apply_surface( 40, 150, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 40, 250, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 40, 350, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 40, 450, grid->faces, screen, &(grid->clip[ 4 ]) );

    apply_surface( 140, 150, grid->faces, screen, &(grid->clip[ 2 ]) );
    apply_surface( 140, 250, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 140, 350, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 140, 450, grid->faces, screen, &(grid->clip[ 0 ]) );

    apply_surface( 240, 150, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 240, 250, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 240, 350, grid->faces, screen, &(grid->clip[ 3 ] ));
    apply_surface( 240, 450, grid->faces, screen, &(grid->clip[ 0 ]) );

    apply_surface( 340, 150, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 340, 250, grid->faces, screen, &(grid->clip[ 1 ]) );
    apply_surface( 340, 350, grid->faces, screen, &(grid->clip[ 0 ]) );
    apply_surface( 340, 450, grid->faces, screen, &(grid->clip[ 0 ]) );


}

void grid_window_destroy(GridWindow* grid){
    SDL_FreeSurface(grid->background);
    SDL_FreeSurface(grid->trophy);
    SDL_FreeSurface(grid->faces);
    SDL_FreeSurface(grid->title);
    //SDL_FreeSurface(grid->pFontSurface);
    free(grid);
}
