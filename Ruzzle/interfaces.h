#ifndef _INTERFACES_H
#define _INTERFACES_H


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/*Pour l'screen principal au lancement du RUZZLE */

typedef struct{
    SDL_Surface *title, *background;
    SDL_Rect logoRuzzlePosition, backgroundPosition, gameStartPosition;
}PrincipalWindow;

extern PrincipalWindow* principal_window_create();
extern void principal_window_draw(PrincipalWindow* menu,SDL_Surface* screen);
extern void principal_window_destroy(PrincipalWindow* menu);

/*Pour l'screen avec la grid du RUZZLE */

typedef struct{
    SDL_Surface *title, *background, *faces, *trophy;
    SDL_Rect logoRuzzlePosition, backgroundPosition, trophyPosition, clip[5];
}GridWindow;

extern GridWindow* grid_window_create();
extern void grid_window_draw(GridWindow* grid, SDL_Surface* screen);
extern void grid_window_destroy(GridWindow* grid);
extern void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface* dest, SDL_Rect* clip);

#endif //INTERFACES_H
