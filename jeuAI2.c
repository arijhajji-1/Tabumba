#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fct.h"

int main()
{
	//declaration 
SDL_Surface *screen;
SDL_Surface *background;
SDL_Surface *ximage;
SDL_Rect posbackground;
SDL_Rect xpos;
joueur xplayer;
ordinateur oplayer;
//SDL_Rect xpos;
ctableau Tab[3][3];
char pause;
int i,j,compteur,action;
//initialisation d'ecran
SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
screen=SDL_SetVideoMode(600,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

//affichage du background
afficher_background(screen);

//initialisation du tableau
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
Tab[i][j]=initialisation_tab(i,j);
}
}
//x=SDL_LoadBMP("x.bmp");
//xpos.x=201;
//xpos.y=1;
//initialisation du xplayer
xplayer=initialisation_xjoueur();
//SDL_BlitSurface(x,NULL,screen,&xpos);
//SDL_Flip(screen);
//initialisation du oplayer
oplayer=initialisation_ojoueur();

compteur=xplayer.nb_de_fois;
//tour de xplayer
do
{xplayer=joueurX(xplayer,Tab,screen);
	SDL_Delay(1500);
	if(fin_jeu(xplayer,oplayer,Tab,screen)==0)
 {oplayer=ordinateurO(oplayer,Tab,screen);
 	SDL_Delay(1000);}
 }while(fin_jeu(xplayer,oplayer,Tab,screen)==0);
if(fin_jeu(xplayer,oplayer,Tab,screen)==1)
{
	
}
else if(fin_jeu(xplayer,oplayer,Tab,screen)==2)
{
	
}else if(fin_jeu(xplayer,oplayer,Tab,screen)==3)
{
  main();
}

SDL_FreeSurface(screen);
 pause=getchar();
SDL_Quit();
return 0;
}

