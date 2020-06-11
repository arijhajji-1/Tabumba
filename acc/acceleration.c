

  #include <SDL/SDL.h>

 

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
} Sprite;

void InitSprite(Sprite* Sp)
{//position spawn
	Sp->x = 100.0f;
	Sp->y = 220.0f;
	Sp->status = STAT_SOL;
	Sp->vx = Sp->vy = 0.0f;
}

void Render(Sprite* Sp,SDL_Surface* screen)
{
	SDL_Rect R;
	R.x = (Sint16)Sp->x;
	R.y = (Sint16)Sp->y;
	R.w = 20;
	R.h = 40;
	SDL_FillRect(screen,&R,SDL_MapRGB(screen->format,0,255,0));
}


void Evolue(Sprite* Sp,Uint8* keys)
{
	float lateralspeed = 0.5f;//speed
	float airlateralspeedfacteur = 1.0f;//EFFETSPEEDFILHWÉ
	float maxhspeed = 15.0f;
	float adherance = 1.5f;
	if (Sp->status == STAT_AIR) // (*2)
		lateralspeed*= airlateralspeedfacteur;
	if (keys[SDLK_LEFT]) // (*1)
		Sp->vx-=lateralspeed;
	if (keys[SDLK_RIGHT])
		Sp->vx+=lateralspeed;
	if (Sp->status == STAT_SOL && !keys[SDLK_LEFT] && !keys[SDLK_RIGHT]) // (*3)
		Sp->vx/=adherance; 
	if (Sp->vx>maxhspeed) // (*4)
		Sp->vx = maxhspeed;
	if (Sp->vx<-maxhspeed)
		Sp->vx = -maxhspeed;

Sp->x +=Sp->vx;
	Sp->y +=Sp->vy;
}

int main(int argc,char** argv)
{
	SDL_Surface* screen;
	int numkeys;
	Uint8 * keys;
	Sprite S;
	Uint32 timer,elapsed;
	SDL_Init(SDL_INIT_VIDEO);
	screen=SDL_SetVideoMode(400,320,32,SDL_SWSURFACE|SDL_DOUBLEBUF);
	InitSprite(&S);
	do 
	{
		timer = SDL_GetTicks();
		SDL_FillRect(screen,NULL,0);
		SDL_PumpEvents();
		keys = SDL_GetKeyState(&numkeys);
		Evolue(&S,keys);
		Render(&S,screen);
		SDL_Flip(screen);
		elapsed = SDL_GetTicks() - timer;
		if (elapsed<20)
		SDL_Delay(20-elapsed);
	} while (!keys[SDLK_ESCAPE]);
	SDL_Quit();


	return 0;
}
