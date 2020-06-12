/** 
* 
@author Fourat Halaoua
@brief mini_jeu XO avec AI;
@date May 24 2019
@version 1.0
@file jeuAI2.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fctAI2.h"

int main()
{
	//declaration 
SDL_Surface *screen;
SDL_Surface *background;
SDL_Rect posbackground;
SDL_Surface *win,*lose;
SDL_Rect poswin,poslose;
joueur xplayer;
ordinateur oplayer;
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

//initialisation du xplayer
xplayer=initialisation_xjoueur();

//initialisation du oplayer
oplayer=initialisation_ojoueur();

compteur=xplayer.nb_de_fois;
//tour de xplayer
do
{xplayer=joueurX(xplayer,Tab,screen);
	SDL_Delay(1000);
	//tour de oplayer 
	if(fin_jeu(xplayer,oplayer,Tab,screen)==0)
 {oplayer=ordinateurO(oplayer,Tab,screen);
 	SDL_Delay(500);}
 }while(fin_jeu(xplayer,oplayer,Tab,screen)==0);
// si 
if(fin_jeu(xplayer,oplayer,Tab,screen)==1)
{
win=SDL_LoadBMP("you win.bmp");
poswin.x=150;
poswin.y=150;
SDL_BlitSurface(win,NULL,screen,&poswin);
SDL_Flip(screen);	
}
else if(fin_jeu(xplayer,oplayer,Tab,screen)==2)
{
lose=SDL_LoadBMP("you lose.bmp");
poslose.x=150;
poslose.y=150;
SDL_BlitSurface(lose,NULL,screen,&poslose);
SDL_Flip(screen);
}else if(fin_jeu(xplayer,oplayer,Tab,screen)==3)
{
  main();
}

SDL_FreeSurface(screen);
 pause=getchar();
SDL_Quit();
return 0;
}

