
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
  SDL_Surface *bg,*back,*back2; /* !< Surface. */
SDL_Surface *background,*mq,*mq2; /* !< Surface. */
	    SDL_Rect camera,posback2,posback1; /* !< Rectangle */
      SDL_Rect pos,posmq,posmq2;/* !< Rectangle */
}background;

void initialiser_backround (background *b);

void afficher_background (SDL_Surface *screen,background *b);
void partagedeu(SDL_Surface * screen,background *b);
void partagepre(SDL_Surface * screen,background *b);
void scrolling_right (background *b);
void scrolling_left (background *b);
void free_memory (background *b );



  #endif // DS_H_INCLUDED
