#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fnc.h"
void  main(SDL_Surface *ecran)
{
    personage per;
    image2 *bg;
    SDL_Event event;
     SDL_Rect px;
      px.x=250;
      px.y=370;
      Uint32 t_prev, dt=1; 

    int continuer=1,i=0,t=0,x,y;
    int vitesse =10,a;

    SDL_Surface* ob;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); 
    ecran=SDL_SetVideoMode(900, 700, 32,SDL_HWSURFACE);
    image img;
    image2 img2;

    init_perso(&per);
    
    init_img(&img);
    init_img2(&img2);
    ob=IMG_Load("o.png");
    SDL_EnableKeyRepeat(100,100); 
    while (continuer)
    { t_prev = SDL_GetTicks();
      i=input(&per,i,&continuer,dt);
          /* per.positionperso.x+=vitesse;
            i++;*/
            if (i==9)
            {
            i=0;
            }
        SDL_PollEvent(&event);
        switch(event.type)
          {
            case SDL_QUIT:
            continuer = 0;
            break;
          }

          SDL_Delay(100);
          
                    display(ecran,&img,&per);


          display_perso(ecran,&per,i);
         if (per.positionperso.x<px.x)
{
  SDL_BlitSurface(ob, NULL, ecran, &px);
}

          jump ( &per);
          SDL_Flip(ecran);
          dt = SDL_GetTicks()-t_prev;
            if (1000/FPS>dt)
            SDL_Delay(1000/FPS-dt);
                      // collision_perprisens1(&img2,&per); 


         if (per.positionperso.x>800)
          per.positionperso.x=0;
              
    }    


   for(i=0;i<=9;i++)
    SDL_FreeSurface(per.perso[i]);
}






