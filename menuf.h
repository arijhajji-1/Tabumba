#ifndef MENUF_H_INCLUDED
#define MENUF_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


//#include "option.h"


//int quit (SDL_Surface *ecran);
void menu (SDL_Surface *screen);
//void coa_on(SDL_Surface *ecran);
/*void coa_off(SDL_Surface *ecran);
void logo_on(SDL_Surface *ecran);
void logo_off(SDL_Surface *ecran);
void sdl_on(SDL_Surface *ecran);
void sdl_off(SDL_Surface *ecran);
void intro (SDL_Surface *screen);
void cinematique(SDL_Surface *ecran);
void transition1 (SDL_Surface *ecran);
void transition2 (SDL_Surface *ecran);
void transition3 (SDL_Surface *ecran);
void transition4 (SDL_Surface *ecran);
void transition5 (SDL_Surface *ecran);
void transition6 (SDL_Surface *ecran);
void loose(SDL_Surface *ecran);
void chance(SDL_Surface *ecran);
void loose1(SDL_Surface *ecran);
void chance1(SDL_Surface *ecran);*/
int options(SDL_Surface *screen,int actiono);
int back(SDL_Surface *screen,int x );
int credit(SDL_Surface *screen);
void quit(SDL_Surface *screen);
void volume(SDL_Surface * screen);
void graphique(SDL_Surface * screen);
void play(SDL_Surface *screen);
void commandes(SDL_Surface *screen);



  #endif // MENUF_H_INCLUDED
