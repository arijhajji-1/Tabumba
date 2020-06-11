#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "perso.h"
int main()
{
perso p;
SDL_Event event;
SDL_Surface *screen=NULL;
int x;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(420, 420, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
init_perso(&p);
animate_personnage(&p);
x=charger_sprite(&p);
affiche_perso(&p,screen);
gestion_evenement( event,&p,screen);
SDL_Quit();
return 0;
}


