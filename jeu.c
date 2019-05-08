#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>  
#include "jeu.h"

void  GAME()
{
    int i_Robot=0,i_Perso=0,i3=0,A,scroll,i_enigmes=1;
    Struct_robot ROBOT;
    Uint32 dt;
    potion p;
    MAP map;
    image2 img2;
    personage per;
    Struct_robotAtt robotATTAQUE;
    SDL_Event event;
    SDL_Surface *ecran = NULL,*RectangleRobot;
    SDL_Rect  positionmap,PosRectangleRobot;
    
    positionmap.x=0;
    positionmap.y=100;

    PosRectangleRobot.x=300;
    PosRectangleRobot.y=50;

    SDL_Surface *GAMEOVER=IMG_Load("GAMEOVER.png");
    SDL_Rect posGAMEOVER;
    posGAMEOVER.x=280;
    posGAMEOVER.y=220;
        int  continuerJeu=1,*MV=0,d=0;

    RectangleRobot=IMG_Load("Rectangle.png");
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(900,700,32, SDL_HWSURFACE | SDL_DOUBLEBUF| SDL_RESIZABLE);
    //initialiser
    initialiser (&ROBOT);
    initialiserMap (&map);
     init_img2(&img2);
     init_perso(&per);
     initialiserattack(&robotATTAQUE);
     SDL_EnableKeyRepeat(100,100);
    while (continuerJeu==1)
    {
      d=AI(&per,&ROBOT,ecran);
        SDL_PollEvent(&event);
       switch(event.type)
          {
            case SDL_QUIT:
            continuerJeu= 0;
            break;

          }
          if (d<0)
         {
          SDL_BlitSurface(GAMEOVER,NULL,ecran,&posGAMEOVER);
          SDL_Flip(ecran);
          SDL_Delay(2000);   
        continuerJeu=0;
      }
        affichageMap(ecran,&map);
i_Robot=Mouvemant(&ROBOT,ecran,i_Robot,&MV);
       affichage(&ROBOT,&robotATTAQUE,ecran,i_Robot,d);
      
      i_Perso=input(&per,i_Perso,&continuerJeu,ecran,&map,&MV);
            //per.positionperso.x+=vitesse;
      //per.positionperso.x=collision_perprisens1(&img2,&per);            
      display_perso(ecran,&per,i_Perso);
            //jump (&per); 
       // scrolling(&ROBOT,&map);//(Struct_robot *ROBOT,MAP *map
      
         if ((map.positionc.x==1180)||(map.positionc.x==4350))
         {
         i_enigmes=MAINenigme(i_enigmes);
          map.positionc.x+=10;
         }
          printf("%d\n",map.positionc.x);

                 //SDL_BlitSurface(RectangleRobot,NULL, ecran,&PosRectangleRobot);
    //SDL_Flip(ecran);
          //i2=robot2mouvemant(&robot,ecran,i2,robot.Posrobot,&map);
 
        //deplacer robot
            
       // i_Robot=Mouvemant(&ROBOT,ecran,i_Robot,&map);
        
       
        //afficher
                 
       
      //if (map.PosRectMap.x==1600||map.PosRectMap.x==3200)
       //affichage2(&robot,ecran,i2,RectangleRobot,PosRectangleRobot);
       
        //Testecran(&ROBOT);
        SDL_Flip(ecran);
           



    } 

   liberation(&ROBOT,&robotATTAQUE);
   liberationMap (&map);
   liberationPerso(&per);
   liberationMAP_Masque (&img2);
   //SDL_FreeSurface(map);
   //SDL_Quit();
//return continuerJeu;

}

int  Mouvemant(Struct_robot *ROBOT,SDL_Surface *ecran,int i,int *MV)
{
  ROBOT->Posrobot.y=420;

  if ((*MV)==0)                
      {
       ROBOT->Posrobot.x+=4;
      i++;
      }
  else 
     i++;
        if (i==5)
        {
            i=0;
        }
        
        return i;
}
int scrolling (personage *per,MAP *map,int i)
  {
  if(per->positionperso.x<400)
  {
  per->positionperso.x+=50; 
  }
  i++;


   if (per->positionperso.x>=400)
  {
  map->positionc.x+=20;
  
  }
          
  return i; 

  }

  int input(personage* per,int i,int *continuer ,SDL_Surface *ecran,MAP *map,int *MV)
{ 

  *MV=0;
SDL_Event event;
SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_f:
             SDL_WM_ToggleFullScreen(ecran);
             break;
                case SDLK_SPACE:
                *MV=1;
                    i=0;
                per->positionperso.y-=90;
                /*if ( per->positionperso.x<400)
                {
                i=scrolling (per,map,i);
                }*/
                //if ( per->positionperso.x>=400)
                  i=scrolling (per,map,i);
                i++;
                if (i>=8)
                    i=0;

                break; 
              
                
                case SDLK_RIGHT:
               *MV=1;
                if (i>=8)
                    i=0;
                   i=scrolling (per,map,i);
              
                //per->positionperso.x+=per->positionperso.x+dt;
              // per->positionperso.x+=per->velocity/dt+per->acceleration;
              
                i++;
                break;              
           }
           break;
           case SDL_KEYUP:
                   if (per->positionperso.y<450)
            { 
                per->positionperso.y=450;
           }
           break;
              case SDL_MOUSEBUTTONUP:
            switch(event.button.button)
            {

            case SDL_BUTTON_LEFT :

                
                      i=0;
                per->positionperso.x +=100;
                per->positionperso.y-=50;
                i++;
             
                    break;

            case SDL_BUTTON_RIGHT :

             if (i>=8)
                    i=0;

                //per->positionperso.x+=per->positionperso.x+dt;
              // per->positionperso.x+=per->velocity/dt+per->acceleration;
              per->positionperso.x+=10;
                i++;

                    break;

                
                }
        
        }
               
return i;
}

int  AI(personage *per,Struct_robot *robot1,SDL_Surface *ecran)
{
    int i2;
    int distance = per->positionperso.x-robot1->Posrobot.x;  
return distance;
}


