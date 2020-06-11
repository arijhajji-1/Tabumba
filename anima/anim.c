#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
void init_perso(perso *p)
{
p->posanimation.x=0;
p->posanimation.y=100;
p->posanimation.w=100;
p->posanimation.h=100;
p->posjoueur.x=0;
p->posjoueur.y=0;
p->posjoueur.w=300;
p->posjoueur.h=300;
}
int charger_sprite(perso *p)
{
p->sprite=IMG_Load("images.png");
if(p->sprite==0)
{
printf("unable to load perso:%s\n",SDL_GetError());
return -1 ;
}
return 0;
}

void animate_personnage(perso *p)// ou on peut utilisé for pos=i=1 pos=i*100 i<5
{
p->posanimation.x +=100;
if (p->posanimation.x==400)
p->posanimation.x=0;
SDL_Delay(100);
}











void gestion_evenement(SDL_Event event,perso *p,SDL_Surface * screen)
{
int keep=1;
while(keep==1)
{
	 p->posanimation.y=100;
animate_personnage(p);
affiche_perso(p,screen);
SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
keep=0;
break;

}
}
}
void affiche_perso(perso *p,SDL_Surface *screen)
{
SDL_BlitSurface(p->sprite,&p->posanimation,screen,&p->posjoueur);
SDL_Flip(screen);
}





















/*
case SDL_KEYUP:
affiche_perso(p,screen);
break;
case SDL_KEYDOWN:
if((event.key.keysym.sym==SDLK_LEFT)||(event.key.keysym.sym==SDLK_q))
{ p->posanimation.y=100;
animate_personnage(p);
affiche_perso(p,screen);
}
if((event.key.keysym.sym==SDLK_RIGHT)||(event.key.keysym.sym==SDLK_d))
{ p->posanimation.y=200;
animate_personnage(p);
affiche_perso(p,screen);
}
if((event.key.keysym.sym==SDLK_UP)||(event.key.keysym.sym==SDLK_z))
{ p->posanimation.y=0;
animate_personnage(p);
affiche_perso(p,screen);
}
if((event.key.keysym.sym==SDLK_DOWN)||(event.key.keysym.sym==SDLK_s))
{ p->posanimation.y=300;
animate_personnage(p);
affiche_perso(p,screen);
}
break;*/
