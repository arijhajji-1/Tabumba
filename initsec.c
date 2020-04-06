#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "initsec.h"

void inisialiser_character (character *t, int x, int y)
{

	       t->image =  IMG_Load("background2.jpg"); 
	      if  ( t->image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     t->positionAbsolute.x = x; 
     t->positionAbsolute.y = y;
     t->positionAbsolute.h = t->image->h ;
     t->positionAbsolute.w = t->image->w ;
t->positionAnimation.x = x; 
     t->positionAnimation.y = y;
     t->positionAnimation.h = t->image->h ;
     t->positionAnimation.w = t->image->w ;
}


t->health=0;
t->direction=0;
t->moving=0;


}

void afficher_character (character *t,SDL_Surface *screen,SDL_Rect pos)
	{
		SDL_BlitSurface(t->character,NULL,screen,&pos);
	}
