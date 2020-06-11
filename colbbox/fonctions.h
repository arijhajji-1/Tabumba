
#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#define BOTTOM 1
#define TOP 2
#define LEFT 3
#define RIGHT 4
#define RIEN 0

int attendreAvantDeQuitter(Uint8 typeEvenement);
SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur);
void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu);
void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect *position);
void attendreTemps(int millisecondes);
void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y);
int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision);
void deplacementAutorise(int typeCol, SDL_Rect * pos1, SDL_Event event, int vit_x, int vit_y);



int verifEtatToucheClavier();

#endif // FONCTIONS_H_INCLUDED
