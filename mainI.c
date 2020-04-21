#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "pp1.h"
#include "background.h" 
#include <SDL/SDL_ttf.h>

void main ()
{
background backg;
SDL_Surface *screen;
personnageP luan;
char pause;
SDL_Event event;
int level=1;
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
screen=SDL_SetVideoMode(1000,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  initialiser_backround (&backg);
afficher_background (screen,&backg);
SDL_Flip(screen);
SDL_Delay(30);
luan=inisialiser_perso(level,screen);
  init_vie(&(luan.persoVie),screen);
   init_score(screen,(luan.persoScore));
delpacement (event,&luan,screen,&backg);
free_memory (&backg);
   pause=getchar();
   free_score(&(luan.persoScore));   
 TTF_Quit();
SDL_Quit();
}
