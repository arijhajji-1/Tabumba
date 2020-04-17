#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"

#include "collision.h"
#include "pp.h"

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}
int Collision(SDL_Surface *map , personnageP perso, SDL_Rect position )
{
int X,Y,W,H;
SDL_Rect pos[8];
SDL_Color couleur_obstacle;
X= 0;
Y= 0;
W = 190; 
H = 60;
perso.position[1].x=X;
perso.position[1].y=Y;
perso.position[2].x=X+(W/2);
perso.position[2].y=Y;
perso.position[3].x=X+W;
perso.position[3].y=Y;
perso.position[4].x=X;
perso.position[4].y=Y+(H/2);
perso.position[5].x=X;
perso.position[5].y=Y+H;
perso.position[6].x=X+(W/2);
perso.position[6].y=Y+H;
perso.position[7].x=X+W;
perso.position[7].y=Y+H;
perso.position[8].x=X+W;
perso.position[8].y=Y+(H/2);

int i;
{for (i=1;i<8;i++)
{
    col=GetPixel(screen,perso.position[i].x,perso.position[i].y);
if ((col.r==0)&&(col.b==0)&&(col.g==0))

  return 1; 
else
return 0;
}
