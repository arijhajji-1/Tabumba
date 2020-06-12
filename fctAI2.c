/** 
* 
@file fctAI2.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "fctAI2.h"
/**
*
@brief pour afficher le background
@param screen est ecran de jeu
@return rien
*/
void afficher_background (SDL_Surface *screen)
{
	SDL_Rect posbackground;
	SDL_Surface *background;
background= SDL_LoadBMP ("background.bmp");
posbackground.x=0;
posbackground.y=0;
SDL_BlitSurface(background,NULL,screen,&posbackground);
SDL_Flip(screen);
SDL_FreeSurface(screen);  
}
/**
*
@brief pour initialiser le tableau
@param j nombre de colone
@param i nombre de ligne
@return la case 
*/
ctableau initialisation_tab(int i,int j)
{
	
	ctableau Tab;
Tab.cas=0;
Tab.pos.x=200*j;
Tab.pos.y=200*i;
return (Tab);
}
/**
*
@brief pour initialiser le joueur x
@param rien
@return initialisation joueur x 
*/
joueur initialisation_xjoueur()
{
	joueur player;
	player.image=SDL_LoadBMP("x.bmp");
	player.nb_de_fois=5;
	return player;
}
/**
*
@brief pour initialiser le joueur o
@param rien
@return initialisation joueur o 
*/
ordinateur initialisation_ojoueur()
{
	ordinateur player;
	player.image=SDL_LoadBMP("o.bmp");
	player.nb_de_fois=4;
	return player;
}
/**
*
@brief pour faire le tour du joueur x
@param player le joueur x
@param Tab[3][3] le tableau 
@param  screen est l'ecran du jeu
@return  joueur x 
*/
joueur joueurX(joueur player,ctableau Tab[3][3],SDL_Surface *screen)
{
	SDL_Event event;
	int i,j;
	int action=1;
  while((player.nb_de_fois>=1)&&(action==1))
  {
	while(SDL_WaitEvent(&event))
	 {
       switch(event.type)
        {
        	case SDL_MOUSEBUTTONUP:
             if(event.button.button==SDL_BUTTON_LEFT)
               {
               	for(i=0;i<3;i++)
               	 {
                   for(j=0;j<3;j++)
                   {if(((event.button.x>=Tab[i][j].pos.x)&&(event.button.x<=Tab[i][j].pos.x+200))&&((event.button.y>=Tab[i][j].pos.y)&&(event.button.y<=Tab[i][j].pos.y+200)))
                       {
                    if(Tab[i][j].cas==0)
                       {    	action=0;
                       	player.nb_de_fois=(player.nb_de_fois-1);
                       	SDL_BlitSurface((player.image),NULL,screen,&(Tab[i][j].pos));
                         SDL_Flip(screen);
                         Tab[i][j].cas=1;
                       }
                       else 
                       {
                       	player=joueurX(player,Tab,screen);
                       	action=0;
                       }
                   }

                   }
               	 }
               }
        	break;
        }
        break;
	 }
  }
  return player;
}
/**
*
@brief pour faire le tour du joueur 0(ordinateur)
@param player le joueur 0
@param Tab[3][3] le tableau 
@param  screen est l'ecran du jeu
@return initialisation joueur o 
*/
ordinateur ordinateurO(ordinateur player,ctableau Tab[3][3],SDL_Surface *screen)
{
	int ligne,colone;
	int action=1;
	while((player.nb_de_fois>=1)&&(action==1))
	{
     ligne=(rand()%3);
     colone=(rand()%3);
     if(Tab[ligne][colone].cas==0)
     {
     	action=0;
     	player.nb_de_fois=(player.nb_de_fois-1);
	    SDL_BlitSurface((player.image),NULL,screen,&(Tab[ligne][colone].pos));
        SDL_Flip(screen);
        Tab[ligne][colone].cas=2;
        break;
     }
     else 
     {
        player=ordinateurO(player,Tab,screen);
        action=0;
     }
	}
	  return player;
}


/**
*
@brief pour arreter le jeu 
@param player le joueur x
@param player le joueur 0
@param Tab[3][3] le tableau 
@param  screen est l'ecran du jeu
@return entier 0=le jeu n'a pas termine 1=joueurx a gagne 2=joueuro a gagne 3= rejouer
*/
int fin_jeu(joueur playerx,ordinateur playero,ctableau Tab[3][3],SDL_Surface *screen)
{ SDL_Surface *barre1,*barre2,*barre3,*barre4;
	SDL_Rect posbarre1,posbarre2,posbarre3,posbarre4;
	if(playerx.nb_de_fois<3)
	{
     if(((Tab[0][0].cas)!=0)&&((Tab[0][1].cas)!=0)&&((Tab[0][2].cas)!=0)&&((Tab[0][0].cas)==(Tab[0][1].cas))&&((Tab[0][1].cas)==(Tab[0][2].cas)))
     {
       if(Tab[0][0].cas==1)
         {
           barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=100;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][0].cas==2)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=100;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }
     }
     else if (((Tab[1][0].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[1][2].cas)!=0)&&((Tab[1][0].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[1][2].cas)))
     {
       if(Tab[1][0].cas==1)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=300;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[1][0].cas==2)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=300;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[2][0].cas)!=0)&&((Tab[2][1].cas)!=0)&&((Tab[2][2].cas)!=0)&&((Tab[2][0].cas)==(Tab[2][1].cas))&&((Tab[2][1].cas)==(Tab[2][2].cas)))
     {
       if(Tab[2][0].cas==1)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=500;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[2][0].cas==2)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=500;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][0].cas)!=0)&&((Tab[1][0].cas)!=0)&&((Tab[2][0].cas)!=0)&&((Tab[0][0].cas)==(Tab[1][0].cas))&&((Tab[1][0].cas)==(Tab[2][0].cas)))
     {
       if(Tab[0][0].cas==1)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=100;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][0].cas==2)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=100;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	         	SDL_Flip(screen);
         	         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][1].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[2][1].cas)!=0)&&((Tab[0][1].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[2][1].cas)))
     {
         if(Tab[0][1].cas==1)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=300;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][1].cas==2)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=300;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][2].cas)!=0)&&((Tab[1][2].cas)!=0)&&((Tab[2][2].cas)!=0)&&((Tab[0][2].cas)==(Tab[1][2].cas))&&((Tab[1][2].cas)==(Tab[2][2].cas)))
     {
          if(Tab[0][2].cas==1)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=500;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][2].cas==2)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=500;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][0].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[2][2].cas)!=0)&&((Tab[0][0].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[2][2].cas)))
     {
       if(Tab[0][0].cas==1)
         {barre1=SDL_LoadBMP("3.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][0].cas==2)
         {barre1=SDL_LoadBMP("3.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][2].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[2][0].cas)!=0)&&((Tab[0][2].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[2][0].cas)))
     {
        if(Tab[0][2].cas==1)
         {barre1=SDL_LoadBMP("4.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][2].cas==2)
         {barre1=SDL_LoadBMP("4.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if((playerx.nb_de_fois==0)&&(playero.nb_de_fois==0))
	{
      if(((Tab[0][0].cas)!=0)&&((Tab[0][1].cas)!=0)&&((Tab[0][2].cas)!=0)&&((Tab[0][0].cas)==(Tab[0][1].cas))&&((Tab[0][1].cas)==(Tab[0][2].cas)))
     {
       if(Tab[0][0].cas==1)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=100;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][0].cas==2)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=100;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }
     }
     else if (((Tab[1][0].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[1][2].cas)!=0)&&((Tab[1][0].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[1][2].cas)))
     {
       if(Tab[1][0].cas==1)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=300;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[1][0].cas==2)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=300;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[2][0].cas)!=0)&&((Tab[2][1].cas)!=0)&&((Tab[2][2].cas)!=0)&&((Tab[2][0].cas)==(Tab[2][1].cas))&&((Tab[2][1].cas)==(Tab[2][2].cas)))
     {
       if(Tab[2][0].cas==1)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=500;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	         	return 1;
         }
         else if(Tab[2][0].cas==2)
         {barre1=SDL_LoadBMP("2.bmp");
         	posbarre1.x=20;
         	posbarre1.y=500;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][0].cas)!=0)&&((Tab[1][0].cas)!=0)&&((Tab[2][0].cas)!=0)&&((Tab[0][0].cas)==(Tab[1][0].cas))&&((Tab[1][0].cas)==(Tab[2][0].cas)))
     {
       if(Tab[0][0].cas==1)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=100;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][0].cas==2)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=100;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][1].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[2][1].cas)!=0)&&((Tab[0][1].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[2][1].cas)))
     {
         if(Tab[0][1].cas==1)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=300;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][1].cas==2)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=300;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][2].cas)!=0)&&((Tab[1][2].cas)!=0)&&((Tab[2][2].cas)!=0)&&((Tab[0][2].cas)==(Tab[1][2].cas))&&((Tab[1][2].cas)==(Tab[2][2].cas)))
     {
          if(Tab[0][2].cas==1)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=500;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][2].cas==2)
         {barre1=SDL_LoadBMP("1.bmp");
         	posbarre1.x=500;
         	posbarre1.y=20;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][0].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[2][2].cas)!=0)&&((Tab[0][0].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[2][2].cas)))
     {
       if(Tab[0][0].cas==1)
         {barre1=SDL_LoadBMP("3.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][0].cas==2)
         {barre1=SDL_LoadBMP("3.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else if (((Tab[0][2].cas)!=0)&&((Tab[1][1].cas)!=0)&&((Tab[2][0].cas)!=0)&&((Tab[0][2].cas)==(Tab[1][1].cas))&&((Tab[1][1].cas)==(Tab[2][0].cas)))
     {
        if(Tab[0][2].cas==1)
         {barre1=SDL_LoadBMP("4.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 1;
         }
         else if(Tab[0][2].cas==2)
         {barre1=SDL_LoadBMP("4.bmp");
         	posbarre1.x=0;
         	posbarre1.y=0;
         	SDL_BlitSurface(barre1,NULL,screen,&posbarre1);
         	SDL_Flip(screen);
         	SDL_Delay(500);
         	return 2;
         }

     }
     else
     	return 3;
		
	 }
     else 
		return 0;
	
    }
	else 
		return 0;
}