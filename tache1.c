#include <stdlib.h>
#include <stdio.h>
//#include "robotfiras.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>


typedef struct 
{
    SDL_Surface *robot[9];
    SDL_Rect Posrobot;
    int A;
}Struct_robot;

typedef struct 
{
    SDL_Surface *robot[5];
    SDL_Rect Posrobot;
    int A;
}ROBOT2;

typedef struct 
{
    SDL_Surface *map;
    SDL_Rect PosMap,PosRectMap;
}MAP;

void initialiser(Struct_robot *ROBOT)
{
     ROBOT->Posrobot.x=0;
     ROBOT->Posrobot.y=500;
    ROBOT->robot[0]= IMG_Load("2.png");
    ROBOT->robot[1]= IMG_Load("3.png");
    ROBOT->robot[2]= IMG_Load("4.png");
    ROBOT->robot[3]= IMG_Load("5.png");
    ROBOT->robot[4]= IMG_Load("6.png");
    ROBOT->robot[5]= IMG_Load("7.png");
    ROBOT->robot[6]= IMG_Load("8.png");
    ROBOT->robot[7]= IMG_Load("9.png");
        
}

void initialiser2(ROBOT2 *robot)
{
     robot->Posrobot.x=500;
     robot->Posrobot.y=500; 
    robot->robot[0]= IMG_Load("B.png");
    robot->robot[1]= IMG_Load("C.png");
    robot->robot[2]= IMG_Load("E.png");
    robot->robot[3]= IMG_Load("F.png");
    robot->robot[4]= IMG_Load("G.png");    
}

void initialiserMap (MAP *map)
{
    map->PosMap.x=0;
    map->PosMap.y=300;
    map->PosRectMap.x=0;
    map->PosRectMap.y=0;
    map->map=IMG_Load("map.png");
}
int scrolling (Struct_robot *ROBOT,MAP *map)
{
    if (ROBOT->Posrobot.x>700)
         {
           ROBOT->Posrobot.x=map->PosMap.x;
            map->PosRectMap.x+=800;
         }
}
void affichage(Struct_robot *ROBOT,SDL_Surface *ecran,int i,SDL_Surface *map,SDL_Rect positionmap)
{
      
    SDL_Delay(100);
    SDL_BlitSurface(map,NULL,ecran,&positionmap); 
    SDL_BlitSurface(ROBOT->robot[i],NULL, ecran,&ROBOT->Posrobot);
     SDL_Flip(ecran);
}

void affichage2(ROBOT2 *robot,SDL_Surface *ecran,int i,SDL_Surface *RectangleRobot,SDL_Rect PosRectangleRobot)
{
      
    SDL_Delay(1);
    SDL_BlitSurface(RectangleRobot,NULL,ecran,&PosRectangleRobot); 
    SDL_BlitSurface(robot->robot[i],NULL, ecran,&robot->Posrobot);
     SDL_Flip(ecran);
}

int  Mouvemant(Struct_robot *ROBOT,SDL_Surface *ecran,int i)
{
        ROBOT->Posrobot.y=300;
        ROBOT->Posrobot.x+=9;
       i++;
        if (i==5)
        {
            i=0;
        }
        
        return i;
}

int robot2mouvemant(ROBOT2 *robot,SDL_Surface *ecran,int i2,SDL_Rect Posrobot)
{
  
  robot->Posrobot.x+=75;
  i2++;

  if (i2==5)
    i2=0;

if (robot->Posrobot.x==800)//rectangle +largeur rectangle (limite du robot)
  {
    robot->Posrobot.x=500; 
  }
return i2;
}

void   Testecran (Struct_robot *ROBOT)
{
    
    if (ROBOT->Posrobot.x>850)
        ROBOT->Posrobot.x=0;
    

}


void liberation(Struct_robot *ROBOT)
{
    int i=0;
    for (i=0;i<=9;i++)
    SDL_FreeSurface(ROBOT->robot[i]);
}

void liberation2(ROBOT2 *robot)
{
    int i=0;
        for (i=0;i<=9;i++)
    SDL_FreeSurface(robot->robot[i]);   
}




int main(int argc, char const *argv[])
{
    int i=0,i2=0,i3=0,A;
    Struct_robot ROBOT;
    ROBOT2 robot,robot1;
    SDL_Event event;
    SDL_Surface *ecran = NULL,*map = NULL,*RectangleRobot;
    SDL_Rect  positionmap,PosRectangleRobot;
    
    positionmap.x=0;
    positionmap.y=100;

    PosRectangleRobot.x=500;
    PosRectangleRobot.y=450;





         
    map=IMG_Load("map.png");
    RectangleRobot=IMG_Load("Rectangle.png");
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900, 700, 32, SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_RESIZABLE);
    //initialiser
    initialiser (&ROBOT);
    initialiser2(&robot);

    while (ROBOT.A)
    {
        SDL_PollEvent(&event);
        {
        if (event.type==SDL_QUIT)
            (ROBOT.A)=0;
        }
         //SDL_BlitSurface(RectangleRobot,NULL, ecran,&PosRectangleRobot);
    SDL_Flip(ecran);
         // i2=robot2mouvemant(&robot,ecran,i2,robot.Posrobot);
        //affichage2(&robot,ecran,i2,RectangleRobot,PosRectangleRobot);
        
        //deplacer robot
        i=Mouvemant(&ROBOT,ecran,i);
        
        //afficher
        affichage(&ROBOT,ecran,i,map,positionmap);
        Testecran(&ROBOT);
        
    }

   liberation(&ROBOT);
   liberation2(&robot);
   SDL_FreeSurface(map);
   SDL_Quit();


}