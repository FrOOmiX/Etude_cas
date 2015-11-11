#include "interfaces.h"

/*Pour l'ecran principal au lancement du RUZZLE */

/*FenetrePrincipale* vueMenu_new(){
    FenetrePrincipale* retour = (FenetrePrincipale*)malloc(sizeof(FenetrePrincipale));
     if(retour == NULL){
      return retour;
    }

    char const *titlePathName = "./assets/gfx/game_over_logo.png";
    char const *bgPathName = "./assets/gfx/background.png";

     //Background
     retour->pBG = IMG_Load(bgPathName);
     if(retour->pBG == NULL){
        //vueMenu_destroy(retour);
        return NULL;
     }
     retour->bgDestination.x = 0;
     retour->bgDestination.y = 0;

     retour->newGameDestination.x = 185 ;
     retour->newGameDestination.y = 400 ;

     //chargement du logo ruzzle
     retour->titre = IMG_Load(titlePathName);
     if ( retour->titre == NULL){
        //vueMenu_destroy(retour);
        return NULL;
     }
     retour->titleDestination.x = 150;
     retour->titleDestination.y = 50;

     return  retour;
}


void vueMenu_draw(FenetrePrincipale* menu,SDL_Surface* ecran){
    if( menu != NULL){
        SDL_BlitSurface(menu->pBG,NULL,ecran,&(menu->bgDestination));
        SDL_BlitSurface(menu->titre,NULL,ecran,&(menu->titleDestination));
    }
}

void vueMenu_destroy(FenetrePrincipale* menu){
    SDL_FreeSurface(menu->titre);
    SDL_FreeSurface(menu->pBG);
    free(menu);
}
*/
/*Pour l'ecran avec la grille du RUZZLE */

FenetreGrille* gv_new(){


  FenetreGrille* grille = (FenetreGrille*)malloc(sizeof(FenetreGrille));
  if(grille == NULL){
      return grille;
  }

    char const *titlePathName = "./assets/gfx/game_over_logo.png";
    char const *bgPathName = "./assets/gfx/background.png";


     //Background
     grille->pBG = IMG_Load(bgPathName);
     if(grille->pBG == NULL){
        //vueMenu_destroy(retour);
        return NULL;
     }
     grille->bgDestination.x = 0;
     grille->bgDestination.y = 0;

     //chargement du logo Ruzzle
     grille->titre = IMG_Load(titlePathName);
     if ( grille->titre == NULL){
        //vueMenu_destroy(retour);
        return NULL;
     }
     grille->titleDestination.x = 150;
     grille->titleDestination.y = 50;



    return  grille;
}

void gv_draw(FenetreGrille* grille, SDL_Surface* ecran){ //FenetreGrille* grille, SDL_Surface* ecran


    SDL_BlitSurface(grille->pBG,NULL,ecran,&(grille->bgDestination));
    SDL_BlitSurface(grille->titre,NULL,ecran,&(grille->titleDestination));




}

void apply_surface( int x, int y, SDL_Surface *source, SDL_Surface* destination, SDL_Rect* clip )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( source, clip, destination, &offset );
}



void gv_destroy(FenetreGrille* grille){
    SDL_FreeSurface(grille->pBG);
    //SDL_FreeSurface(grille->pFontSurface);
    free(grille);
}
