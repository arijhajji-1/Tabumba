#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
SDL_Rect poscore;
int val;
SDL_Surface *score;
}score;


void init_score(score *s) ; 
void updatescore(score *s,int test) ;  
void displayscore(score s ,SDL_Surface *ecran) ;  
void vie_freescore(score *s ) ;   
#endif
