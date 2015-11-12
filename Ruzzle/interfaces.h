#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#ifndef _INTERFACES_H
#define _INTERFACES_H

/*Pour l'screen principal au lancement du RUZZLE */

typedef struct{
    SDL_Surface *title, *background, *gameStart;
    SDL_Rect logoRuzzlePosition, backgroundPosition, gameStartPosition;
    TTF_Font *font;
}PrincipalWindow;


/*Pour l'screen avec la grid du RUZZLE */

typedef struct{
    SDL_Surface *title, *background, *faces, *trophy;
    SDL_Rect logoRuzzlePosition, backgroundPosition, trophyPosition, clip[5];
}GridWindow;

extern PrincipalWindow* principal_window_create();
extern int principal_window_load_window_grid(PrincipalWindow* game_menu, SDL_Event event);
extern void principal_window_draw(PrincipalWindow* game_menu,SDL_Surface* screen);
extern void principal_window_destroy(PrincipalWindow* menu);

extern GridWindow* grid_window_create();
extern void grid_window_draw(GridWindow* grid, SDL_Surface* screen);
extern void grid_window_destroy(GridWindow* grid);
extern void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface* dest, SDL_Rect* clip);

#endif //INTERFACES_H
