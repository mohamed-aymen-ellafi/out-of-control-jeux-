#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "background.h"

void initialiserMap (MAP *map)
{
    map->positiond.x=0;
    map->positiond.y=100;

    map->positionc.x=0;
    map->positionc.y=0;
    map->positionc.h=700;
    map->positionc.w=900;

    map->back=IMG_Load("map.png");
}


/*SDL_Rect  scrolling (Struct_robot *ROBOT,MAP *map)
{
    if (ROBOT->Posrobot.x>750)
         {
           ROBOT->Posrobot.x=map->PosMap.x;
            (map->PosRectMap.x)+=800;
            (map->PosRectMap.y)=0;           
         }
         return map->PosRectMap;
         
}*/
/*void affichageMap()
{
    SDL_Delay(100);
    
    SDL_Flip(ecran);
}*/
  
void affichageMap(SDL_Surface *ecran,MAP *map)
{
SDL_BlitSurface(map->back,&map->positionc,ecran,&map->positiond);
}




void liberationMap(MAP *map)
{
    SDL_FreeSurface(map->back);
}


