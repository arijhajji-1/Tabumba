/**
* @file background.c
* @brief background
* @author arij hajji
* @version 0.1
* @date May 26,2020
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
/**
* @brief to initialize the background b
* @param b the background
* @return Nothing
*/


void initialiser_backround (background *b)
{

b->background=NULL;
b->bg=NULL;
b->pos.x=0;
b->pos.y=0;
b->pos.w=10000;
b->pos.h=800;
b->camera.x=0;
b->camera.y=0;
b->camera.w=10000;
b->camera.h=800;
b->background=IMG_Load("map.png");
b->bg=IMG_Load("masks.png");

}
/**
* @brief to show the background b
* @param screen the screen
* @param b the background
* @return Nothing
*/
void afficher_background (SDL_Surface *screen,background *b)
{SDL_BlitSurface(b->bg,&(b->pos),screen,NULL);

	SDL_BlitSurface(b->background,&(b->camera),screen,NULL);

	
  



}
/**
* @brief To scroll the background to the right
* @param b the background
* @return Nothing
*/

void scrolling_right (background *b)
{
	if (b->camera.x<=b->camera.w){
		 b->pos.x+=20 ;
		b->camera.x+=20;
	
  }

   
}
/**
* @brief To scroll the background to the left
* @param b the background
* @return Nothing
*/

void scrolling_left (background *b)
{
	if (b->camera.x>=0){
  b->pos.x-=20 ;
b->camera.x-=20 ;}

}
/**
* @brief  to free memory
* @param b the background
* @return Nothing
*/
void free_memory (background *b )
{
 SDL_FreeSurface (b->background) ;
 SDL_FreeSurface (b->bg) ;


 SDL_Quit () ;

}
