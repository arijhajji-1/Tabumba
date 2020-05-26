/**
* @file initsec.c
* @brief enemy
* @author arij hajji
* @version 0.1
* @date May 26,2020
*
*/
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "initsec.h"
#include "background.h"
/**
* @brief to initialize the enemy
* @param t the enemy 
* @param screen the screen
* @return Nothing
*/
void inisialiser_character (Enemy *t,SDL_Surface *screen)
{ 
t->image[1]=IMG_Load("2.png");
t->image[2]=IMG_Load("3.png");
t->image[3]=IMG_Load("4.png");
 t->image2[1]=IMG_Load("5.png");
 t->image2[2]=IMG_Load("6.png");
 t->image2[3]=IMG_Load("7.png");
 t->Hit=IMG_Load("1.png");
 t->positionO.x=0;
 t->positionO.y=0;
 t->position.x = 2400; 
 t->position.y = 300;
 t->position.h =250 ;
t->position.w = 100 ;
t->frame=0;
t->direction=0;
t->died=0;
t->imageActuel=IMG_Load("2.png");


}
/**
* @brief to show the enemy
* @param t the enemy 
* @param screen the screen
* @return Nothing
*/

void afficher_character (Enemy *t,SDL_Surface *screen)
	{  
		
		 
		SDL_BlitSurface(t->imageActuel,NULL,screen,&(t->position));
		SDL_Flip(screen);
                SDL_Delay(80);
                
		
	}
