
#ifndef BACKGROUND_H_INCLUDED

#define BACKGROUND_H_INCLUDED
#define PP1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "pp1.h"
/**
* @struct Background
* @brief struct for Background
*/
typedef struct  
{
  SDL_Surface *bg; /* !< Surface. */
SDL_Surface *background; /* !< Surface. */
	    SDL_Rect camera; /* !< Rectangle */
      SDL_Rect pos;/* !< Rectangle */
}background;

void initialiser_backround (background *b);
void initialiser_background (background *b);
void afficher_backgroundd (SDL_Surface *screen,background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling_right (background *b);
void scrolling_left (background *b);
void free_memory (background *b );



  #endif // DS_H_INCLUDED
