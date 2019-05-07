#ifndef _menu_H
#define _menu_H_
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>	
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h> 
#include "jeu.h"

typedef struct 
{
    SDL_Surface *fond[202];
    SDL_Rect posfond;
}animation;

typedef struct  
{
	SDL_Surface *menuFond[3],*help,*settings,*quit,*fond;
	SDL_Rect positionMenuFond,positionmenuQuitter,positionhelp,positionsettings,posfond;
	 Mix_Music* backgroundSound;
    Mix_Chunk* button;	
}MENU;



void initialiserAnimation(animation *ANIM,SDL_Surface *ecran);
void libereranimation(animation *ANIM);
void initialiserMenu(MENU *menu);
void updateMenu(int *i,int *i_settings,int *sauvgarde_settings,int *soundSpace,int *soundMusic,int *x,SDL_Event event,int *continuer,int *i_help,int *i_quit);
void libererationMENU (MENU *menu);
void afficherfond(SDL_Surface *ecran,MENU *menu);
void afficherMenu(int *i,int *i_settings,int *sauvgarde_settings,int *soundSpace,int *soundMusic,MENU *menu,SDL_Surface *ecran,int *i_help,int *i_quit,int *x);
void intiMUSIC(MENU *menu);
void PlayMusic(MENU *menu);
void WAVmusic(MENU *menu,int *x);
void libererMUSIC(MENU *menu);
#endif