#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
typedef struct
{
int choix, valid,i;
int ligne;
int son; 
int continuer;
char qcm[150], rep1[20], rep2[20], rep3[20], rep4[20];
int reponse[20], ctn;
SDL_Surface *imageDeFond,*ecran, *enigme , *question, *r1, *r2, *r3, *r4 ;
Mix_Music* backgroundSound ;
Mix_Chunk* button, *win, *lose;
SDL_Surface *youWin, *gameOver;
SDL_Rect positionFond , positionEnigme, posQuestion, posR1, posR2, posR3, posR4;
TTF_Font *police;
SDL_Color couleurNoire;
SDL_Event event;
}enigmes;

int MAINenigme(int i);
void init_position(SDL_Rect *positionFond , SDL_Rect *positionEnigme,SDL_Rect *posQuestion, SDL_Rect *posR1, SDL_Rect *posR2, SDL_Rect *posR3,SDL_Rect *posR4);
void attente(int *ctn, int *continuer, int *i, int choix, int valid, Mix_Chunk* button, SDL_Event event);
void init_fond(SDL_Surface *ecran,SDL_Surface *imageDeFond, SDL_Rect positionFond);
void prem_affich(SDL_Surface *ecran, SDL_Surface *enigme, SDL_Rect positionEnigme);
void init_son(Mix_Music* backgroundSound,Mix_Chunk* button,Mix_Chunk *win,Mix_Chunk *lose);
void deplacement_selection(int* choix, int* ligne, int* son, int* continuer, Mix_Chunk* button);
void update_affichage(int choix, int ligne, int son, SDL_Rect positionEnigme, SDL_Surface* ecran, SDL_Surface* imageDeFond, SDL_Surface*enigme,SDL_Rect positionFond);
void recuperation_enigme(char qcm[],int i);
void recuperation_reponses(char rep1[], char rep2[], char rep3[], char rep4[], int i);
void recuperation_tabRep(int reponse[]);
void recuperation_texte(char qcm[], char rep1[], char rep2[], char rep3[], char rep4[], int i);
void validation(int *continuer,int choix, int *valid, int i, int ligne, int reponse[], SDL_Rect positionEnigme, SDL_Surface *ecran,SDL_Surface* youWin, SDL_Surface* gameOver, Mix_Chunk* win, Mix_Chunk* lose);
void affichage_enigmes(SDL_Surface *ecran, SDL_Surface *question, SDL_Surface *r1, SDL_Surface *r2,SDL_Surface *r3,SDL_Surface *r4, char qcm[], char rep1[], char rep2[], char rep3[], char rep4[], TTF_Font *police, SDL_Color couleurNoire, SDL_Rect posQuestion,SDL_Rect posR1,SDL_Rect posR2,SDL_Rect posR3,SDL_Rect posR4);
void liberationEnigmes(SDL_Surface *imageDeFond,SDL_Surface *enigme,SDL_Surface *question,SDL_Surface *r1,SDL_Surface *r2,SDL_Surface *r3,SDL_Surface *r4,SDL_Surface *youWin,SDL_Surface *gameOver,Mix_Music* backgroundSound,Mix_Chunk* button,Mix_Chunk *win,Mix_Chunk *lose,TTF_Font *police);
void init(enigmes *E);
#endif // FONCTION_H_INCLUDED
