#ifndef _INTERFACES_H
#define _INTERFACES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//Struct for principal screen
typedef struct{
    SDL_Surface *title, *background, *gameStart;
    SDL_Rect logoRuzzlePosition, backgroundPosition, gameStartPosition;
    TTF_Font *font;
}PrincipalWindow;

//Struct for screen with the play grid
typedef struct{
    SDL_Surface *title, *background, *faces, *trophy, *letter;
    SDL_Rect logoRuzzlePosition, backgroundPosition, trophyPosition, clip[5], clipClic[5], letterPosition, pos;
    TTF_Font *fontLetter;
}GridWindow;

//functions usefull for PrincipalWindow
extern PrincipalWindow* principal_window_create();
extern int principal_window_load_window_grid(PrincipalWindow* game_menu, SDL_Event event);
extern void principal_window_draw(PrincipalWindow* game_menu,SDL_Surface* screen);
extern void principal_window_destroy(PrincipalWindow* menu);

//Function usefull for GridWindow
extern GridWindow* grid_window_create();
extern void grid_window_draw(GridWindow* grid, SDL_Surface* screen, SDL_Event event);
extern void grid_window_destroy(GridWindow* grid);
extern void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface* dest, SDL_Rect* clip, GridWindow* grid);
extern void letter_display(char * nameFile, GridWindow* grid, SDL_Surface* screen);
extern void grid_window_draw_on_clic(GridWindow* grid, SDL_Surface* screen, SDL_Event event);

//Function for init and close SDL
extern void close();
extern int init();

//Function for test
extern int mainDisplay();

#endif //INTERFACES_H
