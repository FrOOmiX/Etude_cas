#include "interfaces.h"
#define LOCATION_GRID "./res/txt/grille.txt"
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
    principal->font = TTF_OpenFont(text, 40);
    SDL_Color textColor = {255,255,255};
    principal->gameStart = TTF_RenderText_Solid(principal->font,"COMMENCER",textColor);
    principal->gameStartPosition.x = 150;
    principal->gameStartPosition.y = 400;

    return  principal;
}

//function to catch the clic event on the principal screen
int principal_window_load_window_grid(PrincipalWindow* game_menu, SDL_Event event)
{
    int x, y;
    if( event.button.button == SDL_BUTTON_LEFT )
    {
        x = event.button.x;
        y = event.button.y;

        //Si la souris est dans le bouton
        if( ( x > game_menu->gameStartPosition.x ) && ( x < game_menu->gameStartPosition.x + game_menu->gameStartPosition.w ) && ( y > game_menu->gameStartPosition.y ) && ( y < game_menu->gameStartPosition.y + game_menu->gameStartPosition.h ) )
        {
            //Mise à jour du sprite du bouton
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
Uint32 timer(Uint32 interval, void* grid){
    GridWindow* g = grid;
    g->secondsLeft--;
 /*  char* buf = malloc(sizeof(char*));
   sprintf(buf, "%d", g->secondsLeft);
    g->fontTimer = TTF_OpenFont("./res/fonts/edgothic.ttf",35);
    SDL_FreeSurface(g->timer);
    g->timer = TTF_RenderText_Solid(g->fontTimer,buf,g->fontColor);*/
    printf("%d", g->secondsLeft);
    return interval;
}

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


    //orange boxes
    grid->clipClic[ 0 ].x = SHEET_WIDTH/2;
    grid->clipClic[ 0 ].y = 0;
    grid->clipClic[ 0 ].w = SHEET_WIDTH;
    grid->clipClic[ 0 ].h = SHEET_HEIGHT/5;

    grid->clipClic[ 1 ].x = SHEET_WIDTH/2;
    grid->clipClic[ 1 ].y = SHEET_HEIGHT/5;
    grid->clipClic[ 1 ].w = SHEET_WIDTH;
    grid->clipClic[ 1 ].h = SHEET_HEIGHT/5;

    grid->clipClic[ 2 ].x = SHEET_WIDTH/2;
    grid->clipClic[ 2 ].y = (SHEET_HEIGHT/5)*2;
    grid->clipClic[ 2 ].w = SHEET_WIDTH;
    grid->clipClic[ 2 ].h = SHEET_HEIGHT/5;

    grid->clipClic[ 3 ].x = SHEET_WIDTH/2;
    grid->clipClic[ 3 ].y = (SHEET_HEIGHT/5)*3;
    grid->clipClic[ 3 ].w = SHEET_WIDTH;
    grid->clipClic[ 3 ].h = SHEET_HEIGHT/5;

    grid->clipClic[ 4 ].x = SHEET_WIDTH/2;
    grid->clipClic[ 4 ].y = (SHEET_HEIGHT/5)*4;
    grid->clipClic[ 4 ].w = SHEET_WIDTH;
    grid->clipClic[ 4 ].h = SHEET_HEIGHT/5;

    //timer
    grid->secondsLeft = 20;
    grid->timerID = SDL_AddTimer(1000,timer,grid);
    grid->fontTimer = TTF_OpenFont("./res/fonts/edgothic.ttf",35);
    grid->fontColor.r = 255; grid->fontColor.g = 255; grid->fontColor.b = 255;
    grid->timer = TTF_RenderText_Blended(grid->fontTimer,"20",grid->fontColor);
    grid->timerPosition.x = 10;
    grid->timerPosition.y = 15;

    return  grid;
}

//to draw the boxes imgs
void apply_surface( int x, int y, SDL_Surface *src, SDL_Surface* dest, SDL_Rect* clip, GridWindow* grid )
{
    grid->pos.x = x;
    grid->pos.y = y;

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &(grid->pos) );
}

void letter_display(char * nameFile, GridWindow* grid, SDL_Surface* screen){

    char const *text = "./res/fonts/helvetica.ttf";
    FILE* readFile= NULL;
    unsigned int i,j,k,s;
    char *str = (char*)malloc(26);
    char buffer[2];
    char c='\0';
    readFile = fopen(nameFile,"r");
    j=-25;
    k=190;

    grid->fontLetter = TTF_OpenFont(text,40);
    SDL_Color textColor = {0,0,0};
    grid->letterPosition.y = k;
    buffer[1]='\0';

    if(readFile != NULL ){
                for (i = 0; i < 4; i++){
                         str =fgets(str, 26, readFile);
                    for (s = 0; s < 4; s++){
                        if(c !='\n'){
                                 c = str[s];
                                 c = toupper(c);
                                 buffer[0]=c;
                            grid->letter = TTF_RenderText_Blended(grid->fontLetter,&buffer[0],textColor);
                            grid->letterPosition.x += 100;
                            SDL_BlitSurface(grid->letter,NULL,screen,&(grid->letterPosition));
                        }
                    }

                    grid->letterPosition.x = j;
                    grid->letterPosition.y += 100;
                }

        fclose(readFile);
    }
    free(str);

}


//to draw all elements on the play scren (with grid)
void grid_window_draw(GridWindow* grid, SDL_Surface* screen, SDL_Event event)
{
    SDL_BlitSurface(grid->background,NULL,screen,&(grid->backgroundPosition));
    SDL_BlitSurface(grid->timer,NULL,screen,&(grid->timerPosition));
    SDL_BlitSurface(grid->trophy,NULL,screen,&(grid->trophyPosition));
    int i,s,l,c;
    l=40; //l comme ligne

        for (i = 0; i < 4; i++){
                c=150;//c comme colonne
                        for (s = 0; s < 4; s++){
                            apply_surface( l, c, grid->faces, screen, &(grid->clip[ 0 ]),grid );
                            c += 100;
                        }
                        l +=100;
        }
    //Applications des bonus
    apply_surface( 40,  450, grid->faces, screen, &(grid->clip[ 4 ]),grid );
    apply_surface( 140, 250, grid->faces, screen, &(grid->clip[ 2 ]),grid );
    apply_surface( 240, 350, grid->faces, screen, &(grid->clip[ 3 ]),grid );
    apply_surface( 340, 250, grid->faces, screen, &(grid->clip[ 1 ]),grid );
}


void grid_window_draw_on_clic(GridWindow* grid, SDL_Surface* screen, SDL_Event event,Trie *t,Cell gride[N][N], int cpt)
{
    int j=0;
    int a;
    int b;
    int *pointeurSurA = &a;
    int *pointeurSurB = &b;
    int r;
    int c;
    int *pointeurSurR = &r;
    int *pointeurSurC = &c;

        SDL_PollEvent(&event);//permet que quand on reste sur la case, ne pas faie l'evenement du clic 30 000 fois
        switch(event.type){
            case SDL_MOUSEBUTTONUP:{
                    if( event.button.button == SDL_BUTTON_LEFT ){
                        j=0;
                        onClic(grid,event.button.x,event.button.y,pointeurSurA,pointeurSurB,pointeurSurR,pointeurSurC, grid->coord);
                        apply_surface( *pointeurSurA, *pointeurSurB, grid->faces, screen, &(grid->clipClic[ 0 ]),grid );
                        grid->coord[cpt][j] = r;
                        printf("%d", grid->coord[cpt][j]); //affichage de X
                        j++;
                        grid->coord[cpt][j] = c;
                        printf("%d\n", grid->coord[cpt][j]); // affichage de Y
                    }
                    else if(event.button.button == SDL_BUTTON_RIGHT) {
                                grid->coord[cpt+1][j] = -1;
                                //scoreWord(t,gride[&a][&b],tab);
                                cpt=0;

                    }
            break;
            }
       }
}

void onClic(GridWindow* grid, int x, int y, int *pointeurSurA, int *pointeurSurB,int *pointeurSurR,int *pointeurSurC,int coord[17][2]){


//TEST AVEC DOUBLE BOUCLE

int i,s,l,c;
l=40; //l comme ligne

    for (i = 0; i < 4; i++){
            c=150;//c comme colones
                    for (s = 0; s < 4; s++){
                        if( (x > l) && (x < l+ grid->pos.w) && (y > c) && (y < c+ grid->pos.h)){
                            *pointeurSurA=l;
                            *pointeurSurB=c;
                            *pointeurSurR=i;
                            *pointeurSurC=s;
                             //affichage de Y

                            break;
                        }
                        c += 100;
                    }

                    l +=100;

    }
}


int grid_window_update(GridWindow *grid){
    if(grid->secondsLeft <= 0){
            SDL_RemoveTimer(grid->timerID);
            return 1;
    }
    return 0;
}

//destroy elements -> free memory
void grid_window_destroy(GridWindow* grid)
{
    SDL_FreeSurface(grid->background);
    SDL_FreeSurface(grid->trophy);
    SDL_FreeSurface(grid->faces);
    SDL_FreeSurface(grid->title);
    SDL_FreeSurface(grid->letter);
    free(grid);
}

//functions for ScoreWindow
ScoreWindow* score_window_create()
{
    ScoreWindow* score = (ScoreWindow*)malloc(sizeof(ScoreWindow*));

    char const *logoRuzzle = "./res/gfx/game_over_logo.png";
    char const *backgroundIMG = "./res/gfx/background.png";
    char const *text = "./res/fonts/edgothic.ttf";

    //Background
    score->background = IMG_Load(backgroundIMG);

    score->backgroundPosition.x = 0;
    score->backgroundPosition.y = 0;

    score->replayPosition.x = 185 ;
    score->replayPosition.y = 400 ;

    //for title logo
    score->title = IMG_Load(logoRuzzle);

    score->logoRuzzlePosition.x = 150;
    score->logoRuzzlePosition.y = 50;

    //To play new game
    score->font = TTF_OpenFont(text, 40);
    SDL_Color textColor = {255,255,255};
    score->replay = TTF_RenderText_Solid(score->font,"REJOUER",textColor);
    score->replayPosition.x = 185;
    score->replayPosition.y = 500;

    return  score;
}

//function to catch the clic event on the principal screen
int score_window_load(ScoreWindow* score_menu, SDL_Event event)
{
    int x, y;
    if( event.button.button == SDL_BUTTON_LEFT )
    {
        x = event.button.x;
        y = event.button.y;

        //Si la souris est dans le bouton
        if( ( x > score_menu->replayPosition.x ) && ( x < score_menu->replayPosition.x + score_menu->replayPosition.w ) &&
           ( y > score_menu->replayPosition.y ) &&( y < score_menu->replayPosition.y + score_menu->replayPosition.h ) )
        {
            //Mise à jour du sprite du bouton
            return 1;
        }
    }
    return 0;
}

//function to draw elements on the screen
void score_window_draw(ScoreWindow* score,SDL_Surface* screen)
{
    SDL_BlitSurface(score->background,NULL,screen,&(score->backgroundPosition));
    SDL_BlitSurface(score->title,NULL,screen,&(score->logoRuzzlePosition));
    SDL_BlitSurface(score->replay,NULL,screen,&(score->replayPosition));
}

//destroy elements -> free memory
void score_window_destroy(ScoreWindow* score)
{
    SDL_FreeSurface(score->title);
    SDL_FreeSurface(score->background);
    SDL_FreeSurface(score->replay);
    free(score);
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
    if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 )
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

    int cpt=0;
    TTF_Init();
    Trie *t = (Trie*)malloc(sizeof(Trie));
    Cell gride[N][N];

    SDL_Surface* screen = NULL; // screen principal
    char continu = 1;
    int state = 0;

    if( init() != 0)
    {
        fprintf(stderr,"SDL init failed\n");
        return -1;
    }

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
    ScoreWindow *score = NULL;
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
            grid_window_draw(grid,screen, event);
            letter_display(LOCATION_GRID, grid, screen);
            grid_window_draw_on_clic(grid, screen, event, t, gride, cpt);
            letter_display(LOCATION_GRID, grid, screen);

            if(grid_window_update(grid) != 0){
                grid_window_destroy(grid);
                score = score_window_create();
                state = 2;
            }
            break;
        case 2:
            score_window_draw(score, screen);
            if(score_window_load(score, event) != 0){
                score_window_destroy(score);
                principal = principal_window_create();
                state = 0;
            }
            break;
        }
        //to close application on cross clic
        if( event.type == SDL_QUIT )
        {
            //leave the principal loop
            continu = 0;
        }
        SDL_PollEvent(&event);
        SDL_Flip(screen);
    }
    close();
    return 0;
}
