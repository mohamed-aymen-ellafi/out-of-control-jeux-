#ifndef _background_H
#define _backgroun_H_

typedef struct 
{ 
    SDL_Rect positiond;
        
SDL_Rect positionc;
SDL_Surface* back;
           
}MAP;


void initialiserMap (MAP *map);
 void affichageMap(SDL_Surface *ecran,MAP *map);
 void liberationMap(MAP *map);


#endif