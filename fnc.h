#ifndef FNC_H_
#define FNC_H_

#define FPS 60
#define ACCELX 0
#define ACCELY 0
#define SCREEN_W 1000
#define SCREEN_H 400
typedef int bool;
enum { false, true };

typedef struct image
{ 
	SDL_Rect positiond;
    SDL_Surface* back;
    SDL_Rect posrect;
           
}image;
typedef struct image2
{ 
	SDL_Rect positiond2;
    SDL_Surface* back;

}image2;


typedef struct personage

{

	SDL_Surface *perso[9];
    SDL_Rect positionperso;

	int direction; //0:right 1:left 2:up
	int moving; //0:not moving 1:moving
	float Mass;

	double velocity;
	double acceleration;

}personage;
typedef struct potion

{

    SDL_Rect px;

}potion;

void init_img2(image2 *img2);
void init_img(image *img);
void display(SDL_Surface *ecran,image *img,personage *per);
void init_perso(personage *per);
void display_perso(SDL_Surface *ecran,personage *per,int i);
int input(personage *per,int i,int *continuer,Uint32 dt);
void display2(SDL_Surface *ecran,image2 img2);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int collision_perprisens1(image2 *img2,personage *per); 
int chage (personage *per ,image2 *img2,image *img);
void jump (personage *per);
int acceleration(personage *per,Uint32 dt);

//int acceleration (personage *per,SDL_Rect px);













#endif
