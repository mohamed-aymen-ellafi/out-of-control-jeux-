#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h>
#include "menu.h"


 void initialiserAnimation(animation *ANIM,SDL_Surface *ecran)
 {
    int i;
    char image[300];
    ANIM->posfond.x=0;
    ANIM->posfond.y=0;
     
     for (i=0;i<=202;i++)
        {
            sprintf(image,"/home/ubuntu/Desktop/OC/menu/functMenu/cinematique/%d.png",i);
    ANIM->fond[i]=IMG_Load(image);
        
        SDL_BlitSurface(ANIM->fond[i],NULL,ecran,&ANIM->posfond);
                    SDL_Flip(ecran);

       }  
 }
  void libereranimation(animation *ANIM)
 {
    int i;
    for (i=0;i<=202;i++)
    {
        SDL_FreeSurface(ANIM->fond[i]);
    }

 }
 //******************************************************************************************************************************
 void initialiserMenu(MENU *menu)
 {    
    menu->positionMenuFond.x = 0;
    menu->positionMenuFond.y = 245;

    menu->positionhelp.x=0;
    menu->positionhelp.y=40;

    menu->positionsettings.x=0;
    menu->positionsettings.y=40;

    menu->positionmenuQuitter.x=180;
    menu->positionmenuQuitter.y=200;
  
    menu->posfond.x=0;
    menu->posfond.y=40;

    menu->posGAMEMODE.x=0;
    menu->posGAMEMODE.y=50;

    menu->posGAME.x=0;
    menu->posGAME.y=50;

           
            
      

         

}

void afficherfond(SDL_Surface *ecran,MENU *menu)
{
 menu->fond=IMG_Load("6.png");
  SDL_BlitSurface(menu->fond,NULL,ecran,&menu->posfond);
}

//MUSIQUE 
void intiMUSIC(MENU *menu)
{
    menu->backgroundSound = Mix_LoadMUS("game.mp3");
    menu->button=Mix_LoadWAV("bouton.wav");
}

void PlayMusic(MENU *menu)
{
    Mix_PlayMusic(menu->backgroundSound,-1);
}

void WAVmusic(MENU *menu,int *x)
{
   if (*x==1)
    Mix_PlayChannel(1,menu->button,0);
  else if (*x==2)
    Mix_PlayChannel(1,menu->button,0);
  else if (*x==3)
    Mix_PlayChannel(1,menu->button,0);
  else if (*x==4)
    Mix_PlayChannel(1,menu->button,0);
}

void libererMUSIC(MENU *menu)
{

     Mix_FreeMusic(menu->backgroundSound);
     Mix_FreeChunk(menu->button);
      Mix_CloseAudio();
}

void updateMenu(SDL_Surface *ecran,int *i,int *i_settings,int *sauvgarde_settings,int *soundSpace,int *soundMusic,int *x,SDL_Event event,int *continuer,int *i_help,int *i_quit,int *i_GAME_MODE,int *i_GAME)
{
        SDL_WaitEvent(&event); 
        switch(event.type) 
        {
            case SDL_QUIT: 
                *continuer = 0;
                break;
         case SDL_KEYDOWN:
                 SDL_EnableUNICODE(1);
                 switch(event.key.keysym.unicode)
                 {
                  case 15:
                  system("xdg-open https://aymenthedon.wixsite.com/out-of-control?fbclid=IwAR1KBVlepADYniI7W3x_lZP5a7x7ILUa--yhFc7XeqHOUxxee16h379iUP8");
                  break;

                 }

            switch(event.key.keysym.sym)
            {   
             case SDLK_UP:
                if(*i==1)
                    *i=4;
                else if (*i==6)
                {
                    if (*i_settings==2)
                        {
                            *i_settings=1;
                        }
                    else  *i_settings=2  ;
                }
                else if (*i==8)
                {
                  if (*i_GAME_MODE==2)
                    *i_GAME_MODE=1;

                  else *i_GAME_MODE=2;
                }
                else if (*i==9)
                {
                  if (*i_GAME==2)
                    *i_GAME=1;

                  else *i_GAME=2;
                }
                else
                    (*i)--;
                break;

            case SDLK_DOWN:
                  
                if(*i==4)
                    *i=1;
                else if (*i==6)
                {
                      if (*i_settings==1)
                        {
                            *i_settings=2;
                        }
                    else  *i_settings=1;
                }
                else if (*i==8)
                {
                  if (*i_GAME_MODE==1)
                    *i_GAME_MODE=2;

                  else *i_GAME_MODE=1;
                }
               else if (*i==9)
                {
                  if (*i_GAME==1)
                    *i_GAME=2;

                  else *i_GAME=1;
                }
                else
                    (*i)++;
                break;
               case SDLK_f:
               //SDL_WINDOW_FULLSCREEN;
                  SDL_WM_ToggleFullScreen(ecran);
                  break;

            case SDLK_RETURN:
                if((*i)==1)
                {
                    //GAME();
                    (*x)=1; 
                    (*i)=8;
                    printf("%d\n",*i );
                }
                if (*i==8)
                {
                  *i=9;
                }
                /*if (*i==8)
                {
                  (*i)=9;
                } */
                if ((*i==9)&&(*i_GAME==1))
                {
                  Mix_CloseAudio();
                  GAME();
                }
                if((*i)==2)
                {
                    (*x)=2;
                    *i=5;
                    
                }
                if((*i)==3)
                {
                    *i=6;
                    (*x)=3;
                    

                }
                if((*i)==4)
                {
                    (*x)=4;
                }
                
                break;//break sdlkreturn
                case SDLK_s:
                if (*i==6)
                  {
                    //*sauvgarde_settings=1;
                    *i=1;

                  }   
                break;
              case SDLK_ESCAPE:
              if (*i==6)
                   {
                    //*sauvgarde_settings=1;
                    //(*soundSpace)=1;
                    SDL_PauseAudio(0);
                    *i=1;
                  }
                else if (*i==5)
                {
                  *i_help=0;
                  

                }
              
             
                else if (*i==9)
                  *i=8;
              break;
              case SDLK_SPACE:
              if (*i_settings==1&&*soundSpace==1)
              {
                *soundSpace=0;
                SDL_PauseAudio(0);
              }
              else if (*i_settings==2&&*soundMusic==1)
              {
                *soundMusic=0;
                SDL_PauseAudio(1);
              }
              else if (*i_settings==1&&*soundSpace==0)
              {
                *soundSpace=1;
                SDL_PauseAudio(0);
              }
              else if (*i_settings==2&&*soundMusic==0)
              {
                *soundMusic=1;
                SDL_PauseAudio(0);
              }
               
              break;
              case SDLK_y:
              if (*x==4)
              {
                *i_quit=1;
                SDL_Delay(200);
                *continuer=0;
              }
              break;
              case SDLK_n:
              if (*x==4)
                *i=1;
              break;
            }
            break;

            case SDL_MOUSEMOTION:
            if (event.motion.x>325 && event.motion.x<455 && event.motion.y>350 && event.motion.y<392)
            {
                (*i)=1;
                break;
                
            }

            else if (event.motion.x>325 && event.motion.x<455 && event.motion.y>408 && event.motion.y<445)
            {
                (*i)=2;
               
                break;
                
            }
            else if (event.motion.x>325 && event.motion.x<455 && event.motion.y>466 && event.motion.y<500)
            {
                (*i)=3;
                break;
                
            }
            else if (event.motion.x>325 && event.motion.x<455 && event.motion.y>518 && event.motion.y<547)
            {
                (*i)=4;
                break;
                
            }

           
            break; 
            
            case SDL_MOUSEBUTTONUP:
            switch(event.button.button)
            {

            case SDL_BUTTON_LEFT :

                if((*i)==1)
                {
                    (*x)=1;
                    *i=8;
                    
                }
                if((*i)==2)
                {
                  (*i)=5;
                  (*x)=2;
                }
                if((*i)==3)
                {
                  (*i)=6;
                  (*x)=3;                  
                }
                if((*i)==4)
                {
                  (*x)=4;
                  *continuer=0;
                }
               
                break;
            }
            break;
        }

  
}


void afficherMenu(int *i,int *i_settings,int *sauvgarde_settings,int *soundSpace,int *soundMusic,MENU *menu,SDL_Surface *ecran,int *i_help,int *i_quit,int *x,int *i_GAME_MODE,int *i_GAME)
{       
        if(*i==1)
        {
          menu->menuFond[0]= IMG_Load("menu1[play].png");            
            SDL_BlitSurface(menu->menuFond[0], NULL, ecran, &menu->positionMenuFond);
            SDL_Flip(ecran);   
        }

        if(*i==2)
        {
          menu->menuFond[1]= IMG_Load("menu1[help].png");           
            
            SDL_BlitSurface(menu->menuFond[1], NULL, ecran, &menu->positionMenuFond);
           SDL_Flip(ecran);         
        }
        if(*i==3)
        {
            menu->menuFond[2]= IMG_Load("menu1[settings].png");
           
            SDL_BlitSurface(menu->menuFond[2], NULL, ecran, &menu->positionMenuFond);
           SDL_Flip(ecran);

        }
        if(*i==4)
         {
           menu->menuFond[3]= IMG_Load("menu1[quit].png"); 

            SDL_BlitSurface(menu->menuFond[3], NULL, ecran, &menu->positionMenuFond);
                 SDL_Flip(ecran);
                  if (*x==4)  
                  {
                    menu->quit=IMG_Load("no.png");
                     SDL_BlitSurface(menu->quit,NULL,ecran,&menu->positionmenuQuitter);
                     SDL_Flip(ecran);
                 
                  }
                  if (*i_quit==1)  
                  {
                    menu->quit=IMG_Load("yes.png");
                     SDL_BlitSurface(menu->quit,NULL,ecran,&menu->positionmenuQuitter);
                 SDL_Flip(ecran);
                  }

                  if (*i_quit==0)  
                  {
                    menu->quit=IMG_Load("no.bmp");
                     SDL_BlitSurface(menu->quit,NULL,ecran,&menu->positionmenuQuitter);
                 SDL_Flip(ecran);

                  }
                  
         }
          if (*i==5)
            {

              if (*i_help==1)
              {
                   menu->help=IMG_Load("help1.png");
 
            SDL_BlitSurface(menu->help, NULL, ecran, &menu->positionhelp);
                 SDL_Flip(ecran);
                }
                else if (*i_help==0)
                {
                  menu->help=IMG_Load("help2.png");
 
            SDL_BlitSurface(menu->help, NULL, ecran, &menu->positionhelp);
                  SDL_Flip(ecran);
                  SDL_Delay(100);
                  *i=1;
                }
                *i_help=1;

            }
            
          if (*i==6)
          {                           
            if (*soundSpace==1&&*soundMusic==1)
                            {
                            menu->settings=IMG_Load("settings1.png");
                            SDL_BlitSurface(menu->settings,NULL,ecran,&menu->positionsettings);
                SDL_Flip(ecran);
                            //SDL_PauseAudio(0);
                            }
               
               else if (*soundSpace==0&&*soundMusic==0)
                        {
                             menu->settings=IMG_Load("settings4.png");
                            SDL_BlitSurface(menu->settings,NULL,ecran,&menu->positionsettings);
                            SDL_Flip(ecran);
                             //SDL_PauseAudio(1);
                        } 
                else if (*soundMusic==0&&*soundSpace==1)
                        {
                            menu->settings=IMG_Load("settings3.png");
                            SDL_BlitSurface(menu->settings,NULL,ecran,&menu->positionsettings);
                            SDL_Flip(ecran);
                            //SDL_PauseAudio(1);
                        }
                else if (*soundMusic==1&&*soundSpace==0)
                        {
                            
                            menu->settings=IMG_Load("settings2.png");
                            SDL_BlitSurface(menu->settings,NULL,ecran,&menu->positionsettings);
                            SDL_Flip(ecran);
                           // SDL_PauseAudio(0);
                        }
                  }
                  if (*i==8)
                  {
                    if ((*i_GAME_MODE)==1)
                            {
                              menu->GAMEMODE[0]=IMG_Load("play2-01.png");
                              SDL_BlitSurface(menu->GAMEMODE[0], NULL, ecran, &menu->posGAMEMODE);
                         SDL_Flip(ecran);
                            } 
                            else if ((*i_GAME_MODE)==2)
                            {
                              menu->GAMEMODE[1]=IMG_Load("play1-01.png");
                              SDL_BlitSurface(menu->GAMEMODE[1], NULL, ecran, &menu->posGAMEMODE);
                            SDL_Flip(ecran);
                            }

                  }
                  if (*i==9)
                   {
                    if ((*i_GAME)==1)
                            {
                              menu->GAME[0]=IMG_Load("newgame-01.png");
                              SDL_BlitSurface(menu->GAME[0], NULL, ecran, &menu->posGAME);
                          SDL_Flip(ecran);
                            } 
                            else if ((*i_GAME)==2)
                            {
                              menu->GAME[1]=IMG_Load("loadgame-01.png");
                              SDL_BlitSurface(menu->GAME[1], NULL, ecran, &menu->posGAME);
                            SDL_Flip(ecran);
                            }

                  } 
} 
void libererationMENU (MENU *menu)
{
     int i;
        for (i=0;i<=3;i++)
    SDL_FreeSurface(menu->menuFond[i]);
    SDL_FreeSurface(menu->fond);
    //SDL_FreeSurface(menu->quit);
    SDL_FreeSurface(menu->settings);
            for (i=0;i<=1;i++)
    SDL_FreeSurface(menu->GAMEMODE[i]);
  for (i=0;i<=1;i++)
    SDL_FreeSurface(menu->GAME[i]);
}