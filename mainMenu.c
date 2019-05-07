#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "menu.h"
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>

int main()
{
    SDL_Surface *ecran; 
    animation ANIM;
    MENU menu;
    SDL_Event event;
int i=1,x=0,QUITTER,Q_choix=1,i_settings=1,soundSpace=1,soundMusic=1,sauvgarde_settings,i_help=1,i_quit,i_GAME_MODE=1,i_GAME=2;
int continuer=1;

int mouseX,mouseY;
putenv("SDL_VIDEO_CENTERED=1");
    SDL_Init( SDL_INIT_AUDIO|SDL_INIT_VIDEO);
 ecran = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
SDL_WM_SetIcon(IMG_Load("logo jeu.png"), NULL);
 //animation
//initialiserAnimation(&ANIM,ecran);
//SDL_Delay(10);  
//libereranimation(&ANIM);
 Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);

initialiserMenu(&menu);
intiMUSIC(&menu);
PlayMusic(&menu);

while (continuer)
{ 
printf("%d\n",i );
	afficherfond(ecran,&menu);
	updateMenu(ecran,&i,&i_settings,&sauvgarde_settings,&soundSpace,&soundMusic,&x,event,&continuer,&i_help,&i_quit,&i_GAME_MODE,&i_GAME);
    afficherMenu(&i,&i_settings,&sauvgarde_settings,&soundSpace,&soundMusic,&menu,ecran,&i_help,&i_quit,&x,&i_GAME_MODE,&i_GAME);
    WAVmusic(&menu,&x);
   // SDL_Flip(ecran);
   // printf("x=%d\n",x);
   // printf("i=%d\n",i );

//   SDL_GetMouseState(&mouseX, &mouseY);
 //printf("x=%d\ny=%d\n",mouseX,mouseY);
  
}

libererationMENU (&menu);
libererMUSIC(&menu);
SDL_Quit();
    return 0;
}
 
