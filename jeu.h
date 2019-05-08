#ifndef _jeu_H
#define _jeu_H_
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include "background.h"
#include "personnage.h"
#include "robot.h"
#include "fonction.h"


void GAME();
 int scrolling (personage *per,MAP *map,int i);
 int input(personage* per,int i,int *continuer ,SDL_Surface *ecran,MAP *map,int *MV);
int  Mouvemant(Struct_robot *ROBOT,SDL_Surface *ecran,int i,int *MV);
int  AI(personage *per,Struct_robot *robot1,SDL_Surface *ecran);
#endif 