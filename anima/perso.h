#ifndef PERSO_H_INCLUDED 
#define PERSO_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
typedef struct
{

SDL_Surface *sprite;
SDL_Rect posanimation,posjoueur ,frame[5];
int direction;
int score;
int etat;
int vie;
}perso;
void init_perso(perso *p);
void affiche_perso(perso *p,SDL_Surface *screen);
void deplacement_perso(perso *p);
int charger_sprite(perso *p);
void animate_personnage(perso *p);
void score_vie(perso *p);
void gestion_evenement(SDL_Event event,perso *p,SDL_Surface * screen);


#endif 
