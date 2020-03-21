#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "background.h"

SDL_Surface * Init_imagedefond( SDL_Surface *imagedefond ,SDL_Rect *positionFond ,  int x , int y) 
 {
	       imagedefond =  IMG_Load("map.png"); 

	      if  ( imagedefond ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     positionFond->x  =  x ; 
     positionFond->y  = y ;
     positionFond->h= imagedefond->h ;
     positionFond->w= imagedefond->w ;  
 }
     
     return (imagedefond) ; 
}
 void Show_imagedefond (SDL_Surface *imagedefond , SDL_Surface *screen , SDL_Rect positionFond ) 
  {

	 SDL_BlitSurface(imagedefond, NULL, screen, &positionFond);
}
void scrolling_map (SDL_Rect *positionFond,SDL_Rect *positionper,SDL_Surface *imageDeFond ,SDL_Surface *pers,SDL_Surface *screen)


{

SDL_Event event;
    SDL_EnableKeyRepeat(10, 10);
    int continuer = 1;

while (continuer)
{

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)

        {

            case SDLK_RIGHT: // Flèche droite
            	
                
        
                       positionFond->x ++;
                       SDL_BlitSurface(imageDeFond,positionFond, screen, NULL);
                   
                 
            
                
                SDL_Flip(screen);

                break;

            case SDLK_LEFT: // Flèche gauche
            	
        
            positionFond->x --;
        
    
         
                SDL_BlitSurface(imageDeFond,positionFond, screen, NULL);
				    
                
               SDL_Flip(screen);

                break;

            case SDLK_UP: 
            	
        
                       positionFond->y --;
                       SDL_BlitSurface(imageDeFond,positionFond, screen, NULL);
                   
                 
            
                
                SDL_Flip(screen);

                break;
               case SDLK_DOWN: 
            	
        
                       positionFond->y ++ ;
                       SDL_BlitSurface(imageDeFond,positionFond, screen, NULL);
                   
                 
            
                
                SDL_Flip(screen);

                break;

        }

        break;    
        }


                SDL_Flip(screen);
 }               SDL_Delay(10);




}
