#include "interfaces.h"

/*For principal screen*/

PrincipalWindow* principal_window_create()
{
    PrincipalWindow* principal = (PrincipalWindow*)malloc(sizeof(PrincipalWindow));

    char const *logoRuzzle = "./res/gfx/game_over_logo.png";
    char const *backgroundIMG = "./res/gfx/background.png";
    char const *text = "./res/fonts/edgothic.ttf";

    //Background
    principal->background = IMG_Load(backgroundIMG);

    principal->backgroundPosition.x = 0;
    principal->backgroundPosition.y = 0;

    principal->gameStartPosition.x = 185 ;
    principal->gameStartPosition.y = 400 ;

    //for title logo
    principal->title = IMG_Load(logoRuzzle);

    principal->logoRuzzlePosition.x = 150;
    principal->logoRuzzlePosition.y = 50;

    //To play new game
    principal->font = TTF_OpenFont(text, 10);
    SDL_Color textColor = {255,255,255};
    principal->gameStart = TTF_RenderText_Solid(principal->font,"COMMENCER",textColor);
    principal->gameStartPosition.x = 150;
    principal->gameStartPosition.y = 400;

    return  principal;
}

//function to catch the clic event on the principal screen
int principal_window_load_window_grid(PrincipalWindow* game_menu, SDL_Event event)
{
    if ( event.type == SDL_MOUSEBUTTONDOWN)
    {
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            return 1;
        }
    }
    return 0;
}

//function to draw elements on the screen
void principal_window_draw(PrincipalWindow* menu,SDL_Surface* screen)
{
    SDL_BlitSurface(menu->background,NULL,screen,&(menu->backgroundPosition));
    SDL_BlitSurface(menu->title,NULL,screen,&(menu->logoRuzzlePosition));
    SDL_BlitSurface(menu->gameStart,NULL,screen,&(menu->gameStartPosition));
}

//destroy elements -> free memory
void principal_window_destroy(PrincipalWindow* menu)
{
    SDL_FreeSurface(menu->title);
    SDL_FreeSurface(menu->background);
    SDL_FreeSurface(menu->gameStart);
    free(menu);
}

/*For game screen with the grid */

GridWindow* grid_window_create()
{
    const int SHEET_WIDTH = 200;
    const int SHEET_HEIGHT = 512;
    /*fenetre sans grille*/
    GridWindow* grid = (GridWindow*)malloc(sizeof(GridWindow));

    char const *titleIMG = "./res/gfx/game_over_logo.png";
    char const *backgroundIMG = "./res/gfx/background.png";
    char const *trophyIMG = "./res/gfx/trophy_decoration.png";

    //Background
    grid->background = IMG_Load(backgroundIMG);

    grid->backgroundPosition.x = 0;
    grid->backgroundPosition.y = 0;

    //for title logo
    grid->title = IMG_Load(titleIMG);

    grid->logoRuzzlePosition.x = 150;
    grid->logoRuzzlePosition.y = 50;

    //bottom img
    grid->trophy = IMG_Load(trophyIMG);

    grid->trophyPosition.x = 0;
    grid->trophyPosition.y = 600;

    //for the grid (srpitesheet)
    grid->faces = IMG_Load("./res/gfx/tile_spritesheet_lowres.png");

    grid->clip[ 0 ].x = 0;
    grid->clip[ 0 ].y = 0;
    grid->clip[ 0 ].w = SHEET_WIDTH/2;
    grid->clip[ 0 ].h = SHEET_HEIGHT/5;

    grid->clip[ 1 ].x = 0;
    grid->clip[ 1 ].y = SHEET_HEIGHT/5;
    grid->clip[ 1 ].w = SHEET_WIDTH/2;
    grid->clip[ 1 ].h = SHEET_HEIGHT/5;

    grid->clip[ 2 ].x = 0;
    grid->clip[ 2 ].y = (SHEET_HEIGHT/5)*2;
    grid->clip[ 2 ].w = SHEET_WIDTH/2;
    grid->clip[ 2 ].h = SHEET_HEIGHT/5;

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

//to draw the boxes imgs
void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface* dest, SDL_Rect* clip )
{

    SDL_Rect pos;

    pos.x = x;
    pos.y = y;

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &pos );
}

//to draw all elements on the play scren (with grid)
void grid_window_draw(GridWindow* grid, SDL_Surface* screen)
{

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

//destroy elements -> free memory
void grid_window_destroy(GridWindow* grid)
{
    SDL_FreeSurface(grid->background);
    SDL_FreeSurface(grid->trophy);
    SDL_FreeSurface(grid->faces);
    SDL_FreeSurface(grid->title);
    free(grid);
}


//to SDL
void close()
{
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

//to init SDL
int init()
{
    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER ) == -1 )
    {
        fprintf(stderr,"SDL init failed\n");
        return -1;
    }
    return 0;
}

//to test application
int mainDisplay()
{
    const unsigned int SCREEN_WIDTH = 480;
    const unsigned int SCREEN_HEIGHT = 800;

    TTF_Init();

    SDL_Surface* screen = NULL; // screen principal
    char continu = 1;
    int state = 0;

    if( init() != 0)
    {
        fprintf(stderr,"SDL init failed\n");
        return -1;
    }

    freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );

    screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("RUZZLE : Etude de Cas", NULL);

    if ( screen == NULL )
    {
        fprintf(stderr,"Open Window Failed\n");
        close();
        return -2;
    }


    PrincipalWindow* principal = principal_window_create();
    GridWindow *grid = NULL;
    SDL_Event event;



    // Boucle principale
    while ( continu )
    {
        switch( state)
        {
        case 0:
            principal_window_draw(principal,screen);
            if (principal_window_load_window_grid(principal,event) != 0)
            {
                principal_window_destroy(principal);
                grid = grid_window_create();
                state = 1;
            }
            break;
        case 1:
            grid_window_draw(grid,screen);


            break;

        }

        SDL_Flip(screen);


        SDL_PollEvent(&event);

        //to close application on cross clic
        if( event.type == SDL_QUIT )
        {
            //leave the principal loop
            continu = 0;
        }
    }
    close();
    return 0;
}
