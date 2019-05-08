#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "personnage.h" 


void init_perso(  personage *per)

{
    per->perso[0] = IMG_Load("10.png");
    per->perso[1] = IMG_Load("20.png");
    per->perso[2] = IMG_Load("30.png");
    per->perso[3] = IMG_Load("40.png");
    per->perso[4] = IMG_Load("50.png");
    per->perso[5] = IMG_Load("60.png");
    per->perso[6] = IMG_Load("70.png");
    per->perso[7] = IMG_Load("80.png");
    per->perso[8] = IMG_Load("90.png");
    per->direction=0;

  per->velocity=0; 
  per->acceleration=0;
 
      per->positionperso.x =100;
    per->positionperso.y =450; 
}

void init_img2(image2 *img2)
{ 
   SDL_Surface * surfM = IMG_Load("mapmaske.png");
    
img2->back=IMG_Load("mapmaske.png");
img2->positiond2.x=0;//position x de bg
img2->positiond2.y=150;//position y de bg
}
int acceleration(personage *per,Uint32 dt,potion p)
{ int vitesse=10;
      p.px.x=250;
      p.px.y=370;
      
        if (per->positionperso.x>p.px.x)
         {
             vitesse=per->velocity/dt+per->acceleration;;
             

          
         }
         else
          vitesse=10;
        
       
        if (per->positionperso.x>p.px.x+400)
          vitesse=10;

 return vitesse;
}





SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{

SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch *y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
SDL_Color Get_Pixel32;
  
return (color);

}

void collision_perprisens1(image2 *img2,personage *per) // collision personage principale avec obstacle "right" 
{
    int verif=0;
    int i,j,test=0;
    SDL_Color couleur[1];

couleur[0]=GetPixel (img2->back, per->positionperso.x + per->positionperso.w-320,  per->positionperso.y + per->positionperso.h/2); // middle right(8)
couleur[1]=GetPixel (img2->back,(per->positionperso.x + per->positionperso.w)-320, per->positionperso.y +per->positionperso.h);// down right(7)
    printf("%d    %d   %d\n",couleur->r,couleur->b,couleur->g );
    


for(i=0;((i>2)&&(verif==0));i++)
    { 
        if((couleur[i].r==0) && ((couleur[i].g ==0) && (couleur[i].b == 0))) // objet noir 
        {
            verif=1;
            
            
        }
    }
if (verif==1)
         {
              per->positionperso.y=540;
         }
     
}

void display_perso(SDL_Surface *ecran,personage *per,int i)
{
SDL_BlitSurface(per->perso[i],NULL,ecran,&per->positionperso);

}

void  liberationPerso(personage *per)
{
  int i;
   for(i=0;i<=8;i++)
    SDL_FreeSurface(per->perso[i]);
}

void liberationMAP_Masque (image2 *img2)
{
  SDL_FreeSurface(img2->back);
}