/** 
 *@file multijoueur.c 
 *@brief ajouter 2éme personnage 
 *@author mohamed yahya jday 
 *@version 0.1 
 *@date 10/06/2020 
*/



#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

/** 
 
 *@brief initialisation de personnage  
 *@param p1 est le 1ér perso   et p2 est la 2eme perso 
 *@return nothing 
 
*/
void init_perso(perso *p1,perso *p2)
{
p1->posanimation.x=0;
p1->posanimation.y=0;
p1->posanimation.w=100;
p1->posanimation.h=100;
p1->posjoueur.x=0;
p1->posjoueur.y=250;
p1->posjoueur.w=100;
p1->posjoueur.h=100;
p2->posanimation.x=0;
p2->posanimation.y=0;
p2->posanimation.w=100;
p2->posanimation.h=100;
p2->posjoueur.x=0;
p2->posjoueur.y=500;
p2->posjoueur.w=100;
p2->posjoueur.h=100;
}

/** 
 
 *@brief charger sprite 
 *@param p1 est la 1er personnage et p2 est la 2éme perso 
 *@return -1 ou bien 0
 
*/

int charger_sprite(perso *p1,perso *p2)
{
p1->sprite=IMG_Load("1.png");
p2->sprite=IMG_Load("2.jpg");
if((p1->sprite==0)&&(p2->sprite==0))
{
printf("unable to load perso:%s\n",SDL_GetError());
return -1 ;
}
return 0;
} 

/** 
 
 *@brief animate la 1ér personnage  
 *@param p1 est la 1er perso 
 *@return nothing 
 
*/

void animate_personnagepre(perso *p1)
{
p1->posanimation.x +=100;
if (p1->posanimation.x==400)
p1->posanimation.x=0;
SDL_Delay(30);
} 

/** 
 
 *@brief animate 2eme personnage 
 *@param p2 est la 2éme personnage
 *@return nothing 
 
*/

void animate_personnagedeu(perso *p2)
{
p2->posanimation.x +=100;
if (p2->posanimation.x==400)
p2->posanimation.x=0;
SDL_Delay(30);
}

/** 
 
 *@brief afficher la 1 er personnage 
 *@param on a p1 est la 1er perso et un screen 
 *@return nothing 
 
*/

void affiche_persopre(perso *p1,SDL_Surface *screen)
{


SDL_BlitSurface(p1->sprite,&p1->posanimation,screen,&p1->posjoueur);
SDL_Flip(screen);
} 
/** 
 
 *@brief afficher 2eme personnage  
 *@param  on a p2 est la 2eme perso  et un screen . 
 *@return nothing 
 
*/

void affiche_persodeu(perso *p2,SDL_Surface *screen)
{

SDL_BlitSurface(p2->sprite,&p2->posanimation,screen,&p2->posjoueur);
SDL_Flip(screen);
} 

/** 
 
 *@brief gestion d'evenement 
 *@param p1 et p2 deux personnages ,un screen,et un event  
 *@return nothing 
 
*/

void gestion_evenement(SDL_Event event,perso *p1,perso *p2,SDL_Surface * screen)
{
int keep=1;
int x;
int *running;

init_perso(p1,p2);
x=charger_sprite(p1,p2);
while(keep==1)
{

affiche_persopre(p1,screen);
affiche_persodeu(p2,screen);
SDL_Flip(screen);
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_QUIT:
keep=0;
break;
case SDL_KEYUP:
affiche_persopre(p1,screen);
affiche_persodeu(p2,screen);
break;
case SDL_KEYDOWN:
if(event.key.keysym.sym==SDLK_LEFT)
{p1->posjoueur.x-=50;
p1->posanimation.y=100;
animate_personnagepre(p1);
}
if(event.key.keysym.sym==SDLK_q)
{p2->posjoueur.x-=50;
p2->posanimation.y=100;
animate_personnagedeu(p2);
}
if((event.key.keysym.sym==SDLK_RIGHT))
{

p1->posjoueur.x+=50;
p1->posanimation.y=200;
animate_personnagepre(p1);

}
if(event.key.keysym.sym==SDLK_d)
{ p2->posjoueur.x+=50;
p2->posanimation.y=200;
animate_personnagedeu(p2);
}
if(event.key.keysym.sym==SDLK_UP)
{p1->posjoueur.y-=50;
p1->posanimation.y=0;
animate_personnagepre(p1);

}
if(event.key.keysym.sym==SDLK_z)
{
 p2->posanimation.y=0;
 animate_personnagedeu(p2);
}
if(event.key.keysym.sym==SDLK_DOWN)
{  p1->posjoueur.y+=50;
p1->posanimation.y=300;
  animate_personnagepre(p1);
}
if(event.key.keysym.sym==SDLK_s)
 {  p2->posanimation.y=300;
    animate_personnagedeu(p2);
}
break;
}
}
}


