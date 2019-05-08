#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"
//--------------------------------------------------------------------------------------------------------------------------------
int MAINenigme(int i)
{
enigmes E;
init(&E);
E.i=i;
//INITIALISATION DES POSITIONS
init_position(&(E).positionFond , &(E).positionEnigme, &(E).posQuestion, &(E).posR1, &(E).posR2, &(E).posR3,&(E).posR4);
//(E).ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
//INITIALISATION SONS
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
init_son((E).backgroundSound,(E).button,(E).win,(E).lose);
//INIT TEXTE
TTF_Init();
(E).police = TTF_OpenFont("UbuntuMono.ttf", 14);
//SDL_WM_SetIcon(IMG_Load ("sdl_icone.bmp"), NULL);

//RECUPERATION DES BONNES REPONSES 
recuperation_tabRep(E.reponse);
//1ere recuperation des enigmes;
recuperation_texte(E.qcm, E.rep1, E.rep2, E.rep3, E.rep4, E.i);
/* Chargement d'un PNG avec IMG_LoadCelui-ci est automatiquement rendu transparent car les informationsdetransparence sont codées à l'intérieur du fichier PNG */
prem_affich((E).ecran,(E).enigme,(E).positionEnigme);
//1er affichage des enigmes
affichage_enigmes((E).ecran, (E).question, (E).r1, (E).r2, (E).r3, (E).r4, (E).qcm, (E).rep1, (E).rep2, E.rep3, E.rep4, (E).police, E.couleurNoire, E.posQuestion, E.posR1, E.posR2, E.posR3, E.posR4);

while (E.continuer)
{
E.choix=0;
E.valid=0;
recuperation_texte(E.qcm, E.rep1, E.rep2, E.rep3, E.rep4, E.i);
deplacement_selection(&(E).choix, &(E).ligne, &(E).son, &(E).continuer, E.button);
update_affichage(E.choix, E.ligne, E.son, E.positionEnigme, E.ecran, E.imageDeFond, E.enigme,E.positionFond);
affichage_enigmes(E.ecran, E.question, E.r1, E.r2, E.r3, E.r4, E.qcm, E.rep1, E.rep2, E.rep3, E.rep4, E.police, E.couleurNoire, E.posQuestion, E.posR1, E.posR2, E.posR3, E.posR4);
validation(&(E).continuer,E.choix, &(E).valid, E.i, E.ligne, E.reponse, E.positionEnigme, E.ecran, E.youWin, E.gameOver, E.win, E.lose);
attente(&(E).ctn,&(E).continuer,&(E).i, E.choix,E.valid, E.button, E.event);
}
//liberationEnigmes(E.imageDeFond, E.enigme, E.question, E.r1, E.r2, E.r3, E.r4, E.youWin, E.gameOver, E.backgroundSound, E.button, E.win, E.lose, E.police);
//SDL_Quit();
//E.continuer=0;
return E.i;
}

void init_position(SDL_Rect *positionFond , SDL_Rect *positionEnigme,SDL_Rect *posQuestion, SDL_Rect *posR1, SDL_Rect *posR2, SDL_Rect *posR3,SDL_Rect *posR4)
{
positionFond->x = 0;
positionFond->y = 0;
positionEnigme->x = (800/2)-(500/2);
positionEnigme->y = (600/2)-(300/2);
posQuestion->x=166.5;
posQuestion->y=194.5;
posR1->x=295.5;
posR1->y=264.5;
posR2->x=295.5;
posR2->y=305.5;
posR3->x=295.5;
posR3->y=356.5;
posR4->x=295.5;
posR4->y=402.5;
}
//--------------------------------------------------------------------------------------------------------------------------------
void init_son(Mix_Music* backgroundSound,Mix_Chunk* button,Mix_Chunk *win,Mix_Chunk *lose)
{

backgroundSound = Mix_LoadMUS("game.mp3");
button=Mix_LoadWAV("bouton.wav");
win=Mix_LoadWAV("ff-bell.wav");
lose=Mix_LoadWAV("fail.wav");
}
//--------------------------------------------------------------------------------------------------------------------------------
void attente(int *ctn, int *continuer, int *i, int choix, int valid, Mix_Chunk* button, SDL_Event event)
{

if(choix!=0)
{
(*ctn)=1;
 while(*ctn)
 {
    SDL_WaitEvent(&event);
    switch(event.type)
     {
        case SDL_QUIT: /* Si c'est un événement QUITTER*/
                Mix_PlayChannel(-1,button,0);
                (*continuer)=0;
                (*ctn)=0;
           break;
        case SDL_KEYDOWN:
           Mix_PlayChannel(-1,button,0);
           if(event.key.keysym.sym==SDLK_RETURN)
             {
                (*ctn)=0;
                (*continuer)=0;
             }
         break;
       case SDL_MOUSEBUTTONDOWN:
           Mix_PlayChannel(-1,button,0);
           if(event.button.button==SDL_BUTTON_LEFT)
            {
                (*ctn)=0;
                (*continuer)=0;
             }
        break; 
     }
 }
} 
 if(choix!=0 && valid!=0)
      {
          (*i)++;
          (*continuer)=0;
      }
}
//--------------------------------------------------------------------------------------------------------------------------------
void prem_affich(SDL_Surface *ecran, SDL_Surface *enigme, SDL_Rect positionEnigme)
{
enigme = IMG_Load ("1.png");
SDL_BlitSurface(enigme, NULL, ecran, &positionEnigme);
SDL_Flip(ecran);
}
//--------------------------------------------------------------------------------------------------------------------------------
 
//--------------------------------------------------------------------------------------------------------------------------------
void deplacement_selection(int* choix, int* ligne, int* son, int* continuer, Mix_Chunk* button)
{
 SDL_Event event;
 SDL_WaitEvent(&event); /* On attend un événement qu'on récupère dans event*/ 

        switch(event.type) /* On teste le type d'événement*/

        {

         case SDL_QUIT: /* Si c'est un événement QUITTER*/
                Mix_PlayChannel(-1,button,0);
                (*continuer) = 0; /* On met le booléen à 0, donc la boucle va s'arrêter*/ 

              break;
         case SDL_KEYDOWN:
               Mix_PlayChannel(-1,button,0);
              switch(event.key.keysym.sym)

              {

                  case SDLK_UP:
                      if ((*ligne)==1)
                         (*ligne)=4;
                      else
                         (*ligne)--;
                    break;

                  case SDLK_DOWN:
                      if ((*ligne)==4)
                         (*ligne)=1;
                      else
                         (*ligne)++;
                    break;

                
                  case SDLK_RETURN:
                      Mix_PlayChannel(-1,button,0); 
                     switch((*ligne))
                      {
                        case 1:
                         (*choix)=1;
                         break;
                        case 2:
                         (*choix)=2;
                         break;
                        case 3:
                         (*choix)=3;
                         break;
                        case 4:
                         (*choix)=4;
                         break;
                      }
                    break;

              }
              break;
         case SDL_MOUSEMOTION:
            if (event.motion.x>280 && event.motion.x<525 && event.motion.y>255 && event.motion.y<290)
            {
               (*ligne)=1;
                break;
            }

            else if (event.motion.x>280 && event.motion.x<525 && event.motion.y>300 && event.motion.y<335)
            {
                (*ligne)=2;
                break;
            }
            else if (event.motion.x>280 && event.motion.x<525 && event.motion.y>350 && event.motion.y<380)
            {
                (*ligne)=3;
                break;
            }
            else if (event.motion.x>280 && event.motion.x<525 && event.motion.y>395 && event.motion.y<425)
            {
                (*ligne)=4;
                break;
            }
           break;

         case SDL_MOUSEBUTTONDOWN:
            Mix_PlayChannel(-1,button,0);
           switch(event.button.button)
            {

             case SDL_BUTTON_LEFT :

                if ((*ligne)==1)
                {
                   (*choix)=1;
                  break;
                }
                if ((*ligne)==2)
                {
                   (*choix)=2;
                  break;
                }
                if ((*ligne)==3)
                {
                   (*choix)=3;
                  break;
                }
                if ((*ligne)==4)
                {
                   (*choix)=4;
                  break;
                }

              break;
            }
          break;
        }
(*son)=1;
}
//--------------------------------------------------------------------------------------------------------------------------------
void update_affichage(int choix, int ligne, int son, SDL_Rect positionEnigme, SDL_Surface* ecran, SDL_Surface* imageDeFond, SDL_Surface* enigme,SDL_Rect positionFond)
{

        if(ligne==1)
        {
            SDL_FreeSurface(enigme);
            enigme = IMG_Load("1.png");
            SDL_BlitSurface(imageDeFond , NULL, ecran, &positionFond);
            SDL_BlitSurface(enigme, NULL, ecran, &positionEnigme);
                  SDL_Flip(ecran);
        }

        if(ligne==2)
        {
            SDL_FreeSurface(enigme);
            enigme = IMG_Load("2.png");
            SDL_BlitSurface(imageDeFond , NULL, ecran, &positionFond );
            SDL_BlitSurface(enigme, NULL, ecran, &positionEnigme);
                  SDL_Flip(ecran);
        }
        if(ligne==3)
        {
            SDL_FreeSurface(enigme);
            enigme = IMG_Load("3.png");
            SDL_BlitSurface(imageDeFond , NULL, ecran, &positionFond );
            SDL_BlitSurface(enigme, NULL, ecran, &positionEnigme);
                  SDL_Flip(ecran);

        }
        if(ligne==4)
         {
            SDL_FreeSurface(enigme);
            enigme = IMG_Load("4.png");
            SDL_BlitSurface(imageDeFond , NULL, ecran, &positionFond );
            SDL_BlitSurface(enigme, NULL, ecran, &positionEnigme);
                  SDL_Flip(ecran);
         }
}
//--------------------------------------------------------------------------------------------------------------------------------
void recuperation_enigme(char qcm[],int i)
{
    int n=1;

    FILE *fichier;
    fichier=fopen("enigme.txt", "r");
    if(fichier!=NULL)
    {
        while(fgets((qcm),150,fichier)!=NULL && n!=(i))
        {

            n++;
        }
    }
    fclose(fichier);
}
//--------------------------------------------------------------------------------------------------------------------------------
void recuperation_reponses(char rep1[], char rep2[], char rep3[], char rep4[], int i)
{
 int n=1;

    FILE *fichier;
    fichier=fopen("reponses.txt", "r");
    if(fichier!=NULL)
    {
        while(fscanf(fichier," %s %s %s %s ", rep1, rep2, rep3, rep4)!=EOF && n!=(i))
        {

            n++;
        }
    }
    fclose(fichier);
}
//--------------------------------------------------------------------------------------------------------------------------------
void recuperation_tabRep(int reponse[])
{
int n=0;
    FILE *fichier;
    fichier=fopen("intRep.txt", "r");
    if(fichier!=NULL)
    {
        while(fscanf(fichier,"%d", &reponse[n] )!=EOF)
        {
            n++;
        }
    }
    fclose(fichier);

} 
//--------------------------------------------------------------------------------------------------------------------------------
void recuperation_texte(char qcm[], char rep1[], char rep2[], char rep3[], char rep4[], int i)
{
    recuperation_enigme(qcm, i);
    recuperation_reponses(rep1, rep2, rep3, rep4, i);
}
//--------------------------------------------------------------------------------------------------------------------------------
void validation(int *continuer,int choix, int *valid, int i, int ligne, int reponse[], SDL_Rect positionEnigme, SDL_Surface *ecran,SDL_Surface* youWin, SDL_Surface* gameOver, Mix_Chunk* win, Mix_Chunk* lose)
{


switch(choix)
{
         case 1:
          if(reponse[i-1]==ligne)
             {
               Mix_PlayChannel(-1,win,0);
               youWin = IMG_Load("youWin.png");
               SDL_BlitSurface(youWin, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
               SDL_Delay(1500);
               (*continuer)=0;
               (*valid)=1;
               break;
             }
          else
             {
               Mix_PlayChannel(-1,lose,0);
               gameOver = IMG_Load("gameOver.png");
               SDL_BlitSurface(gameOver, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
               SDL_Delay(1500);
               (*continuer)=0;
             }
           break;
         case 2:
          if(reponse[i-1]==ligne)
             {
               Mix_PlayChannel(-1,win,0);
               youWin = IMG_Load("youWin.png");
               SDL_BlitSurface(youWin, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
               SDL_Delay(1500);
               (*continuer)=0;
               (*valid)=1;
               break;
             }
          else
             {
               Mix_PlayChannel(-1,lose,0);
               gameOver = IMG_Load("gameOver.png");
               SDL_BlitSurface(gameOver, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
                SDL_Delay(1500);
               (*continuer)=0;
             }
           break;
         case 3:
          if(reponse[i-1]==ligne)
             {
               Mix_PlayChannel(-1,win,0);
               youWin = IMG_Load("youWin.png");
               SDL_BlitSurface(youWin, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
                SDL_Delay(1500);
               (*continuer)=0;
               (*valid)=1;
               break;
             }
          else
             {
               Mix_PlayChannel(-1,lose,0);
               gameOver = IMG_Load("gameOver.png");
               SDL_BlitSurface(gameOver, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
                 SDL_Delay(1500);
               (*continuer)=0;
             }
           break;
         case 4:
          if(reponse[i-1]==ligne)
             {
               Mix_PlayChannel(-1,win,0);
               youWin = IMG_Load("youWin.png");
               SDL_BlitSurface(youWin, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
              SDL_Delay(1500);
               (*continuer)=0;
               (*valid)=1;
               break;
             }
          else
             {
               Mix_PlayChannel(-1,lose,0);
               gameOver = IMG_Load("gameOver.png");
               SDL_BlitSurface(gameOver, NULL, ecran, &positionEnigme);
               SDL_Flip(ecran);
               SDL_Delay(1500);
               (*continuer)=0;
             }
           break;
}
}
//--------------------------------------------------------------------------------------------------------------------------------
void affichage_enigmes(SDL_Surface *ecran, SDL_Surface *question, SDL_Surface *r1, SDL_Surface *r2,SDL_Surface *r3,SDL_Surface *r4, char qcm[], char rep1[], char rep2[], char rep3[], char rep4[], TTF_Font *police, SDL_Color couleurNoire, SDL_Rect posQuestion,SDL_Rect posR1,SDL_Rect posR2,SDL_Rect posR3,SDL_Rect posR4)
{
   question = TTF_RenderText_Blended (police,qcm ,couleurNoire);
   SDL_BlitSurface(question, NULL, ecran, &posQuestion);
   r1 = TTF_RenderText_Blended (police,rep1 ,couleurNoire);
   SDL_BlitSurface(r1, NULL, ecran, &posR1);
   r2 = TTF_RenderText_Blended (police,rep2 ,couleurNoire);
   SDL_BlitSurface(r2, NULL, ecran, &posR2);
   r3 = TTF_RenderText_Blended (police,rep3 ,couleurNoire);
   SDL_BlitSurface(r3, NULL, ecran, &posR3);
   r4 = TTF_RenderText_Blended (police,rep4 ,couleurNoire);
   SDL_BlitSurface(r4, NULL, ecran, &posR4);
SDL_Flip(ecran);
}
//------------------------------------------------------------------------------------------------------------------------------
void liberationEnigmes(SDL_Surface *imageDeFond,SDL_Surface *enigme,SDL_Surface *question,SDL_Surface *r1,SDL_Surface *r2,SDL_Surface *r3,SDL_Surface *r4,SDL_Surface *youWin,SDL_Surface *gameOver,Mix_Music* backgroundSound,Mix_Chunk* button,Mix_Chunk *win,Mix_Chunk *lose, TTF_Font *police)
{
Mix_FreeMusic(backgroundSound);
Mix_FreeChunk(button);
Mix_FreeChunk(win);
Mix_FreeChunk(lose);
Mix_CloseAudio();
SDL_FreeSurface(imageDeFond );
SDL_FreeSurface(enigme);
SDL_FreeSurface(question);
SDL_FreeSurface(r1);
SDL_FreeSurface(r2);
SDL_FreeSurface(r3);
SDL_FreeSurface(r4);
SDL_FreeSurface(youWin);
SDL_FreeSurface(gameOver);
TTF_CloseFont(police);
TTF_Quit();
}
//---------------------------------------------------------------------------------------------------------------------------
void init(enigmes *E)
{
E->i=1;
E->choix=0;
E->ligne=1;
E->son=0;
E->continuer=1;
E->ctn=1;
E->enigme = NULL;
E->question = NULL;
E->r1 = NULL;
E->r2 = NULL;
E->r3 = NULL;
E->r4 = NULL;
E->backgroundSound = NULL ;
E->button=NULL;
E->win=NULL;
E->lose=NULL;
E->youWin=NULL;
E->gameOver=NULL;
E->police = NULL;
E->couleurNoire.r=0;
E->couleurNoire.g=0;
E->couleurNoire.b=0;
E->police = TTF_OpenFont("UbuntuMono.ttf", 14);
}

