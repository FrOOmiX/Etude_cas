#ifndef _INTERFACES_H
#define _INTERFACES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Grid.h"
#include "Grid.h"
#include "Trie.h"
//Struct for principal screen
typedef struct{
    SDL_Surface *title, *background, *gameStart;
    SDL_Rect logoRuzzlePosition, backgroundPosition, gameStartPosition;
    TTF_Font *font;
}PrincipalWindow;

//Struct for screen with the play grid
typedef struct{
    SDL_Color fontColor;
    SDL_TimerID timerID;
    unsigned int secondsLeft;
    int coord[17][2];
    SDL_Surface *title, *background, *faces, *trophy, *letter, *timer;
    SDL_Rect logoRuzzlePosition, backgroundPosition, trophyPosition, clip[5], clipClic[5], letterPosition, pos, timerPosition;
    TTF_Font *fontLetter, *fontTimer;
}GridWindow;

//Struct for screen with the score and replay grid
typedef struct{
    SDL_Surface *title, *background, *trophy, *replay, *score;
    SDL_Rect logoRuzzlePosition, backgroundPosition, trophyPosition, replayPosition, scorePosition;
    TTF_Font *font;
}ScoreWindow;

//functions usefull for PrincipalWindow
extern PrincipalWindow* principal_window_create();
extern int principal_window_load_window_grid(PrincipalWindow* game_menu, SDL_Event event);
extern void principal_window_draw(PrincipalWindow* game_menu,SDL_Surface* screen);
extern void principal_window_destroy(PrincipalWindow* menu);

//Functions usefull for GridWindow
extern GridWindow* grid_window_create();
extern void grid_window_draw(GridWindow* grid, SDL_Surface* screen, SDL_Event event);
extern void grid_window_destroy(GridWindow* grid);
extern void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface* dest, SDL_Rect* clip, GridWindow* grid);
extern void letter_display(char * nameFile, GridWindow* grid, SDL_Surface* screen);
extern int grid_window_draw_on_clic(GridWindow* grid, SDL_Surface* screen, SDL_Event event,Trie *t,Cell gride[N][N], int coord[17][2], int *cpt);
extern int onClic(GridWindow* grid,int x,int y, int *pointeurSurA, int *pointeurSurB,int *pointeurSurR,int *pointeurSurC);
extern Uint32 timer(Uint32 interval, void* grid);
extern int grid_window_update(GridWindow *grid);

//functions usefull for ScoreWindow
extern ScoreWindow* score_window_create();
extern void score_window_draw(ScoreWindow* grid, SDL_Surface* screen);
extern void score_window_destroy(ScoreWindow* grid);
int score_window_load(ScoreWindow* score_menu, SDL_Event event);

//Function for init and close SDL
extern void close();
extern int init();

//Function for test
extern int mainDisplay();

#endif //INTERFACES_H
