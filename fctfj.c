/** 
* 
@author Fourat Halaoua
@brief condition fin de jeu;
@date May 28 2019
@version 1.0
@file fctfj.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "fin_jeu.h"

/**
*
@brief pour arreter le jeu 
@param enigme 
@param vie nombre du vie du personnage
@return entier 1:le joueur a gagne le jeu 0: le joueur a perdu le jeu 
*/

int fin_jeu(int enigem,int vie)
{
if(vie==0)
{
	return 0;
}else if((enigem==1)&&(vie!=0))
{
	return 1;
}
else 
return 2;
}
/**
*
@brief si le joueur a gagne
@param screen est l'ecran du jeu  
@param nbvie nombre du vie du personnage
@param point est le score du joueur 
@param time est le temps passe dans le jeu
@return rien 
*/
void gagne_jeu(SDL_Surface *screen,int point,int time,int nbvie)
{
SDL_Surface *texte=NULL;
SDL_Surface *texte1=NULL;
SDL_Surface *texte2=NULL;
SDL_Rect postxt,postxt1,postxt2;
SDL_Surface *win;
SDL_Rect poswin;
TTF_Font *police=NULL;
SDL_Color couleurRouge={255,0,0},couleurBlanche={255,255,255};
char score[30],temps[30],vie[30];
TTF_Init();
Mix_Music *music;
Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
music = Mix_LoadMUS("2.mp3");
  Mix_PlayMusic(music,-1);
win=IMG_Load("you win.png");
poswin.x=150;
poswin.y=20;
SDL_BlitSurface(win,NULL,screen,&poswin);
SDL_Flip(screen);
SDL_FreeSurface(screen);  

police= TTF_OpenFont("angelina.TTF", 65);
sprintf(temps,"temps : %d s",time);
texte=TTF_RenderText_Shaded(police,temps,couleurRouge,couleurBlanche);
sprintf(score,"score : %d",point);
texte1=TTF_RenderText_Shaded(police,score,couleurRouge,couleurBlanche);
sprintf(vie,"vie : %d",nbvie);
texte2=TTF_RenderText_Shaded(police,vie,couleurRouge,couleurBlanche);
postxt.x=60;
postxt.y=340;
postxt1.x=60;
postxt1.y=440;
postxt2.x=60;
postxt2.y=540;
SDL_BlitSurface(texte,NULL,screen,&postxt);
SDL_BlitSurface(texte1,NULL,screen,&postxt1);
SDL_BlitSurface(texte2,NULL,screen,&postxt2);
SDL_Flip(screen);
TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte);
SDL_FreeSurface(texte1);
SDL_FreeSurface(texte2);
}
/**
*
@brief si le joueur a perdu
@param screen est l'ecran du jeu  
@param nbvie nombre du vie du personnage
@param point est le score du joueur 
@param time est le temps passe dans le jeu
@return rien 
*/
void perdu_jeu(SDL_Surface *screen,int point,int time,int nbvie)
{
SDL_Surface *texte=NULL;
SDL_Surface *texte1=NULL;
SDL_Surface *texte2=NULL;
SDL_Rect postxt,postxt1,postxt2;
SDL_Surface *lose;
SDL_Rect poslose;
TTF_Font *police=NULL;
SDL_Color couleurRouge={255,0,0},couleurBlanche={255,255,255};
char score[30],temps[30],vie[30];
TTF_Init();
Mix_Music *music;
Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
music = Mix_LoadMUS("1.mp3");
  Mix_PlayMusic(music,-1);
lose=IMG_Load("you lose.png");
poslose.x=350;
poslose.y=20;
SDL_BlitSurface(lose,NULL,screen,&poslose);
SDL_Flip(screen);
SDL_FreeSurface(screen);  

police= TTF_OpenFont("angelina.TTF", 65);
sprintf(temps,"temps : %d s",time);
texte=TTF_RenderText_Shaded(police,temps,couleurRouge,couleurBlanche);
sprintf(score,"score : %d",point);
texte1=TTF_RenderText_Shaded(police,score,couleurRouge,couleurBlanche);
sprintf(vie,"vie : %d",nbvie);
texte2=TTF_RenderText_Shaded(police,vie,couleurRouge,couleurBlanche);
postxt.x=60;
postxt.y=340;
postxt1.x=60;
postxt1.y=440;
postxt2.x=60;
postxt2.y=540;
SDL_BlitSurface(texte,NULL,screen,&postxt);
SDL_BlitSurface(texte1,NULL,screen,&postxt1);
SDL_BlitSurface(texte2,NULL,screen,&postxt2);
SDL_Flip(screen);
TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte);
SDL_FreeSurface(texte1);
SDL_FreeSurface(texte2);
}
