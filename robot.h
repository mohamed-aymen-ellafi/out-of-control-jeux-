#ifndef _robot_H
#define _robot_H
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>

typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING,ATTACKING};


typedef struct 
{
    SDL_Surface *robot[9];
    SDL_Rect Posrobot;
    int A;
    STATE state;
}Struct_robot;
typedef struct 
{
    
    SDL_Surface *robotattack[7];
    SDL_Rect Posrobot;
    int A;
}Struct_robotAtt;


typedef struct 
{
    SDL_Surface *minimap;
    SDL_Rect PosminiMap,PosRectminiMap;
}miniMAP; 
typedef struct 
{    
      SDL_Rect Pospoint;
      SDL_Surface *point;
}point;

void initialiserattack(Struct_robotAtt *ROBOTA);
void initialiser(Struct_robot *ROBOT);
void affichage(Struct_robot *ROBOT,Struct_robotAtt *ROBOTA,SDL_Surface *ecran,int i,int distance);
void liberation(Struct_robot *ROBOT,Struct_robotAtt *att);

#endif 