
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"vie.h"
#define WIDTH 1000
#define HEIGHT 560



void main ( int argc, char* argv[] )
{
        SDL_Surface *ecran = NULL,*fond;
        SDL_Rect position;

        position.x=0;
        position.y=0; 
        SDL_Event event;
        int gameover = 1;
        int test,x,s;
	vie v;
        
        SDL_Init(SDL_INIT_VIDEO);
        ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
        SDL_WM_SetCaption("vie", NULL);
       fond = IMG_Load("backgroundsao.jpg");
        init_vie(&v,ecran);
        while(gameover)
        {
                      
                     x=0;              
         SDL_BlitSurface(fond, NULL, ecran, &position);
                s=displayvie(&v ,ecran,x) ; 
               SDL_Flip(ecran);
	
                while (SDL_PollEvent(&event))
                {
                        switch(event.type)
                        {
                        case SDL_QUIT:
                                gameover = 0;
                                break;
                        case SDL_KEYDOWN:

                                switch(event.key.keysym.sym)
                                {
                                        case SDLK_ESCAPE:
                                        gameover=0;
                                        break;
                                
                                case SDLK_RETURN:

					x=1;
                                        s=displayvie(&v ,ecran,x) ; 

                                        break;
                                }
                                break;
                        }
                        
                        
                }
        }
	vie_freevie(&v);
        if (gameover==0)
        SDL_Quit();
      

}
