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
{
SDL_BlitSurface(b->bg,&(b->pos),screen,NULL);

	SDL_BlitSurface(b->background,&(b->camera),screen,NULL);
}
/**
* @brief To show the first half of screen (for multiplayer)
* @param b the background screen the screen
* @return Nothing
*/
void partagepre(SDL_Surface * screen,background *b)
{

b->back=NULL;
b->back=SDL_CreateRGBSurface(SDL_HWSURFACE,10000,400,32,0,0,0,0);
b->back= IMG_Load("mapp.png");
b->posback1.x=0;
b->posback1.y=0;
b->mq=IMG_Load("maskss.png");
b->posmq.x=0;
b->posmq.y=0;
SDL_BlitSurface(b->mq, NULL, screen, &(b->posmq));
SDL_BlitSurface(b->back, NULL, screen, &(b->posback1));

}
/**
* @brief To show the second half of screen (for multiplayer)
* @param b the background screen the screen
* @return Nothing
*/
void partagedeu(SDL_Surface * screen,background *b)
{

b->back2=NULL;
b->back2=SDL_CreateRGBSurface(SDL_HWSURFACE,10000,400,32,0,0,0,0);
b->back2= IMG_Load("mapp.png");
b->posback2.x=0;
b->posback2.y=360;
b->mq2=IMG_Load("maskss.png");
b->posmq2.x=0;
b->posmq2.y=360;
SDL_BlitSurface(b->mq2, NULL, screen, &(b->posmq2));
SDL_BlitSurface(b->back2, NULL, screen, &(b->posback2));

}

/**
* @brief To scroll the background to the right
* @param b the background
* @return Nothing
*/

void scrolling_right (background *b)
{
	if (b->camera.x<=b->camera.w){
		 b->pos.x+=70 ;
		b->camera.x+=70; }

if (b->posback1.x<=b->posback1.w){
		 b->posmq.x+=70 ;
		b->posback1.x+=70; }
   if (b->posback2.x<=b->posback2.w){
		 b->posmq2.x+=70 ;
		b->posback2.x+=70; }
}
/**
* @brief To scroll the background to the left
* @param b the background
* @return Nothing
*/

void scrolling_left (background *b)
{
	if (b->camera.x>=0){
  b->pos.x-=70 ;
b->camera.x-=70 ;}
if (b->posback1.x>=0){
		 b->posmq.x-=70 ;
		b->posback1.x-=70; }
   if (b->posback2.x>=0){
		 b->posmq2.x-=70 ;
		b->posback2.x-=70; }

}
/**
* @brief  to free memory
* @param b the background
* @return Nothing
*/
void free_memory (background *b )
{ SDL_FreeSurface (b->back) ;
 SDL_FreeSurface (b->back2) ;
 SDL_FreeSurface (b->mq) ;
 SDL_FreeSurface (b->mq2) ;
 SDL_FreeSurface (b->background) ;
 SDL_FreeSurface (b->bg) ;


 SDL_Quit () ;

}
