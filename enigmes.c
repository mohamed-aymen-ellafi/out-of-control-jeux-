#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h> 
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonction.h"

//--------------------------------------------------------------------------------------------------------------------------------
int enigmes()
{
enigmes E;
init(&E);
//INITIALISATION DES POSITIONS
init_position(&(E).positionFond , &(E).positionEnigme, &(E).posQuestion, &(E).posR1, &(E).posR2, &(E).posR3,&(E).posR4);
(E).ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
//INITIALISATION SONS
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
init_son((E).backgroundSound,(E).button,(E).win,(E).lose);
//INIT TEXTE
TTF_Init();
(E).police = TTF_OpenFont("UbuntuMono.ttf", 14);
//SDL_WM_SetIcon(IMG_Load ("sdl_icone.bmp"), NULL);
init_fond((E).ecran, (E).imageDeFond, E.positionFond);
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
validation(E.choix, &(E).valid, E.i, E.ligne, E.reponse, E.positionEnigme, E.ecran, E.youWin, E.gameOver, E.win, E.lose);
attente(&(E).ctn,&(E).continuer,&(E).i, E.choix,E.valid, E.button, E.event);
}
//liberation(E.imageDeFond, E.enigme, E.question, E.r1, E.r2, E.r3, E.r4, E.youWin, E.gameOver, E.backgroundSound, E.button, E.win, E.lose, E.police);
SDL_Quit();
return EXIT_SUCCESS;
}

