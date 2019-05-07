#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "AI.h"

void initialiserpoint (point *point)
{
    point->Pospoint.x=200;
    point->Pospoint.y=115;
    point->point=IMG_Load("point.png");
}

void initialiser(Struct_robot *ROBOT)
{
     ROBOT->Posrobot.x=0;
     ROBOT->Posrobot.y=250;
    ROBOT->robot[0]= IMG_Load("2.png");
    ROBOT->robot[1]= IMG_Load("3.png");
    ROBOT->robot[2]= IMG_Load("4.png");
    ROBOT->robot[3]= IMG_Load("5.png");
    ROBOT->robot[4]= IMG_Load("6.png");
    ROBOT->robot[5]= IMG_Load("7.png");
    ROBOT->robot[6]= IMG_Load("8.png");
    ROBOT->robot[7]= IMG_Load("9.png");
        
}
void initialiserattack(Struct_robotAtt *ROBOTA)
{
     ROBOTA->Posrobot.x=0;
     ROBOTA->Posrobot.y=250;
    ROBOTA->robotattack[0]= IMG_Load("a.png");
    ROBOTA->robotattack[1]= IMG_Load("b.png");
    ROBOTA->robotattack[2]= IMG_Load("c.png");
    ROBOTA->robotattack[3]= IMG_Load("d.png");
    ROBOTA->robotattack[4]= IMG_Load("e.png");
    ROBOTA->robotattack[5]= IMG_Load("f.png");
    ROBOTA->robotattack[6]= IMG_Load("g.png");
        
}

void initialiser2(ROBOT2 *robot)
{
     robot->Posrobot.x=490;
     robot->Posrobot.y=285;
     robot->direction=1; 
    robot->robot[0]= IMG_Load("A.png");
    robot->robot[1]= IMG_Load("B.png");
    robot->robot[2]= IMG_Load("C.png");
    robot->robot[3]= IMG_Load("D.png");
    robot->robot[4]= IMG_Load("E.png");    
}

void initialiserminiMap (miniMAP *minimap)
{
    minimap->PosminiMap.x=400;
    minimap->PosminiMap.y=100;
    minimap->PosRectminiMap.x=0;
    minimap->PosRectminiMap.y=0;
    minimap->minimap=IMG_Load("minimap.png");
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
void affichage(Struct_robot *ROBOT,Struct_robotAtt *ROBOTA,SDL_Surface *ecran,int i,SDL_Surface *map,SDL_Rect positionmap,SDL_Surface *minimap,SDL_Rect positionminimap,int distance)
{
      
    SDL_Delay(100);
    SDL_BlitSurface(map,NULL,ecran,&positionmap);
        SDL_BlitSurface(minimap,NULL,ecran,&positionminimap); 
    if (distance>100)
    SDL_BlitSurface(ROBOT->robot[i],NULL, ecran,&ROBOT->Posrobot);
    if (distance<100)

            SDL_BlitSurface(ROBOTA->robotattack[i],NULL, ecran,&ROBOT->Posrobot);

     //SDL_Flip(ecran);
}

void affichage2(ROBOT2 *robot,SDL_Surface *ecran,int i,SDL_Surface *RectangleRobot,SDL_Rect PosRectangleRobot,point *point)
{      
    SDL_Delay(1);
    SDL_BlitSurface(RectangleRobot,NULL,ecran,&PosRectangleRobot);
        SDL_Delay(1);

        SDL_BlitSurface(point->point,NULL,ecran,&point->Pospoint); 
 
    SDL_BlitSurface(robot->robot[i],NULL, ecran,&robot->Posrobot);
     //SDL_Flip(ecran);
}

int  Mouvemant(Struct_robot *ROBOT,SDL_Surface *ecran,int i)
{
        ROBOT->Posrobot.y=250;
        ROBOT->Posrobot.x+=10;
       i++;
        if (i==5)
        {
            i=0;
        }
        
        return i;
}
void Mouvemantpoint(point *point,SDL_Surface *ecran,miniMAP *MP)
{
        point->Pospoint.y=125;
                SDL_Delay(1);

        point->Pospoint.x+=1;
        if (point->Pospoint.x==MP->PosRectminiMap.x+535)
                   point->Pospoint.x=200;
 
       
}

int robot2mouvemant(ROBOT2 *robot,SDL_Surface *ecran,int i2,SDL_Rect Posrobot)
{
  if(robot->direction==1)
  {
  robot->Posrobot.x+=4;
  i2++;

  if (i2==5)
    i2=0;

if (robot->Posrobot.x==530)//rectangle +largeur rectangle (limite du robot)
  {
    robot->direction=0; 
  }
  }
  else 
  {
    robot->Posrobot.x-=4;
  i2++;

  if (i2==5)
    i2=0;

if (robot->Posrobot.x<=480)//rectangle +largeur rectangle (limite du robot)
  {
    robot->direction=1; 
  }
  }
return i2;
}
int  Mouvemantattack(ROBOT2 *robot,SDL_Surface *ecran,int i2,SDL_Rect Posrobot)
{
        
        robot->Posrobot.x-=10;
        printf("Posrobot = %d \n",robot->Posrobot.x );
       i2++;
        if (i2==5)
        {
            i2=0;
        }
        
        return i2;
}

void   Testecran (Struct_robot *ROBOT)
{
    
    if (ROBOT->Posrobot.x>800)
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

int  AI(ROBOT2 *robot2,Struct_robot *robot1,SDL_Surface *ecran)
{
    int i2;
    int distance = robot2->Posrobot.x - robot1->Posrobot.x;
    printf("%d \n",distance);
   if(distance > 200)//waiting
    {
      robot2->state=WAITING;
      //i2=robot2mouvemant(robot2,ecran,i2,robot2->Posrobot);
    }
    else if (distance <= 200)//following
    {
        robot2->state=ATTACKING;
        //i2=Mouvemantattack(robot2,ecran,i2,robot2->Posrobot);
    }
    switch (robot2->state)
    {
        case WAITING:
        {
           i2=robot2mouvemant(robot2,ecran,i2,robot2->Posrobot);
           break; 
        }
        case ATTACKING:
        {
            i2=Mouvemantattack(robot2,ecran,i2,robot2->Posrobot);
            break;
        }
    }
return distance;
}



