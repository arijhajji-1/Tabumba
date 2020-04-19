#include "background.h"



void initialiser_backround (background *b)
{
b->x_relative=0;
b->y_relative=0;
b->background=NULL;
b->bg=NULL;
b->pos.x=0;
b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=10000;
b->camera.h=800;
b->background=IMG_Load("map.png");
b->bg=IMG_Load("masks.png");

}

void afficher_background (SDL_Surface *screen,background *b)
{
  SDL_BlitSurface(b->bg,NULL,screen,&b->pos);
SDL_BlitSurface(b->background,&b->camera,screen,NULL);


}

void scrolling_right (background *b,personnageP *p,SDL_Surface *screen)
{
	if (b->camera.x<10000-1010)
	{
		b->x_relative+=p->xvelocity;
		b->camera.x+=p->xvelocity;
    p->position.x+=p->xvelocity;

	}
}

void scrolling_left (background *b,personngeP *p,SDL_Surface *screen)
{
	if (b->camera.x>0)
	{
		b->x_relative-=p->xvelocity;
		b->camera.x-=p->xvelocity;
    p->position.x-=p->xvelocity;

	}
}
void free_memory (background *b )
{
 SDL_FreeSurface (b->background) ;
 SDL_FreeSurface (b->bg) ;


 SDL_Quit () ;

}
