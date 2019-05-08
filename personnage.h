#ifndef _jeu_H
#define _jeu_H_


typedef int bool;
enum { false, true };

typedef struct image2
{ 
    SDL_Rect positiond2;
    SDL_Surface* back;

}image2;

typedef struct personage
{
    SDL_Surface *perso[9];
    SDL_Rect positionperso;

    int direction;
    double velocity;
    double acceleration;
}personage;


typedef struct potion
{
    SDL_Rect px;
    SDL_Surface* backp;
}potion;



void init_img2(image2 *img2);
void init_perso(personage *per);
void display_perso(SDL_Surface *ecran,personage *per,int i);
void display2(SDL_Surface *ecran,image2 img2);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
void collision_perprisens1(image2 *img2,personage *per);
void  liberationPerso(personage *per);
void liberationMAP_Masque (image2 *img2);

#endif 