
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"vie.h"
#define WIDTH 1000
#define HEIGHT 560




void init_vie(vie *v,SDL_Surface *ecran) 
{
 (v->posvie.x)=0;
 (v->posvie.y)=0;
 (v->val)=5;
 (v->image[1])=IMG_Load("vie1.png") ;
 (v->image[2])=IMG_Load("vie2.png") ;
 (v->image[3])=IMG_Load("vie3.png") ;
 (v->image[4])=IMG_Load("vie4.png") ;
 (v->image[5])=IMG_Load("vie5.png") ;

}

int  displayvie(vie *v ,SDL_Surface *ecran,int x) 
{


SDL_BlitSurface(v->image[v->val],NULL,ecran,&(v->posvie));
 
  if (x==1)
{v->val--;}
if (v->val==0)
	return 1;
else 
	return 0;
}


void vie_freevie(vie *v ) 
{
SDL_FreeSurface(v->image[1]);
SDL_FreeSurface(v->image[2]);
SDL_FreeSurface(v->image[3]);
SDL_FreeSurface(v->image[4]);
SDL_FreeSurface(v->image[5]);
}
   



			
		
