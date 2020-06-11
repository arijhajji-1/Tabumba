#ifndef FONCTION2_H_
#define FONCTION2_H_


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "mini.h"
/** 
 *@struct map 
 *@brief struct map 

*/
typedef struct 
{
SDL_Surface *map;  /*!<Surface.*/
SDL_Rect posmap;   /*!<Rectangle*/
}ma;

/** 
 *@struct minimap 
 *@brief struct minimap 

*/

typedef struct 
{
SDL_Surface *mini;/*!<Surface.*/
SDL_Rect posmini;/*!<Rectangle*/
}mi;
mi minimap(perso p,mi m2);
#endif
