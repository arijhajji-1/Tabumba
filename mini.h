#ifndef FONCTION_H_
#define FONCTION_H_


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
SDL_Surface *det;  /*!<Surface.*/
SDL_Rect pos[8];    /*!<Rectangle*/
int x,y,w,h;
}perso; 

/** 
 *@struct background 
 *@brief struct background 

*/

typedef struct {
SDL_Surface *background;  /*!<Surface.*/
SDL_Rect positionecran;    /*!<Rectangle*/
}bk;


#endif
