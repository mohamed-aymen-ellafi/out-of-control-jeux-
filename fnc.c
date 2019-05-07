#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"

void init_img(image *img)
{
SDL_Surface *surf = IMG_Load("bgg.png");

img->back=IMG_Load("bgg.png");
img->positiond.x=0;
img->positiond.y=150;
img->posrect.x=0;
img->posrect.y=800;

}
void init_img2(image2 *img2)
{ 
    SDL_Surface * surfM = IMG_Load("bggx.png");
    
img2->back=IMG_Load("bggx.png");
img2->positiond2.x=0;//position x de bg
img2->positiond2.y=150;//position y de bg


//return img2;
}


void display(SDL_Surface *ecran,image *img,personage *per)
{ if (per->positionperso.x>800)
          img->posrect.x+=800;
        
SDL_BlitSurface(img->back,NULL,ecran,&img->positiond);//afficher l image
}
void display2(SDL_Surface *ecran,image2 img2)
{
SDL_BlitSurface(img2.back,NULL,ecran,&img2.positiond2);//afficher l image
}


int acceleration(personage *per,Uint32 dt)
{ int vitesse=30;
   SDL_Rect px;
      px.x=250;
      px.y=370;
        if (per->positionperso.x>px.x)
         {
             vitesse=per->velocity/dt+per->acceleration;
             

          
         }
         else
          vitesse=10;
        
       
        if (per->positionperso.x>px.x+400)
          vitesse=10;

 return vitesse;
}
int input(personage* per,int i,int *continuer ,Uint32 dt)
{ int t,vitesse=10;

  vitesse=acceleration(per,dt);
          per->velocity=50;
          per->direction=50;    
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
             
                case SDLK_a :
                i=0;
                per->positionperso.x +=100;
                per->positionperso.y-=50;
                i++;
            
                break; 
                case SDLK_UP:
                i=0;
     

                per->positionperso.y-=50;
                i++;
                break;
                case SDLK_RIGHT:
                if (i>=9)
                    i=0;
              per->acceleration+=1;
              per->direction=0;
                //per->positionperso.x+=per->positionperso.x+dt;
              // per->positionperso.x+=per->velocity/dt+per->acceleration;
              per->positionperso.x+=vitesse;
                i++;


                break;

               
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

                
               if (i>=9)
                    i=0;
              
                per->positionperso.x+=vitesse;

                i++;

                    break;

                
                }
        
        }
               
return i;
}
void jump (personage *per)
{
                 if (per->positionperso.y<360)
            { 
                per->positionperso.y=360;
           }
}

void init_perso(  personage *per)

{

  

    per->perso[0] = IMG_Load("1.png");

per->perso[1] = IMG_Load("2.png");

    per->perso[2] = IMG_Load("3.png");

    per->perso[3] = IMG_Load("4.png");

    per->perso[4] = IMG_Load("5.png");

    per->perso[5] = IMG_Load("6.png");

    per->perso[6] = IMG_Load("7.png");

    per->perso[7] = IMG_Load("6.png");

    per->perso[8] = IMG_Load("5.png");

    per->direction=0;

  per->velocity=0; //velocity=0
  per->acceleration=0;
  per->Mass=70;
  per->moving=0;

      per->positionperso.x = 0;
    per->positionperso.y = 360; 
   


     


}
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{

SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
SDL_Color Get_Pixel32;
  
return (color);

}

int collision_perprisens1(image2 *img2,personage *per) // collision personage principale avec obstacle "right" 
{
    int verif=0;
    int i,j,test=0;
    SDL_Color couleur[7];

couleur[0]=GetPixel (img2->back, per->positionperso.x + per->positionperso.w-320 ,  per->positionperso.y + per->positionperso.h/2); // middle right(8)
couleur[1]=GetPixel (img2->back,(per->positionperso.x + per->positionperso.w)-320, per->positionperso.y +per->positionperso.h);// down right(7)
couleur[2]=GetPixel (img2->back,(per->positionperso.x + per->positionperso.w/2)-320, per->positionperso.y +per->positionperso.h);// down right(7)

    printf("%d    %d   %d\n",couleur->r,couleur->b,couleur->g );
    


for(i=0;i<3&&(verif==0);i++)
    { 
        if((couleur[i].r == 0) && ((couleur[i].g ==0) && (couleur[i].b == 0))) // objet noir 

        {
            verif=1;
            
            
        }
       
    }
          if (verif==1)
         {
              per->positionperso.y=450;

         }

    
    return verif;
     
}

void display_perso(SDL_Surface *ecran,personage *per,int i)
{
SDL_BlitSurface(per->perso[i],NULL,ecran,&per->positionperso);
}







