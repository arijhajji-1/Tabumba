#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "initsec.h"

void inisialiser_character (Enemy *t, int x, int y)
{

	       t->imageActuel =  IMG_Load("sylvan.png"); 
	      if  ( t->imageActuel  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     t->position.x = x; 
     t->position.y = y;
     t->position.h =200 ;
     t->position.w = 80 ;

}


t->frame=0;
t->direction=0;
t->died=0;


}

void afficher_character (Enemy *t,SDL_Surface *screen,SDL_Rect pos)
	{
		SDL_BlitSurface(t->Enemy,NULL,screen,&pos);
	}
