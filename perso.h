#ifndef PERSO_H_INCLUDED 
#define PERSO_H_INCLUDED 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
/** 
 *@struct personnage 
 *@brief struct personnage 

*/
typedef struct
{

SDL_Surface *sprite;
SDL_Rect posanimation,posjoueur;
int direction;
int score;
int etat;
int vie;
}perso;

void init_perso(perso *p1,perso *p2);
void affiche_persopre(perso *p1,SDL_Surface *screen);
void affiche_persodeu(perso *p2,SDL_Surface *screen);
void deplacement_perso(perso *p1,perso *p2);
int charger_sprite(perso *p1,perso *p2);
void animate_personnagepre(perso *p1);
void animate_personnagedeu(perso *p2);
void score_vie(perso *p);
void gestion_evenement(SDL_Event event,perso *p1,perso *p2,SDL_Surface * screen);
//void partagepre(SDL_Surface * screen);
//void partagedeu(SDL_Surface * screen);

#endif 
