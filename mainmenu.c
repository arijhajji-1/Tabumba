#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL/SDL_ttf.h"
#include "menuf.h"



void main(int argc, char *argv[])
{



  
 SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

SDL_Surface *screen;
SDL_Event event;
int screenx=640;
int screeny=740;
int done=1;
int actm,r=0;
Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );
 Mix_AllocateChannels(2); 
 Mix_Music *music;
 music = Mix_LoadMUS("SOUND/music1.mp3");
    Mix_VolumeMusic(128/2);
    
 Mix_PlayMusic( music, -1);
if(!screen)
  {
      printf("Error 2: %s\n",SDL_GetError());

  }
  

  if(SDL_Init(SDL_INIT_VIDEO)!=0)
  {
      printf("Error: %s\n",SDL_GetError());

  }
TTF_Init();
screen = SDL_SetVideoMode(screenx,screeny,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 


int action;


while (done==1)
{	  
menu(screen);
}
SDL_Quit();
}

