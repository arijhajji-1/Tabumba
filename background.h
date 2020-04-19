#ifndef background_H_INCLUDED
#define background_H_INCLUDED


#include "pp.h"

typedef struct  background
{
  SDL_Surface *bg;
	    SDL_Surface *background;
	    SDL_Rect camera;
	    int x_relative;
	    int y_relative;
      SDL_Rect pos;
}background;

void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling_right (background *b,personnageP *p,SDL_Surface *screen);
void scrolling_left (background *b,personnageP *p,SDL_Surface *screen);

void free_memory (background *b );

  #endif // DS_H_INCLUDED
