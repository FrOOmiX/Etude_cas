#ifndef _INTERFACES_H
#define _INTERFACES_H


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/*Pour l'ecran principal au lancement du RUZZLE */

typedef struct{
    SDL_Surface *titre, *pBG;
    SDL_Rect titleDestination, bgDestination, newGameDestination;
}FenetrePrincipale;

extern FenetrePrincipale* vueMenu_new();
extern void vueMenu_draw(FenetrePrincipale* menu,SDL_Surface* ecran);
extern void vueMenu_destroy(FenetrePrincipale* menu);

/*Pour l'ecran avec la grille du RUZZLE */

typedef struct{
    SDL_Surface *titre, *pBG, *faces;
    SDL_Rect titleDestination, bgDestination, newGameDestination;// grilleBonusDestination;
}FenetreGrille;

extern FenetreGrille* gv_new();
extern void gv_draw(FenetreGrille* grille, SDL_Surface* ecran);
extern void gv_destroy(FenetreGrille* grille);
extern void apply_surface( int x, int y, SDL_Surface *source, SDL_Surface* destination, SDL_Rect* clip);

#endif //INTERFACES_H
