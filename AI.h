#ifndef  AI_H_
#define  AI_H_

#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
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
    SDL_Surface *robot[5];
    SDL_Rect Posrobot;
    int direction;
    STATE state;
}ROBOT2;

typedef struct 
{
    SDL_Surface *map;
    SDL_Rect PosMap,PosRectMap;
}MAP;
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

void initialiserpoint (point *point);
void initialiser(Struct_robot *ROBOT);
void initialiserattack(Struct_robotAtt *ROBOTA);
void initialiser2(ROBOT2 *robot);
void   Testecran (Struct_robot *ROBOT);
void initialiserminiMap (miniMAP *minimap);
void initialiserMap (MAP *map);
int scrolling (Struct_robot *ROBOT,MAP *map);
void affichage(Struct_robot *ROBOT,Struct_robotAtt *ROBOTA,SDL_Surface *ecran,int i,SDL_Surface *map,SDL_Rect positionmap,SDL_Surface *minimap,SDL_Rect positionminimap,int distance);
void affichage2(ROBOT2 *robot,SDL_Surface *ecran,int i,SDL_Surface *RectangleRobot,SDL_Rect PosRectangleRobot,point *point);
int  Mouvemant(Struct_robot *ROBOT,SDL_Surface *ecran,int i);
void Mouvemantpoint(point *point,SDL_Surface *ecran,miniMAP *MP);
int robot2mouvemant(ROBOT2 *robot,SDL_Surface *ecran,int i2,SDL_Rect Posrobot);
int  Mouvemantattack(ROBOT2 *robot,SDL_Surface *ecran,int i2,SDL_Rect Posrobot);
void liberation(Struct_robot *ROBOT);
void liberation2(ROBOT2 *robot);
int  AI(ROBOT2 *robot2,Struct_robot *robot1,SDL_Surface *ecran);
#endif

