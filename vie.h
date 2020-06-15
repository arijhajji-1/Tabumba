#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct  
{
SDL_Rect posvie ;  
int val=5 ;
SDL_Surface *image[5]; 
} vie ; 



void init_vie(vie *v,SDL_Surface *ecran); 

int displayvie(vie *v ,SDL_Surface *ecran,int x); 

void vie_freevie(vie *v ) ;

#endif
