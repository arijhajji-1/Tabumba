
/**
* @file sauvegarde.c
* @brief sauvegarde
* @author arij hajji
* @version 0.1
* @date May 26,2020
*
*/
	#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "sauvegarde.h"
#include "background.h"
#include "pp1.h"
#include "enig.h"
/**
* @brief to save the game
* @param Nothing
* @return Nothing
*/
	void SaveGame(personnageP luan)
	{ 
		FILE *f;
		f=fopen("savegame.txt","w");

		
			fprintf(f," %d %d \n ",(luan.position.x),(luan.position.y));

		

			fclose(f);
	}
/**
* @brief to initialize the save message
* @param screen the screen
* @param S the struct sauvegarde
* @return Nothing
*/
	void validationSauvegarde(SDL_Surface* screen,sauvegarde *s)
	{ 
		SDL_Color black={0,0,0};

		TTF_Init();

		TTF_Font* font=TTF_OpenFont("Capture_it.ttf",24);
		s->yedd=IMG_Load("pencil1.png");

		s->etat=0;
		s->pos=0;

		s->sauvegarder=TTF_RenderText_Solid(font,"Voulez vous sauvegarder ?",black);
		s->oui=TTF_RenderText_Solid(font,"Oui",black);
		s->non=TTF_RenderText_Solid(font,"Non",black);

		s->sauvegarderPos.x=300;
		s->sauvegarderPos.y=(screen->h - s->sauvegarder->h)/2;

		s->ouiPos.x=300;
		s->ouiPos.y=(screen->h - s->oui->h)/2 + 100;

		s->nonPos.x=600;
		s->nonPos.y=(screen->h - s->non->h)/2 + 100;



	}
/**
* @brief to  show the save message
* @param screen the screen
* @param sauvegarde the struct sauvegarde
* @return Nothing
*/
	void afficherSauvegarde(SDL_Surface *screen,sauvegarde *sauvegarde)
	{SDL_Event event; 

        if (sauvegarde->pos==0)
		{
			sauvegarde->yeddPos.x=300;
		sauvegarde->yeddPos.y=(screen->h - sauvegarde->yedd->h)/2 + 150;
		}
		 if (sauvegarde->pos==1)
		{
			sauvegarde->yeddPos.x=600;
		sauvegarde->yeddPos.y=(screen->h - sauvegarde->yedd->h)/2 + 150;
		}

		SDL_BlitSurface(sauvegarde->sauvegarder,NULL,screen,&sauvegarde->sauvegarderPos);
		SDL_BlitSurface(sauvegarde->oui,NULL,screen,&sauvegarde->ouiPos);
		SDL_BlitSurface(sauvegarde->non,NULL,screen,&sauvegarde->nonPos);
		SDL_BlitSurface(sauvegarde->yedd,NULL,screen,&sauvegarde->yeddPos);

		SDL_Flip(screen);
		
	}
/**
* @brief to choose yes or no for save
* @param screen the screen
* @param s the struct sauvegarde
* @return Nothing
*/
	int update (sauvegarde *s,SDL_Surface *screen,personnageP luan, int *done)

	{  SDL_Event event;
		
validationSauvegarde(screen,s);
int continuer=1;
int i=0,j=0;
		int pauses=0;
		background backg;
 while((SDL_WaitEvent(&event))&&(continuer==1))
{  
 afficherSauvegarde(screen,s);
  SDL_Delay(50);
  if (event.type==SDL_QUIT)
                continuer = 0;
 if(event.type==SDL_KEYDOWN){
                if(event.key.keysym.sym==SDLK_RIGHT)
                { 
        s->pos=1;

     

      	i=1;
      	
   }
   
            
       if(event.key.keysym.sym==SDLK_LEFT){
      
       s->pos=0;
       
       j=1;
  
}
if (event.key.keysym.sym==SDLK_RETURN){
if((s->pos==1)&&(i==1))
{

continuer=0;
return 1; 

}
else if((s->pos==0)&&(j==1))
{
	SaveGame(luan);
continuer=0;
return 0;
}
}
}
}



}

	
/**
* @brief to load game
* @param Nothing
* @return Nothing
*/

void loadGame(personnageP *luan)
{
	FILE *f; 
		f=fopen("savegame.txt","r");

		if (f != NULL)
		{
			fscanf(f," %hu %hu ",&(luan->position.x),&(luan->position.y));
			
		}
		else 
		{

luan->position.x=60;
luan->position.y=540;

		}
		fclose(f);
}
/**
* @brief to free memory
* @param sauvegarde the struct sauvegarde
* @return Nothing
*/
	void freem(sauvegarde *sauvegarde)
	{


		SDL_FreeSurface(sauvegarde->sauvegarder);
SDL_FreeSurface(sauvegarde->oui);
SDL_FreeSurface(sauvegarde->non);
SDL_FreeSurface(sauvegarde->yedd);
TTF_Quit();

	}
